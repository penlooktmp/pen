package system

import (
	. "github.com/penlook/core/system/global"
	"fmt"
)

type Controller struct {
	Http Http
	View chan Map
	Data map[string] interface {}
	Signal chan int
}

func (controller *Controller) Initialize() {

	// Properties initialization
	controller.View = make(chan Map, 1)
	controller.Signal = make(chan int, 1)

	// Listen assignations from controller to view
	controller.OnAssignVariable()

}

func (controller Controller) OnAssignVariable() {
	go func() {
		select {
			case pairs := <- controller.View :
				fmt.Println(pairs)
			case signal := <- controller.Signal :
				switch (signal) {
				case SignalAfterAction:
					break
				}
		}
	}()
}

func (controller Controller) BeforeAction() {

	// Broadcast signal
	controller.Signal <- SignalBeforeAction

}

func (controller Controller) AfterAction() {

	// Emit after action signal
	controller.Signal <- SignalAfterAction

}

func (controller *Controller) RenderAction() {

	// Broadcast signal
	controller.Signal <- SignalRenderAction

	for key, value := range pairs {
		fmt.Println(key)
		fmt.Println(value)
		//controller.Data[key] = pairs[key]
	}
}

func (controller Controller) RenderTemplate() {
	fmt.Println(controller.Data)
}
