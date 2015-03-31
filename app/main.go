package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	. "github.com/penlook/pengo/system"
    "github.com/penlook/pengo/app/controller"
)



func Handle(controller_name string, action_name string) func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {

        defer Runtime(Now(), "pengo")

    	action := controller.App {
            Controller {
                Name : "App",
                ActionName: "Index",
                Http: Http {
                    Request : request,
                    Response : response,
                },
                Router: Router {
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
        action.WaitResponse()

	}
}

func main() {

    /*System(`
        pwd
        echo "HELLO WORLD"
    `)*/

    router := httprouter.New()
    router.GET("/index", Handle("App", "Index"))
    http.ListenAndServe(":80", router)
}