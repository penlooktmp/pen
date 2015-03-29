package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	"fmt"
)

func Index(w http.ResponseWriter, r *http.Request, _ httprouter.Params) {
    fmt.Fprint(w, "Not protected!\n")
}

func main() {
	router := httprouter.New()
    router.GET("/index", Index)
    http.ListenAndServe(":8080", router)
}
