package controller

import (
	. "github.com/penlook/core/system/global"
	. "github.com/penlook/core/system"
)

type App struct {
	Controller
}

func (app App) Index() {

	app.View <- Map {
		"key1" : "value1",
		"key2" : "value2",
	}

	app.View <- Map {
		"key3" : "value3",
		"key4" : "value4",
	}

	app.View <- Map {
		"key5" : "value5",
		"key6" : "value6",
	}

}