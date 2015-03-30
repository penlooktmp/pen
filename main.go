package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	"github.com/penlook/core/system"
    "github.com/penlook/core/controller"
)

func Handle(controller_name string, action_name string) func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {

    return func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {

        http := system.Http {
                    Request : request,
                    Response : response,
                    Controller : controller_name,
                    Action : action_name,
                }

    	action  :=  controller.App {
                        system.Controller {
                            Http: http,
                            /*View: system.View {
                                Http: http,
                                Directory: "view",
                            },*/
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
