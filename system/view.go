package system

import (
	engine "github.com/flosch/pongo2"
)

type View struct {
	Http Http
	Directory string
}

func (view View) ToContext() engine.Context {

    context := engine.Context{
        "key" : "value",
    }

    return context
    //for key, value := range view.
}

/*
func (view View) Render(html HTML) {
    var template = engine.Must(engine.FromFile("view/" + view.Http.Controller + "/" + view.Http.Action +".html"))
    err := template.ExecuteWriter(view.ToContext(), view.Http.Response)

    if err != nil {
        panic(err)
    }
}
*/