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
func (app App) Before() {
}
// @Route /login/:uid/:password
// @Method GET
func (app App) Login(uid string, password string) {
	app.Session("id", uid)
	app.Session("password", password)
	user := app.Table("User", Schema {
		Username: "Loi",
		Password: 1234,
	})
	abc := app.Table("User", Schema {})
	abd := app.Table("User", Schema {})
	Print(abc)
	Print(abd)
	Print(user)
	app.View(Data{"title": "Index Page",})
	app.View(Data{"hello": "Welcome to golang",})
	app.View(Data{"avatar": "http://i.share.pho.to/fcf739b8_o.png",})
	app.View(Data{"id": uid,})
	app.View(Data{"pass": password,})
}
// @Route /abc
func (app App) Abc() {
}
func (app App) After() {
}
