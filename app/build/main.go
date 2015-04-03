// AUTO GENERATED

package main

import (
 	"net/http"
    "unicode"
    "strings"
    "github.com/julienschmidt/httprouter"
	. "github.com/penlook/pengo"
    . "github.com/penlook/pengo/module"
    . "github.com/penlook/pengo/app/controller"
)

func Base(controllerName string, actionName string, response http.ResponseWriter, request *http.Request, params httprouter.Params) Controller {
    if actionName == "*" {
        actionName = params.ByName("action")
        if actionName == "" {
            actionName = "index"
        }
    }

    array := []rune(strings.ToLower(actionName))
    array[0] = unicode.ToUpper(array[0])
    actionName = string(array)

    return Controller {
        Name: controllerName,
        ActionName: actionName,
        Http: Http {
            Request : request,
            Response : response,
            Router: params,
        },
    }
}

func HandleApp(actionName string) func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
        controller := App {
            Base("App", actionName, response, request, params),
        }
        controller.Initialize()
        controller.Start()
        controller.InitAction()
        controller.BeforeAction(controller)
        controller.Action(controller)
        controller.AfterAction(controller)
        controller.Flow.Graph()
	}
}

func HandleIndex(actionName string) func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
    return func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
        controller := Index {
            Base("Index", actionName, response, request, params),
        }
        controller.Initialize()
        controller.Start()
        controller.InitAction()
        controller.BeforeAction(controller)
        controller.Action(controller)
        controller.AfterAction(controller)
        controller.Flow.Graph()
    }
}

func main() {
    router := httprouter.New()
    router.GET("/",  HandleIndex("Index"))
    router.GET("/app/:action", HandleApp("*"))
    http.ListenAndServe(":80", router)
}