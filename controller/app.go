package controller

import (
	"github.com/penlook/core/system"
	"fmt"
)

type App struct {
	system.Controller
}

func (this App) Index() {
	fmt.Fprint(this.Http.Response, "Not protected!\n")
}