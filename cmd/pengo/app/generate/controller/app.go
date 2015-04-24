
	// AUTO GENERATED
	// DO NOT MODIFY
	package controller
	import (
		. "github.com/penlook/pengo"
		. "github.com/penlook/pengo/cmd/pengo/app/generate/extend"
		. "github.com/penlook/pengo/cmd/pengo/app/generate/model"
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
	user := MySql_Table_User(Schema{
		Username: "Loi",
		Password: 1234,
	})

	user.Create()
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
