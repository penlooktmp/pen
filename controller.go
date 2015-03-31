package pengo

import (
	. "github.com/penlook/pengo/builtin"
	engine "github.com/flosch/pongo2"
	"fmt"
)

type Controller struct {
	Name string
	ActionName string
	Http Http
	Router Router
	ViewData engine.Context
	View chan Data
	Template View
	TotalDeclared int
	TotalEmit int
	Model Model
	Translator Translator
	Signal chan int
	StopOnSignal chan bool
	End chan bool
}

// Share properties with view
type ViewBridge struct {
	Name string
	ActionName string
	Http Http
	Router Router
	ViewData engine.Context
}