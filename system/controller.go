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
	TotalDeclared int
	TotalEmit int
	Template View
	Signal chan int
	End chan bool

	ListenSignal chan bool
	Response chan bool
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
	controller.ListenSignal = make(chan bool, 1)

	// End flag for controller
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
		for {
			select {
				case pairs := <- controller.View :
					controller.addPairsToView(pairs)
				case signal := <- controller.Signal :
					controller.ProcessSignal(signal)
			}

			// Stop listening to signals
			// controller.ListenSignal <- false
			if ! <- controller.ListenSignal {
				break
			}
		}
	}(controller)
}

func (controller Controller) ProcessSignal(signal int) {
	switch (signal) {
		case SignalResponse :
			controller.ListenSignal <- false
			controller.Response <- true
	}
}

func (controller Controller) BeforeAction() {

	fmt.Println("BEFORE ACTION")

	// Broadcast signal
	controller.Signal <- SignalBeforeAction

}

func (controller *Controller) AfterAction() {

	fmt.Println("AFTER ACTION")

	controller.TotalDeclared = len(controller.View)
	go func(controller *Controller) {
		for {
			fmt.Println("EMIT ", controller.TotalEmit)
			fmt.Println("DECLARED ", controller.TotalDeclared)
			if controller.TotalEmit == controller.TotalDeclared {
				fmt.Println("START RENDER Template")
				controller.RenderTemplate()
				break
			}
		}
	}(controller)
}

func (controller Controller) RenderTemplate() {
	controller.Template.Render()
	fmt.Println("EMIT SIGNAL Response")
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