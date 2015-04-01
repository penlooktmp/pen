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
package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	. "github.com/penlook/pengo"
    . "github.com/penlook/pengo/module"
    "github.com/penlook/pengo/app/controller"
)

func Handle(controller_name string, action_name string) func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {

        defer Runtime(Now(), "pengo")

    	action := controller.App {
            Controller {
                Name : "App",
                ActionName: "Index",
                Http: Http {
                    Request : request,
                    Response : response,
                },
                Router: Router {
                    Method: "GET",
                    Controller : controller_name,
                    Action : action_name,
                },
            },
	  	}

        // Life cycle

        action.Initialize()
        action.InitAction()
        action.BeforeAction()
        action.Index()
        action.AfterAction()
        action.WaitResponse()

	}
}

func main() {

    /*System(`
        pwd
        echo "HELLO WORLD"
    `)*/

    router := httprouter.New()
    router.GET("/index", Handle("App", "Index"))
    http.ListenAndServe(":80", router)
}