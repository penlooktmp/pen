package controller

import (
	. "github.com/penlook/pengo/global"
	. "github.com/penlook/pengo"
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