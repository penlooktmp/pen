package controller

import (
	"fmt"
)

type App struct {
	Controller
}

func (this App) Index() {
	fmt.Fprint(this.Response, "Not protected!\n")
}