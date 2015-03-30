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
	controller.View = make(chan Map, 100)
	controller.Signal = make(chan int, 100)
}

func (controller Controller) InitAction() {

	// Broadcast signal
	controller.Signal <- SignalInitAction

	// Listen assignations from controller to view
	controller.OnAssignVariable()

}

func (controller Controller) OnSignal() {
	go func() {
		flag := false
		for {
			select {
				case pairs := <- controller.View :
					fmt.Println(pairs)
				case signal := <- controller.Signal :
					controller.processSignal(signal, &flag)
			}
			if flag {
				break
			}
		}
		fmt.Println("End listen signal")
	}()
}

func (controller Controller) ProcessSignal(signal, flag) {
	switch (signal) {
	case SignalInitAction:
		fmt.Println("Init Action")
	}
	case SignalBeforeAction:
		fmt.Println("Before Action")
	}
	case SignalAfterAction:
		fmt.Println("After Action")
	}
	case SignalRenderAction:
		fmt.Println("Render Action")
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

	/*for key, value := range pairs {
		fmt.Println(key)
		fmt.Println(value)
		controller.Data[key] = pairs[key]
	}*/
}