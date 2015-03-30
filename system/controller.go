package system

import (
	. "github.com/penlook/core/system/global"
	"fmt"
)

type Controller struct {
	Name string
	Action string
	Http Http
	Router Router
	View chan Pair
	Template View
	ViewData map[string] interface {}
	Data map[string] interface {}
	Signal chan int
}

func (controller *Controller) Initialize() {

	// Properties initialization
	controller.View = make(chan Pair, 10)
	controller.ViewData = make(Pair)

	// Setup for template
	controller.Template = View {
		Http: controller.Http,
		Data: controller.ViewData,
		Directory: "view",
	}

	// Make signal channel
	controller.Signal = make(chan int, 10)

	// Listen system signal
	controller.OnSignal()
}

func (controller Controller) InitAction() {

	// Broadcast signal
	controller.Signal <- SignalInitAction

}

func (controller Controller) OnSignal() {
	go func() {
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
		fmt.Println("End listen signal")
	}()
}

func (controller *Controller) addPairsToView(pairs Pair) {
	for key, value := range pairs {
		controller.ViewData[key] = value
	}
}

func (controller Controller) ProcessSignal(signal int, exit *bool) {
	switch (signal) {
		case SignalInitAction:
			fmt.Println("Init Action")

		case SignalBeforeAction:
			fmt.Println("Before Action")

		case SignalAfterAction:
			fmt.Println("After Action")
			controller.RenderAction()

		case SignalRenderAction:
			fmt.Println("Render Action")
			*exit = true
	}
}

func (controller Controller) BeforeAction() {

	// Broadcast signal
	controller.Signal <- SignalBeforeAction

}

func (controller Controller) AfterAction() {

	// Emit after action signal
	controller.Signal <- SignalAfterAction

}

func (controller Controller) RenderAction() {

	// Broadcast signal
	controller.Signal <- SignalRenderAction

	// Render Template
	controller.RenderTemplate()
}

func (controller Controller) RenderTemplate() {

}