package system

import (
	. "github.com/penlook/core/system/global"
	"fmt"
)

type Controller struct {
	Name string
	ActionName string
	Http Http
	Router Router
	ViewData map[string] interface {}

	View chan Pair
	TotalDeclare int
	TotalEmit int
	Template View
	Signal chan int
	End chan bool
}

// Share properties with view
type ViewBridge struct {
	Name string
	ActionName string
	Http Http
	Router Router
	ViewData map[string] interface {}
}

func (controller *Controller) Initialize() {

	// Properties initialization
	controller.View = make(chan Pair, 20)
	controller.ViewData = make(Pair)
	controller.TotalDeclare = 0
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

	// Make signal channel
	controller.Signal = make(chan int, 10)
	controller.End = make(chan bool, 1)

	// Listen system signal
	controller.OnSignal()
}

func (controller Controller) InitAction() {

	fmt.Println("INIT ACTION")

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
		exit := false
		for {
			select {
				case pairs := <- controller.View :
					controller.addPairsToView(pairs)
				case signal := <- controller.Signal :
					controller.ProcessSignal(signal, &exit)
			}
			if exit {
				break
			}
		}

		// Response to browser after finishing life cycle
		controller.Signal <- SignalResponse
	}(controller)
}

func (controller Controller) ProcessSignal(signal int, exit *bool) {
	switch (signal) {
		case SignalResponse :
			*exit = true
			controller.End <- true
	}
}

func (controller Controller) BeforeAction() {

	fmt.Println("BEFORE ACTION")

	// Broadcast signal
	controller.Signal <- SignalBeforeAction

}

func (controller *Controller) AfterAction() {
	controller.TotalDeclare = len(controller.View)
	go func(controller *Controller) {
		for {
			if (controller.TotalEmit == controller.TotalDeclare) {
				controller.RenderAction()
				break
			}
		}
	}(controller)
}

func (controller Controller) RenderAction() {

	// Broadcast signal
	controller.Signal <- SignalRenderAction

	// Render Template
	controller.RenderTemplate()
}

func (controller Controller) RenderTemplate() {
	controller.Template.Render()
    controller.Signal <- SignalResponse
}

func (controller Controller) WaitResponse() {
	select {
		case <- controller.End:
			controller.Destroy()
	}
}

func (controller *Controller) Destroy() {
	controller.Signal = nil
	controller.View   = nil
}