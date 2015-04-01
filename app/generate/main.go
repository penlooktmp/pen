// AUTO GENERATED
// DO NOT MODIFIED IT

package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	. "github.com/penlook/pengo"
    . "github.com/penlook/pengo/module"
    "github.com/penlook/pengo/app/controller"
    "fmt"
)

func Handle(controller_name string, action_name string) func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, router httprouter.Params) {

    	controller := controller.App {
            Controller {
                Name : "App",
                ActionName: "Index",
                Http: Http {
                    Request : request,
                    Response : response,
                    Router: router,
                },
                Router: Router {
                    Method: "GET",
                    Controller : controller_name,
                    Action : action_name,
                },
            },
	  	}

        // Life cycle
        controller.Initialize()
        controller.Start()

        //controller.SetOnSignal()
        //controller.InitAction()
        //controller.BeforeAction()
        controller.Index()
        //controller.AfterAction()
        //controller.WaitResponse()
        controller.Test()

        fmt.Println("Show Graph")
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
    http.ListenAndServe(":80", router)
}