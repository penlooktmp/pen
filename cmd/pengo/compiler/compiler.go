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
 *     Loi Nguyen       <loint@penlook.com>
 */

package compiler

import (
 	"path/filepath"
 	"os"
 	"log"
 	"bufio"
 	"fmt"
 	"strings"
 	"unicode"
 	"regexp"
 	"github.com/oleiade/lane"
)

type Compiler struct {
	Directory string
	File string
	Line string
	Content string
	Enable bool
	Stack *lane.Stack
	Data Pair
}

func (compiler Compiler) HeaderC() string {
	header := " "
	return header
}
// Header file
func (compiler Compiler) Header() string {

	header := `
	// AUTO GENERATED
	// DO NOT MODIFY
	package controller
	import (
		. "github.com/penlook/pengo"
		. "github.com/penlook/pengo/cmd/pengo/app/generate/extend"
	)
	`
	return header
}

func (compile *Compiler) AddHeader() {

	header := compile.Header()
	regex  := regexp.MustCompile(PATTERN_FILENAME_CONTROLLER)
	loc    := regex.FindStringIndex(compile.File)

	// Find the last splash
	if len(loc) > 0 {
		// Ignore .go extenstion and parent directory
		controllerName := compile.File[loc[0]:loc[1] - 3]

		// Multiple part of name
		// app_example_a
		array := strings.Split(controllerName, "_")
		controllerName = ""

		for i:=0; i<len(array); i++ {
			array_char := []rune(strings.ToLower(array[i]))
    		array_char[0] = unicode.ToUpper(array_char[0])
			controllerName += string(array_char)
		}

		compile.Content += header  + "type " + controllerName + " struct { Controller }\n"
		compile.Content += "func (" + strings.ToLower(controllerName) + " " + controllerName + ") Start() {\n\tPengo()\n\t"+ strings.ToLower(controllerName) +".Pick(\"Start\")\n}\n"
		compile.Data["controllerName"] = controllerName
		return
	}

	fmt.Println("Your file name is not match with standard at " + compile.File)
	panic("Filename error !")
}

// Start with "@" (out of function)
func (compile *Compiler) Annotation(loc []int) {
	compile.Content += "// " + compile.Line + "\n"
}

// Start with "func"
func (compile *Compiler) Function(loc []int) {

	line := compile.Line

	// With argument
	// Example(string a, string b) {
	// }
	first := strings.Index(line, "(")
	last  := strings.Index(line, ")")

	// Function syntax
	if first < 0 || last < 0 {
		fmt.Println("Syntax error ", "Missing { in " + compile.Line)
	}

	argumentString := strings.TrimSpace(line[0: first])

	if last - first > 1 {
		param_array := strings.Split(line[first + 1 : last], ",")
		args := ""
		for i:=0; i<len(param_array); i++ {
			args += strings.TrimSpace(param_array[i]) + ", "
		}
		argumentString += "(" + args[0:len(args) - 2] + ") {"
	}

	// Fixed syntax with {
	if ! (string(argumentString[len(argumentString) - 1]) == "{") {
		argumentString += "() {"
	}

	controllerName := compile.Data["controllerName"]
	compile.Content += "func (" + strings.ToLower(controllerName) + " " + controllerName + ") " + argumentString + "\n"

}

// Global variable
// Start with @@ (in function)
func (compile *Compiler) CrossVariable(loc []int) {
	/*
	line := compile.Line
	array := strings.Split(line[loc[0]:], "=")
	if len(array) == 2 {
		compile.Content += "\t" + strings.ToLower(compile.Data["controllerName"]) + ".View(Data{\"" + strings.TrimSpace(array[0][1:]) + "\":" + array[1] + ",})\n"
	}
	*/
}

// Start as normal function
// Pick("Run action")
func (compile *Compiler) GoMethod(loc []int) {
	line := compile.Line
	controllerName := compile.Data["controllerName"]
	compile.Content += "\t" + strings.ToLower(controllerName) + "." + line[loc[0] + 1:] + "\n"
}

// Start with ~
// ~SampleC()
func (compile *Compiler) CFunction(loc []int) {
	line := compile.Line
	compile.Content += "\t" + line[loc[0] + 1:] + "\n"
}

// Template variable
// Start with $ (in function)
// $title = "Hello"
func (compile *Compiler) TemplateVariable(loc []int) {
	line := compile.Line
	array := strings.Split(line[1:], "=")
	if len(array) == 2 {
		compile.Content += "\t" + strings.ToLower(compile.Data["controllerName"]) + ".View(Data{\"" + strings.TrimSpace(array[0][1:]) + "\":" + array[1] + ",})\n"
	}
}

// Syntax for table and collection
// Name unique
// Start with # (in function)
// #User
// #User {
// 	   Name: "ABC"
// }
func (compile *Compiler) TableCollection(loc []int) {
	line  := compile.Line
	match := line[loc[0]:loc[1]]
	if compile.Stack.Size() == 0 {
		controllerName := compile.Data["controllerName"]

		// #Example {
		compile.Content += line[0:loc[0]] + strings.ToLower(controllerName) + ".Table(\"User\", Schema {"
		line = strings.TrimSpace(line)
		regex := regexp.MustCompile("\\{")
		loc_bracket := regex.FindStringIndex(match)

		// #Example or #Example {}
		if len(loc_bracket) == 0 || strings.HasSuffix(line, "}") {
			compile.Content += "})\n"
			return
		}

		// Missing }
		compile.Content += "\n"
		compile.Stack.Push("Model.Table")
	}
}

func (compile *Compiler) KeyValue(loc []int) {
	line  := compile.Line
	match := line[loc[0]:loc[1]]
	fmt.Println(match)
}

// Start with # (in function)
// #ListAll()
func (compile *Compiler) ModelController(loc []int) {
	line := compile.Line
	if compile.Stack.Size() == 0 {
		controllerName := compile.Data["controllerName"]
		// Hard-code
		compile.Content += line[0:loc[0]] + strings.ToLower(controllerName) + ".Model.Controller." + controllerName +"ListAll()\n"
	}
}

 // Close incomplete bracket for corresponding case
func (compile *Compiler) Complete() {
	typeName := compile.Stack.Pop()
	switch typeName.(string) {
		case "Model.Table":
			compile.Content += compile.Line + ")\n"
		default:
			compile.Content += compile.Line + "\n"
	}
}

// Check pattern should be compiled
func (compile Compiler) FindPattern(pattern string) []int {
	regex := regexp.MustCompile(pattern)
	return regex.FindStringIndex(compile.Line)
}

// Comment Block - Multiple lines
// Return false to ignore currently line
func (compile *Compiler) CommentBlock() bool {

	line := strings.TrimSpace(compile.Line)
	if strings.HasPrefix(line, "//") {
		return true
	}

	if compile.Enable {
		regex := regexp.MustCompile("\\/\\*")
		loc := regex.FindStringIndex(compile.Line)
		if len(loc) > 0 {
			compile.Enable = false
			return true
		}
		return false
	} else {
		regex := regexp.MustCompile(".+\\*\\/")
		loc := regex.FindStringIndex(compile.Line)
		if len(loc) > 0 {
			compile.Enable = true
			return true
		}
		return true
	}
}

// Compile controller
func (compile *Compiler) ParseController() {

	// Target controller directory
	targetDirectory, _ := filepath.Abs(compile.Directory + "/controller")

	// Destination compiled controller
	destDirectory, _   := filepath.Abs(compile.Directory + "/generate/controller")

	// Loop in target controller
	filepath.Walk(targetDirectory, func(path string, f os.FileInfo, err error) error {

    	file, err := os.Open(path)

		if err != nil {
	    	log.Fatal(err)
		}

		defer file.Close()

		// Update context
		compile.File    = path
		compile.Content = ""
		compile.Data    = Pair {}
		compile.Enable  = true
		compile.Stack   = lane.NewStack()

		// Other format and test file need to be ignored
		if ! strings.HasSuffix(compile.File, ".go") || strings.HasSuffix(compile.File, "_test.go") {
			return nil
		}

		scanner := bufio.NewScanner(file)

		// Header Initialize
		compile.AddHeader()

		// Compile file content
		for scanner.Scan() {

			// Update context
			compile.Line = scanner.Text()

			// Do not compile empty line
			if len(strings.TrimSpace(compile.Line)) == 0 {
				continue
			}

			if compile.CommentBlock() {
				continue
			}

			if loc := compile.FindPattern(PATTERN_ANNOTATION); len(loc) > 0 {
				compile.Annotation(loc)
				continue
			}

			if loc := compile.FindPattern(PATTERN_FUNCTION_DEFINE); len(loc) > 0 {
				compile.Function(loc)
				continue
			}

			if loc := compile.FindPattern(PATTERN_VARIABLE_TEMPLATE); len(loc) > 0 {
				compile.TemplateVariable(loc)
				continue
			}

			if loc := compile.FindPattern(PATTERN_VARIABLE_CONTEXT); len(loc) > 0 {
				compile.CrossVariable(loc)
				continue
			}

			if loc := compile.FindPattern(PATTERN_GO_METHOD); len(loc) > 0 {
				compile.GoMethod(loc)
				continue
			}

			if loc := compile.FindPattern(PATTERN_C_FUNCTION); len(loc) > 0 {
				compile.CFunction(loc)
				continue
			}

			if loc := compile.FindPattern(PATTERN_MODEL_ENTITY); len(loc) > 0 {
				compile.TableCollection(loc)
				continue
			}

			if loc := compile.FindPattern(PATTERN_MODEL_FUNCTION); len(loc) > 0 {
				compile.ModelController(loc)
				continue
			}

			if line := strings.TrimSpace(compile.Line); line == "}" && compile.Stack.Size() > 0 {
				compile.Complete()
				continue
			}

			compile.Content += compile.Line + "\n"
		}

		// Write content to file
		if len(compile.Data["controllerName"]) > 0 {
			generator := Generator {}
    		generator.Controller(compile.Content, destDirectory, compile.Data["controllerName"])
    	}

    	return nil
	})
}


// Compile controller
func (compile *Compiler) ParseModel() {

	/*
	// Target controller directory
	targetDirectory, _ := filepath.Abs(compile.Directory + "/model")

	// Destination compiled controller
	destDirectory, _   := filepath.Abs(compile.Directory + "/generate/model")

	// Loop in target controller
	filepath.Walk(targetDirectory, func(path string, f os.FileInfo, err error) error {

    	file, err := os.Open(path)

		if err != nil {
	    	log.Fatal(err)
		}

		defer file.Close()

		// Update context
		compile.File    = path
		compile.Content = ""
		compile.Data    = Pair {}
		compile.Enable  = true
		compile.Stack   = lane.NewStack()

		scanner := bufio.NewScanner(file)

		// Compile file content
		for scanner.Scan() {

			// Update context
			compile.Line = scanner.Text()

			// Do not compile empty line
			if len(strings.TrimSpace(compile.Line)) == 0 {
				continue
			}

			if compile.CommentBlock() {
				continue
			}

			if strings.HasPrefix(compile.Line, "@") {
				compile.Annotation()
				continue
			}

			compile.Content += compile.Line + "\n"
		}

		// Write content to file
		if len(compile.Data["ModelName"]) > 0 {
			generator := Generator {}
			fmt.Println(compile.Content)
    		generator.Controller(compile.Content, destDirectory, compile.Data["ModelName"])
    	}

    	return nil
	})*/
}