package server

import (
 	"net/http"
 	"fmt"
 	"strconv"
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