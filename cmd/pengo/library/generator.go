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
  	"os"
  	"strings"
  	"encoding/json"
  	"path/filepath"
  	"fmt"
)

type Data map[string] interface{}

type Generator struct {}

func (gen Generator) Clean(path string) {
	err := os.Remove(path)
	if err != nil {
		fmt.Println(err)
	  	return
	}
}

func (gen Generator) Write(template string, path string) {
	if _, err := os.Stat(path); os.IsNotExist(err) {
    	os.Create(path)
	}
	file, err := os.OpenFile(path, os.O_APPEND, 0666)
	defer file.Close()
	if err != nil {
		panic(err)
	}
	file.WriteString(template)
}

func (gen Generator) Replace(template string, variable string, content string) string {
	variable = "{{ " + variable + " }}"
	template = strings.Replace(template, variable, content, -1)
	return template
}

func (gen Generator) Schema() {
}

func (gen Generator) ExtendC(template string, path string) {
	gen.Clean(path)
	gen.Write(template, path)
}

func (gen Generator) Extend(template string, path string, data Data) {
	gen.Clean(path)
	gen.Write(template, path)
}

func (gen Generator) Controller(template string, controllerDirectory string, controllerName string) {
	path, _ := filepath.Abs(controllerDirectory + "/" + strings.ToLower(controllerName) + ".go")
	gen.Clean(path)
	gen.Write(template, path)
}

func (gen Generator) Main(template string, path string, data Data) {
	gen.Clean(path)

	type Router struct {
		Route string
		Method string
		Controller string
		Action string
		Arguments Arguments
	}

	routers := [] Router {}

	for controllerName, actionIndex := range data["controller"].(Controller) {
		for _, action := range actionIndex {
			if action.Name == "Start" || action.Name == "Before" || action.Name == "After" {
				continue
			}
			routers = append(routers, Router {
				Controller: controllerName,
				Action: action.Name,
				Route : action.Annotation["@Route"],
				Method: action.Annotation["@Method"],
				Arguments: action.Arguments,
			})
		}
	}

	router_code := ""
	for _, router := range routers {
		if router.Method == "" {
			router.Method = "GET"
		}
		argumentString, err := json.Marshal(router.Arguments)
		if err != nil {
			fmt.Println("Syntax error ", router.Arguments)
		}
		router_code += "router." + router.Method + "(\"" + router.Route + "\""+ `, func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
    		c := ` + router.Controller + ` {
        		Base("` + router.Controller + `", "` + router.Action + `", response, request, params),
    		}
    		c.Initialize()
    		c.Start()
    		c.InitAction()
    		c.BeforeAction(c)
    		c.Action(c, ` + "`" + string(argumentString) + "`" + `)
    		c.AfterAction(c)
    		c.Flow.Graph()
		})` + "\n\t"
	}
	template = gen.Replace(template, "router", router_code)
	gen.Write(template, path)
}