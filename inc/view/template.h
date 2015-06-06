/**
 * Pengo Project
 *
 * Copyright (c) 2015 Penlook Development Team
 *
 * --------------------------------------------------------------------
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * Author:
 *     Tomas Andrle (https://github.com/catnapgames/NLTemplate)
 *     Loi Nguyen       <loint@penlook.com>
 */

#ifndef __Template_H__
#define __Template_H__


#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <memory>


namespace View {

namespace Template {

namespace Private {
    

struct Token {
    int type;
    std::string value;
};


class Tokenizer {
public:
    Tokenizer( const std::string & text );
    Token next();
    
private:
    const char *text_ptr;
    long len;
    long pos;
    Token peek;
    bool peeking;
};


class Dictionary {
public:
    const std::string find( const std::string & name ) const;
    void set( const std::string & name, const std::string & value );

protected:
    std::vector<std::pair<std::string, std::string> > properties;
};


class Fragment {
public:
    virtual void render( std::ostream & output, const Dictionary & dictionary ) const = 0;
    virtual ~Fragment();
    virtual Fragment *copy() const = 0;
    virtual bool isBlockNamed( const std::string & name ) const;
};


class Text : public Fragment {
public:
    Text( const std::string & text );
    void render( std::ostream & output, const Dictionary & dictionary ) const;
    Fragment *copy() const;
    
private:
    const std::string text;
};


class Property : public Fragment {
public:
    Property( const std::string & name );
    void render( std::ostream & output, const Dictionary & dictionary ) const;
    Fragment *copy() const;
    
private:
    const std::string name;
};

    
}; // namespace Private

    
    
class Block;

//using namespace Private;

    
class Node : public Private::Fragment, public Private::Dictionary {
public:
    ~Node();
    Fragment *copy() const;
    void render( std::ostream & output, const Private::Dictionary & dictionary ) const;
    Block & block( const std::string & name ) const;
    
protected:
    std::vector<Fragment*> fragments;
    
    friend class Template;
};


class Block : public Node {
public:
    Block( const std::string & name );
    Fragment *copy() const;
    ~Block();
    bool isBlockNamed( const std::string & name ) const;
    void enable();
    void disable();
    void repeat( size_t n );
    Node & operator[]( size_t index );
    void render( std::ostream & output, const Dictionary & dictionary ) const;
    
protected:
    const std::string name;
    bool enabled;
    bool resized;
    std::vector<Node*> nodes;
};


class Loader {
public:
    struct Result {
        bool valid;
        std::string data;
        std::string error;
    };
    
    virtual ~Loader();
    virtual Result load( const std::string & name ) = 0;
};


class LoaderFile : public Loader {
public:
    Result load( const std::string & name );
};

    
class LoaderMemory : public Loader {
private:
    std::vector<std::pair<std::string, std::string> > files;
public:
    void add( const std::string & name, const std::string & body );
    Result load( const std::string & name );
};



class Template : public Block {
public:
    Template( Loader & loader );
    void clear();
    void load( const std::string & name );
    void render( std::ostream & output ) const;
    
private:
    Loader & loader;

    void load_recursive( const std::string & name, std::vector<Private::Tokenizer> & files, std::vector<Node*> & nodes );
};



} // namespace Template
    
} // namespace NL

#endif