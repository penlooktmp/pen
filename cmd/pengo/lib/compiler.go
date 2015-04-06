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
	targetDirectory, _ := filepath.Abs(compiler.Directory + "/controller")
	//destDirectory, _   := filepath.Abs(compiler.Directory + "/generate")
	//struct_alias, _      := regexp.Compile("@[A-Z]")
	template_variable := regexp.MustCompile("@[a-z]")
	filepath.Walk(targetDirectory, func(path string, f os.FileInfo, err error) error {
    	file, err := os.Open(path)
		if err != nil {
	    	log.Fatal(err)
		}
		defer file.Close()
		scanner := bufio.NewScanner(file)
		content := ""
		controllerName := ""
		for scanner.Scan() {
			line := scanner.Text()

			// Controller declaration
	    	if strings.HasPrefix(line, "@controller") {
	    		array := strings.Split(line, " ")
	    		controllerName = array[1]
	    		content = content + "type " + controllerName + " struct { Controller } \n"
	    	} else {
	    		if strings.HasPrefix(line, "@") {
	    			if controllerName == "" {
	    				fmt.Println("Controller must be declared in", path)
	    				return nil
	    			}
	    			content = content + "// " + line + "\n"
	    		} else {
	    			if strings.HasPrefix(line, "func") {
	    				content = content + "func (" + strings.ToLower(controllerName) + " " + controllerName + ")" + line[4:] + "\n"
	    			} else {
	    				//fmt.Println(struct_alias.FindStringIndex(line))
	    				loc := template_variable.FindStringIndex(line)
	    				if (len(loc) > 0) {
	    					array := strings.Split(line[loc[0]:], "=")
	    					if len(array) == 2 {
	    						content = content + "\t" + strings.ToLower(controllerName) + ".View(Data{\"" + strings.TrimSpace(array[0][1:]) + "\":" + array[1] + "},) \n"
	    					}
	    				} else {
	    					content = content + line + "\n"
	    				}
	    			}
	    		}
	    	}
		}
		fmt.Println(content)
    	return nil
	})
}

func (compiler Compiler) ParseModel() {
}
