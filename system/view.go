package system

import (
	engine "github.com/flosch/pongo2"
    "strings"
    //"fmt"
)

type View struct {
	Controller *ViewBridge
	Directory string
}

func (view View) ToContext() engine.Context {
    context := engine.Context {}
    for key, value := range view.Controller.ViewData {
        context[key] = value
    }
    return context
}

func (view View) Render() {
    var template = engine.Must(engine.FromFile(strings.ToLower(view.Directory) + "/" + strings.ToLower(view.Controller.Name) + "/" + strings.ToLower(view.Controller.ActionName) + ".html"))
    err := template.ExecuteWriter(view.ToContext(), view.Controller.Http.Response)
    if err != nil {
        panic(err)
    }
}