package system

import (
	. "github.com/penlook/core/system/global"
	"fmt"
)

type Controller struct {
	Http Http
	View View
	Data map[string] interface{}
}

func (controller *Controller) Render(pairs HTML) {
	for key, value := range pairs {
		fmt.Println(key)
		fmt.Println(value)
		//controller.Data[key] = pairs[key]
	}
}

func (controller Controller) RenderTemplate() {
	fmt.Println(controller.Data)
}
