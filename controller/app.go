package controller

import (
	. "github.com/penlook/core/system/global"
	. "github.com/penlook/core/system"
)

type App struct {
	Controller
}

func (this App) Index() {
	this.Render(HTML{
		"key1" : "value1",
		"key2" : "value2",
	})
}