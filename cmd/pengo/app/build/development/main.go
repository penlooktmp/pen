
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
    model := Model{}
    model.Initialize()

    //{{ model }}
    router := httprouter.New()
    
    http.ListenAndServe(":8080", router)
}
