package system

import (
	. "github.com/penlook/pengo/system/global"
	engine "github.com/flosch/pongo2"
	"fmt"
)

type Controller struct {
	Name string
	ActionName string
	Http Http
	Router Router
	ViewData engine.Context

	View chan Pair
	TotalDeclared int
	TotalEmit int
	Template View
	Signal chan int
	End chan bool

	StopOnSignal chan bool
	Response chan bool
}

// Share properties with view
type ViewBridge struct {
	Name string
	ActionName string
	Http Http
	Router Router
	ViewData engine.Context
}

func (controller *Controller) Initialize() {

	// Properties initialization
	controller.View = make(chan Pair, 20)
	controller.ViewData = engine.Context {}
	controller.TotalDeclared = 0
	controller.TotalEmit = 0

	viewBridge := ViewBridge {
		Name: controller.Name,
		ActionName: controller.ActionName,
		Http: controller.Http,
		Router: controller.Router,
		ViewData: controller.ViewData,
	}

	// Setup for template
	controller.Template = View {
		Controller: &viewBridge,
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

func (controller *Controller) addPairsToView(pairs Pair) {
	for key, value := range pairs {
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
				case pairs := <- controller.View :
					controller.addPairsToView(pairs)
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