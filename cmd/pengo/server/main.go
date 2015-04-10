package main

import (
 	"net/http"
 	//"fmt"
)

func handler(w http.ResponseWriter, r *http.Request) {
    //r.URL.Path[1:]
}

func main() {
    http.HandleFunc("/", handler)
    http.ListenAndServe(":80", nil)
}