package controller

import (
	. "github.com/penlook/pengo/builtin"
	. "github.com/penlook/pengo"
)

type App struct {
	Controller
}

func (app App) Index() {

	/*
	user   := app.Model("Table.User")
	status := app.Model("Document.Status")
	*/

	app.View <- Data {
		"key1" : "value1",
		"key2" : "value2",
	}

	app.View <- Data {
		"key3" : "software developer",
		"key4" : "value2",
	}
}