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

// MVC ENGINE

func (controller *Controller) Initialize() {

	// Properties initialization
	controller.View = make(chan Data, 20)
	controller.ViewData = engine.Context {}
	controller.TotalDeclared = 0
	controller.TotalEmit = 0

	// Setup for template
	controller.Template = View {
		Controller: ViewBridge {
			Name: controller.Name,
			ActionName: controller.ActionName,
			Http: controller.Http,
			Router: controller.Router,
			ViewData: controller.ViewData,
		},
		Directory: "view",
	}

	// Multiple signal in life cycle
	controller.Signal = make(chan int, 10)

	// End flag for signal
	controller.StopOnSignal = make(chan bool, 1)

	// End flag for controller
	controller.End = make(chan bool, 1)

	// Listen system signal
	controller.OnSignal()
}

func (controller Controller) InitAction() {

	// Broadcast signal
	controller.Signal <- SignalInitAction
}

func (controller *Controller) addDataToView(data Data) {
	for key, value := range data {
		controller.ViewData[key] = value
	}
	// Remember number variable was passed
	controller.TotalEmit = controller.TotalEmit + 1
}

func (controller *Controller) OnSignal() {
	go func(controller *Controller) {
		loop := true
		for {
			select {
				case data := <- controller.View :
					controller.addDataToView(data)
				case signal := <- controller.Signal :
					controller.ProcessSignal(signal, &loop)
			}
			if ! loop {
				break
			}
		}
		fmt.Println(" --> OnSignal Done")
	}(controller)
}

func (controller Controller) ProcessSignal(signal int, loop *bool) {
	switch (signal) {
		case SignalResponse :
			*loop = false
			controller.End <- true
	}
}

func (controller Controller) BeforeAction() {
	// Broadcast signal
	controller.Signal <- SignalBeforeAction

}

func (controller *Controller) AfterAction() {
	controller.TotalDeclared = len(controller.View)
	go func(controller *Controller) {
		for {
			if controller.TotalEmit == controller.TotalDeclared {
				controller.RenderTemplate()
				break
			}
		}
		fmt.Println(" --> AfterAction Done")
	}(controller)
}

func (controller Controller) RenderTemplate() {
	controller.Template.Render()
    controller.Signal <- SignalResponse
}

func (controller Controller) WaitResponse() {
	select {
		case <- controller.End:
	}
}

// MODULES FUNCTION

func (controller Controller) Model(query string) string {
	return query
}

func (controller Controller) Session(key string, value string) string {
	return "Session values"
}

func (controller Controller) Cookie(key string, value string) string {
	return "Cookie values"
}

func (controller Controller) Translate(word string) string {
	return "ABC"
}

// REQUEST FUNCTION

func (controller Controller) GET(key string) string {
}

func (controller Controller) POST(key string) string {
}

func (controller Controller) PUT(key string) string {
}

func (controller Controller) PATCH(key string) string {
}

func (controller Controller) DELETE(key string) string {
}