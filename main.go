package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	"github.com/penlook/core/controller"
)

func Handle(action string) func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {
    	action  :=  controller.App {
                        controller.Controller {
    			    	    Request : request,
    					    Response : response,
                        },
    			  	}

        action.Index()
    	//action.Index()
	}
}

func main() {
	router := httprouter.New()
    router.GET("/index", Handle("App.Index"))
    http.ListenAndServe(":8080", router)
}
