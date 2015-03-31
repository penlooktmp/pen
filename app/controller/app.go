package controller

import (
	. "github.com/penlook/pengo/builtin"
	. "github.com/penlook/pengo"
	"github.com/penlook/pengo/model/table"
)

type App struct {
	Controller
}

func (app App) Index() {

	table    := app.Model.Table("User").Find()
	document := app.Model.Document("Status").Find()

	/*
	status := app.Model("Document.Status")
	*/

	app.View <- Data {
		"key1" : "value1",
		"key2" : user,
	}

	app.View <- Data {
		"key3" : "software developer",
		"key4" : "value2",
	}
}