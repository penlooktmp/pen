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
package lib

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
}

func (compiler Compiler) ParseController() {
	// Target controller directory
	targetDirectory, _ := filepath.Abs(compiler.Directory + "/controller")

	// Destination compiled controller
	destDirectory, _   := filepath.Abs(compiler.Directory + "/generate/controller")

	// Struct alias pattern
	struct_alias, _      := regexp.Compile("@[A-Z]")

	// Template variable pattern
	template_variable := regexp.MustCompile("\\$[a-z]")

	// Loop in target controller
	filepath.Walk(targetDirectory, func(path string, f os.FileInfo, err error) error {
    	file, err := os.Open(path)
		if err != nil {
	    	log.Fatal(err)
		}
		defer file.Close()
		scanner := bufio.NewScanner(file)

		// Header declaration
		header  := "// AUTO GENERATED\n"
		header = header + "// DO NOT MODIFY\n"
		header = header + "package controller\n"
		header = header + "import (\n"
		header = header + "\t. \"github.com/penlook/pengo\"\n"
		header = header + "\t. \"github.com/penlook/pengo/cmd/pengo/app/generate/extend\"\n"
		header = header + ")\n"
		content := ""

		controllerName := ""
		for scanner.Scan() {
			line := scanner.Text()

			// Controller declaration
	    	if strings.HasPrefix(line, "@Controller") {
	    		array := strings.Split(line, " ")
	    		controllerName = array[1]
	    		content = content + header + "type " + controllerName + " struct { Controller }\n"
	    		content = content + "func (" + strings.ToLower(controllerName) + " " + controllerName + ") Start() {\n\tPengo()\n\t"+ strings.ToLower(controllerName) +".Pick(\"Start\")\n}\n"
	    		continue
	    	}

	    	// Annotation
    		if strings.HasPrefix(line, "@") {
    			if controllerName == "" {
    				fmt.Println("Controller must be declared in", path)
    				return nil
    			}
    			content = content + "// " + line + "\n"
    			continue
    		}

    		// Function full pattern
			if strings.HasPrefix(line, "func") {
				first := strings.Index(line, "(")
				last  := strings.Index(line, ")")

				if first < 0 || last < 0 {
					fmt.Println("Syntax error ", line)
					return nil
				}

				funcFull := strings.TrimSpace(line[4: first])

				if last - first > 1 {
					param_array := strings.Split(line[first + 1 : last], ",")
					args := ""
					for i:=0; i<len(param_array); i++ {
						args += strings.TrimSpace(param_array[i]) + ", "
					}
					funcFull += "(" + args[0:len(args) - 2] + ") {"
				}

				if string(funcFull[len(funcFull) - 1]) == "{" {
				} else {
					funcFull += "() {"
				}

				content = content + "func (" + strings.ToLower(controllerName) + " " + controllerName + ") " + funcFull + "\n"
				continue
			}

			// Template variable
			loc := template_variable.FindStringIndex(line)
			if len(loc) > 0 {
				array := strings.Split(line[loc[0]:], "=")
				if len(array) == 2 {
					content = content + "\t" + strings.ToLower(controllerName) + ".View(Data{\"" + strings.TrimSpace(array[0][1:]) + "\":" + array[1] + ",})\n"
					continue
				}
			}

			// Struct method or field name
			loc = struct_alias.FindStringIndex(line)
			if len(loc) > 0 {
				content = content + "\t" + strings.ToLower(controllerName) + "." + line[loc[0] + 1:] + "\n"
				continue
			}

			content = content + line + "\n"
		}

		if len(controllerName) > 1 {
			generator := Generator {}
    		generator.Controller(content, destDirectory, controllerName)
    	}

    	return nil
	})
}

func (compiler Compiler) ParseModel() {
}