package generate

import (
	. "github.com/penlook/pengo"
)

type App struct {
	Controller
}

func (a App) Before() {
	a.Pick("Before action")
}

func (a App) After() {
	a.Pick("After action")
}

func (a App) Index() {
	a.Pick("Assign Title")
	a.View(Data{
		"title" : "Index Page",
	})

	a.Pick("Before call pk")
	Pk()
	a.Pick("After call pk")

	a.Pick("Assign slogan and author")
	name := a.GET("name")

	a.View(Data{
		"slogan" : "Welcome to Index Page",
		"author" : name,
	})
}
