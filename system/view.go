package system

import (
    . "github.com/penlook/core/system/global"
	engine "github.com/flosch/pongo2"
)

type View struct {
	Http Http
	Directory string
}

func (view View) ToContext() engine.Context {
    return engine.Context{"key":"value"}
}

func (view View) Render(html HTML) {

    var template = engine.Must(engine.FromFile("view/" + view.Http.Controller + "/" + view.Http.Action +".html"))
    template.ExecuteWriter(view.ToContext(), view.Http.Response)

	/*
	t := template.New("nonexported template demo")
    t, _ = t.Parse("hello {{.Name}}! Age is {{.nonExportedAgeField}}.")
    err := t.Execute(os.Stdout, p)
    if err != nil {
        fmt.Println("There was an error:", err.String())
    }*/

}
