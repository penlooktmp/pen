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
package library

import (
 	"path/filepath"
 	"os"
 	"log"
 	"bufio"
 	"fmt"
 	"strings"
 	"regexp"
)

type Compiler struct {
	Directory string
	File string
	Line string
	Content string
	Data Arguments
}

// Header file
func (compiler Compiler) Header() string {
	header := "// AUTO GENERATED\n"
	header = header + "// DO NOT MODIFY\n"
	header = header + "package controller\n"
	header = header + "import (\n"
	header = header + "\t. \"github.com/penlook/pengo\"\n"
	header = header + "\t. \"github.com/penlook/pengo/cmd/pengo/app/generate/extend\"\n"
	header = header + ")\n"
	return header
}

// Start with "@" (out of function)
func (compile *Compiler) Annotation() {

	line := compile.Line

	if strings.HasPrefix(line, ANNOTATION_CONTROLLER) {
		array := strings.Split(line, " ")
		header := compile.Header()
		controllerName := array[1]
		compile.Content += header  + "type " + controllerName + " struct { Controller }\n"
		compile.Content += "func (" + strings.ToLower(controllerName) + " " + controllerName + ") Start() {\n\tPengo()\n\t"+ strings.ToLower(controllerName) +".Pick(\"Start\")\n}\n"
		compile.Data["controllerName"] = controllerName
	}

	if compile.Data["controllerName"] == "" {
		fmt.Println("Controller must be declared in", compile.File)
		panic("Controller does not defined !")
	}

	compile.Content += "// " + line + "\n"
}

// Start with "func"
func (compile *Compiler) Function() {

	line := compile.Line
	first := strings.Index(line, "(")
	last  := strings.Index(line, ")")

	// Function syntax
	if first < 0 || last < 0 {
		fmt.Println("Missing '(' or ')' in ", line)
		panic("Syntax error")
	}

	argumentString := strings.TrimSpace(line[4: first])

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

// Start with @ (in function)
func (compile *Compiler) Method(loc []int) {
	line := compile.Line
	controllerName := compile.Data["controllerName"]
	compile.Content += "\t" + strings.ToLower(controllerName) + "." + line[loc[0] + 1:] + "\n"
}

// Template variable
// Start with $ (in function)
func (compile *Compiler) TemplateVariable(loc []int) {
	line := compile.Line
	array := strings.Split(line[loc[0]:], "=")
	if len(array) == 2 {
		compile.Content += "\t" + strings.ToLower(compile.Data["controllerName"]) + ".View(Data{\"" + strings.TrimSpace(array[0][1:]) + "\":" + array[1] + ",})\n"
	}
}

// Start with # (in function)
func (compile Compiler) Model(loc []int) {
	// TODO
}

// Check pattern should be compiled
func (compile Compiler) FindPattern(pattern string) []int {
	regex := regexp.MustCompile(pattern)
	return regex.FindStringIndex(compile.Line)
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
		compile.File = path
		compile.Content = ""
		compile.Data = Arguments {}

		scanner := bufio.NewScanner(file)

		// Compile file content
		for scanner.Scan() {

			// Update context
			compile.Line = scanner.Text()

			// Do not compile empty line
			if len(strings.TrimSpace(compile.Line)) == 0 {
				continue
			}

			if strings.HasPrefix(compile.Line, "@") {
				compile.Annotation()
				continue
			}

			if strings.HasPrefix(compile.Line, "func") {
				compile.Function()
				continue
			}

			if loc := compile.FindPattern("\\$[a-z]"); len(loc) > 0 {
				compile.TemplateVariable(loc)
				continue
			}

			if loc := compile.FindPattern("\\@[A-Z]"); len(loc) > 0 {
				compile.Method(loc)
				continue
			}

			if loc := compile.FindPattern("\\#[A-Z]"); len(loc) > 0 {
				compile.Model(loc)
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

func (compiler Compiler) ParseModel() {
}