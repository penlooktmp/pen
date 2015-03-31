package main

import (
 	"net/http"
	"github.com/julienschmidt/httprouter"
	"github.com/penlook/pengo/system"
    "github.com/penlook/pengo/controller"
    "time"
    "fmt"
)

func timeTrack(start time.Time, name string) {
    elapsed := time.Since(start)
    fmt.Printf("%s took %s", name, elapsed)
}

func Handle(controller_name string, action_name string) func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, _ httprouter.Params) {

        defer timeTrack(time.Now(), "pengo")

    	action := controller.App {
            system.Controller {
                Name : "App",
                ActionName: "Index",
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
        action.WaitResponse()
	}
}

func main() {
	router := httprouter.New()
    router.GET("/index", Handle("App", "Index"))
    http.ListenAndServe(":80", router)
}
