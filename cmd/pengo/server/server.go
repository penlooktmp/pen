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
	Callback func(url string)
}

func handler(writer http.ResponseWriter, request *http.Request) {
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
}

func (server *Server) Handle(callback func(url string)) {
	server.Callback = callback
}

func (server Server) Listen() {
	http.HandleFunc("/", handler)
	fmt.Println("Listen on Port " + strconv.Itoa(server.Port))
	http.ListenAndServe(":" + strconv.Itoa(server.Port), nil)
}