package controller

import (
	. "github.com/penlook/pengo/system/global"
	. "github.com/penlook/pengo/system"
)

type App struct {
	Controller
}

func (app App) Index() {
	app.View <- Data {
		"key1" : "value1",
		"key2" : "value2",
	}
}