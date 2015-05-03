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

package server

import (
 	"net/http"
 	"fmt"
 	"strconv"
    "time"
 	"io/ioutil"
 	"os"
)

type Server struct {
	Name string
	Port int
    Callback func()
    Unlocked chan bool
}

func (server Server) Handler() func(writer http.ResponseWriter, request *http.Request) {
    return func(writer http.ResponseWriter, request *http.Request) {

        // Do not serve favicon request
        if request.URL.Path == "/favicon.ico" {
            return
        }

        // Waiting for previous compilation
        select {
            case <- server.Unlocked:
        }

        server.Callback()

        time.Sleep(time.Second * 2)

        debugPort := 8080
        url := "http://" + request.Host + ":" + strconv.Itoa(debugPort) + request.RequestURI

        response, err := http.Get(url)

        if err != nil {
            fmt.Printf("%s", err)
            os.Exit(1)
        } else {
            defer response.Body.Close()
            contents, err := ioutil.ReadAll(response.Body)
            if err != nil {
                fmt.Printf("%s", err)
                os.Exit(1)
            }
            fmt.Fprintf(writer, string(contents[:]))
        }
        server.Unlocked <- true
    }
}

func (server *Server) Handle(callback func()) {
    server.Unlocked = make(chan bool, 1)
	server.Callback = callback
}

func (server Server) Listen() {
    server.Unlocked <- true
	http.HandleFunc("/", server.Handler())
	fmt.Println("Listen on Port " + strconv.Itoa(server.Port))
	http.ListenAndServe(":" + strconv.Itoa(server.Port), nil)
}