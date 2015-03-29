package system

import (
	engine "github.com/flosch/pongo2"
)

type View struct {
	Http Http
	Directory string
}

func (view View) Render() {

    var template = engine.Must(engine.FromFile("view/app/index.html"))
    template.ExecuteWriter(engine.Context{"key":"value"}, view.Http.Response)

	/*
	t := template.New("nonexported template demo")
    t, _ = t.Parse("hello {{.Name}}! Age is {{.nonExportedAgeField}}.")
    err := t.Execute(os.Stdout, p)
    if err != nil {
        fmt.Println("There was an error:", err.String())
    }*/

}
