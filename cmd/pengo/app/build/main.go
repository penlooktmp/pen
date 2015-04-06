
// AUTO GENERATED
// DO NOT MODIFY
package main

import (
 	"net/http"
    "unicode"
    "strings"
    "github.com/julienschmidt/httprouter"
	. "github.com/penlook/pengo"
    . "github.com/penlook/pengo/module"
    . "github.com/penlook/pengo/cmd/pengo/app/generate/controller"
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
        Config: Config {
            ViewRoot: "./view",
        },
        Http: Http {
            Request : request,
            Response : response,
            Router: params,
        },
    }
}

func main() {
    router := httprouter.New()
    router.GET("/app/:name", func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
    		c := App {
        		Base("App", "Home", response, request, params),
    		}
    		c.Initialize()
    		c.Start()
    		c.InitAction()
    		c.BeforeAction(c)
    		c.Action(c)
    		c.AfterAction(c)
    		c.Flow.Graph()
		})
	router.GET("/index/index", func(response http.ResponseWriter, request *http.Request, params httprouter.Params) {
    		c := Index {
        		Base("Index", "Index", response, request, params),
    		}
    		c.Initialize()
    		c.Start()
    		c.InitAction()
    		c.BeforeAction(c)
    		c.Action(c)
    		c.AfterAction(c)
    		c.Flow.Graph()
		})
	
    http.ListenAndServe(":80", router)
}
