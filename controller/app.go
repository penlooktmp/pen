package controller

import (
	. "github.com/penlook/pengo/system/global"
	. "github.com/penlook/pengo/system"
)

type App struct {
	Controller
}

func (app App) Index() {

	app.View <- Pair {
		"key1" : "value1",
		"key2" : "value2",
	}

	app.View <- Pair {
		"key3" : "value3",
		"key4" : "value4",
	}

	app.View <- Pair {
		"key5" : "value5",
		"key6" : "value6",
	}

	app.View <- Pair {
		"key7" : "value7",
		"key8" : "value8",
	}

	app.View <- Pair {
		"key9"  : "value9",
		"key10" : "value10",
	}

	app.View <- Pair {
		"key11" : "value11",
		"key12" : "value12",
	}
}