#!/usr/bin/python
# Open source template builder
# https://github.com/ismaproco/pytemplate

import os, sys, string

class PathTree:
    identifier = 0
    level = 0
    name = ""
    creation_type = ""
    path = ""
    father = None

#Main class to build the template
class TemplateBuilder:

    """docstring for PyTemplate"""
    def __init__(self, text, destination ):

        self.text = text

        # Variable initilization for the file parsing
        word_dictionary = []
        word = ""
        path = []

        #flag to know when to break the word
        break_word = False

        #Tokens to split the file
        open_tokens = ['[','{','(']
        close_tokens = [']','}',')']
        general_tokens = [',','/','\\','\n','\t']

        #Special tokens (all special tokens start with @)
        action_token = '@';

        # Token to identify download
        # if "@" token is found, a key value definition will be expected
        # in the key:value:filename structure ;
        # ex: @jquery:http://code.jquery.com/jquery-2.1.0.min.js:jquery.min.js
        # just one definition per line
        #
        # logic:
        # A hash will be created with the key, value, name
        # and will be added to the download_files Queu
        #
        # if the key is found in any file definition
        # the downloaded file will be located in that place.
        #

        #states
        #s -> none, folder, file, end_token
        type_state = []

        reading_token = False

        identifier = 0
        temp_state_identifier = ""

        pop_folder = False

        variables = {}
        reading_variable = False
        variable_name = ""
        break_text = 0
        break_variable = False

        # loop through the text
        for c in self.text:

            # The chatacter is a Token?
            if not reading_variable:
                if  general_tokens.count(c) > 0 or open_tokens.count(c) > 0 or close_tokens.count(c) > 0:

                    reading_token = True
                    break_word = True
                else:
                    reading_token = False

            # is a word to add?
            if not reading_variable:
                if break_word:
                    #build the path tree for the word
                    path_tree = self.add_word_pathtree( word, type_state, path, identifier )

                    #is a valid path_tree?
                    if path_tree:
                        # append the object to the dictionary of words
                        word_dictionary.append(path_tree);
                    #clear the word
                    word = ""
                    #increment the identifier
                    identifier += 1
            else:
                if break_variable:
                    variable_name = word.strip()
                elif break_text == 2:
                    variables[variable_name] = word.strip()

            # Check the open tokens
            if c == "[":
                type_state.append("folder")
            elif c == "{":
                type_state.append("file")
            elif c == "@":
                type_state.append("variable")


            #if last state is "variable"
                #read the chars until an = is find
                # if an equals is found start reading until a double quotes is found
                # start reading the string
                # end reading the string until the next double quote

            #get the last element of the list
            if type_state[-len(type_state)] == 'variable':
                reading_variable = True
            else:
                # Check the closing tokens
                if c == "]":
                    type_state.pop()
                    path.pop()
                elif c == "}":
                    type_state.pop()

            #is not reading variable
            if not reading_variable:
                # is not a breaking token, add char to the string
                if not reading_token and type_state[-1] != "none":
                    word += c
            else:
                if not c == "=" and not c == "\"":
                    word += c
                elif c == "=":
                    break_variable = True
                elif c == "\"":
                    break_variable = False
                    break_text +=1


            #clear the current status
            reading_token = False
            break_word = False

        # loop all the words
        for f in word_dictionary:
            #is a folder?
            if f.creation_type == "folder":
                #custom destionation specified?
                if destination == "": # no
                    final_path = os.path.dirname(os.path.abspath(__file__)) +"/"+ f.path
                else: # yes
                    final_path = destination +"/"+ f.path

                #path exists?
                if not os.path.exists(final_path) : os.makedirs(final_path)

            #is a file?
            if f.creation_type == "file":
                if destination == "": # no
                    open(f.path, "w+")
                else:
                    open(destination + "/" + f.path,"w+")

    """ Return a string of the templating object """
    def __str__(self):
        return str(self.identifier) + " " + self.creation_type + " " + self.name + " " + self.path

    """ Add word to the path tree """

    def add_word_pathtree(self, word, type_state, path, identifier):
        # is not empty?
        if word != "":

            f = PathTree()

            # set the values of the PathTree object
            f.identifier = identifier
            f.name = word
            f.creation_type = type_state[-1]
            f.Father = None

            # is a folder?
            if type_state[-1] == "folder":
                if(len(type_state) == len(path)):
                    path.pop()
                #add the current word to the path array
                path.append(word)

            #build the path for the Path Tree file
            f.path = self.build_path(path)

            # is a file
            if type_state[-1] == "file":
                #add the word to the path string
                f.path += word

            return f

    """ Return a string of the path array """
    def build_path(self,path):
        s_path = ""
        for i in path:
            s_path += i + "/"
        return s_path