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

        controller.LifeCycle(controller, "Index")
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