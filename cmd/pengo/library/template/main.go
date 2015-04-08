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
package template

var TemplateMain string = `
// AUTO GENERATED
// DO NOT MODIFY
package main

import (
 	"net/http"
    "unicode"
    "strings"
    "github.com/julienschmidt/httprouter"
	. "github.com/penlook/pengo"
    . "github.com/penlook/pengo/module"
    . "github.com/penlook/pengo/cmd/pengo/app/generate/controller"
)

func Base(controllerName string, actionName string, response http.ResponseWriter, request *http.Request, params httprouter.Params) Controller {
    if actionName == "*" {
        actionName = params.ByName("action")
        if actionName == "" {
            actionName = "index"
        }
    }
    array := []rune(strings.ToLower(actionName))
    array[0] = unicode.ToUpper(array[0])
    actionName = string(array)
    return Controller {
        Name: controllerName,
        ActionName: actionName,
        Config: Config {
            ViewRoot: "./view",
        },
        Http: Http {
            Request : request,
            Response : response,
            Router: params,
        },
    }
}

func main() {
    model := Model{}
    model.Initialize()

    //{{ model }}
    router := httprouter.New()
    {{ router }}
    http.ListenAndServe(":80", router)
}
`
