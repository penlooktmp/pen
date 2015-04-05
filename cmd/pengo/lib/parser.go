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
 	"os"
 	"log"
 	"strings"
 	"bufio"
 	"path/filepath"
 	"regexp"
)

type Parser struct {
}

func (parser Parser) Controller(rootPath string) interface {} {
	rules := [] string {
		"// @router",
		"// @method",
		"// @error",
		"// @less",
		"// @dart",
		"func ",
	}
	rules_count := len(rules)
	linestack := [] string {}
	linestack_count := 0

   	filepath.Walk(rootPath, func(path string, f os.FileInfo, err error) error {
        file, err := os.Open(path)
		if err != nil {
		    log.Fatal(err)
		}
		defer file.Close()
		scanner := bufio.NewScanner(file)
		for scanner.Scan() {
			line := scanner.Text()
		    for i:=0; i<rules_count; i++ {
		    	line = strings.TrimSpace(line)
		    	if len(line) == 0 {
		    		continue
		    	}
		    	if strings.HasPrefix(line, rules[i]) {
		    		linestack = append(linestack, line)
		    		linestack_count += 1
		    	}
		    }
		}
        return nil
    })

    controllers := Controller {}
    annotation := [] Annotation {}
    funcPattern, _ := regexp.Compile("[(){]+")

   	for i:=0; i<linestack_count; i++ {
   		// Is Annotation ?
   		if strings.HasPrefix(linestack[i], "// @") {
   			array := strings.Split(linestack[i], " ")
   			if len(array) < 3 {
   				panic("Invalid argument for annotation !")
   			}
   			annotation = append(annotation, Annotation {
   				array[1] : array[2],
   			})
   		} else {
   			linestack[i] = funcPattern.ReplaceAllString(linestack[i], "")
   			array := strings.Split(linestack[i], " ")
   			controllers[array[2]] = append(controllers[array[2]], Action {
   				array[3] : annotation,
   			})
   		}
   	}

   	return controllers
}

func (parser Parser) CGoInterface(rootPath string) {
}