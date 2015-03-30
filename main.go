package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	"github.com/penlook/core/system"
    "github.com/penlook/core/controller"
)

func Handle(controller_name string, action_name string) func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {

    	action  :=  controller.App {
                        system.Controller {
                            Http: system.Http {
                                Request : request,
                                Response : response,
                            },
                            Router: system.Router {
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

    	//action.Index()
	}
}

func main() {
	router := httprouter.New()
    router.GET("/index", Handle("App", "Index"))
    http.ListenAndServe(":80", router)
}
