// AUTO GENERATED
// DO NOT MODIFY
package controller
import (
	. "github.com/penlook/pengo"
	. "github.com/penlook/pengo/cmd/pengo/app/generate/extend"
)
type App struct { Controller }
func (app App) Start() {
	Pengo()
	app.Pick("Start")
}
// @Controller App
// @Pick "Before Action"
func (app App) Before() {
}
// @Route /login/:uid/:password
// @Method GET
// @Pick "Simple Login Form"
func (app App) Login(uid int, password string) {
	// Save login data to session
	app.Session("id", uid)
	app.Session("password", password)
	// Get data from table User
	user := app.Table("User", Schema {
		Username: "Loi",
		Password: 1234,
	})
	user.Create()
	user.First()
	// Call model of app controller
	// users := app.Model.Controller.AppListAll()
	// Assign variable to template
	app.View(Data{"title": "Index Page",})
	app.View(Data{"hello": "Welcome to golang",})
	app.View(Data{"avatar": "http://i.share.pho.to/fcf739b8_o.png",})
	app.View(Data{"id": uid,})
	app.View(Data{"pass": password,})
}
// @Pick "After Action"
func (app App) After() {
}
