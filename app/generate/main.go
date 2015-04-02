// AUTO GENERATED
// DO NOT MODIFIED IT

package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	. "github.com/penlook/pengo"
    . "github.com/penlook/pengo/module"
    "github.com/penlook/pengo/app/controller"
)

func Handle(controller_name string, action_name string) func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
    	controller := controller.App {
            Controller {
                Name: controller_name,
                ActionName: action_name,
                Http: Http {
                    Request : request,
                    Response : response,
                    Router: params,
                },
            },
	  	}

        // Life cycle
        controller.Initialize()
        controller.Start()
        controller.SetOnSignal()
        controller.InitAction()
        controller.BeforeAction(controller)
        controller.Action(controller)
        controller.AfterAction(controller)
        controller.WaitResponse()
        controller.Flow.Graph()
	}
}

func main() {

    /*System(`
        pwd
        echo "HELLO WORLD"
    `)*/

    router := httprouter.New()
    router.GET("/index/:name", Handle("App", "Index"))
    router.GET("/home/:name",  Handle("App", "Home"))
    http.ListenAndServe(":80", router)
}