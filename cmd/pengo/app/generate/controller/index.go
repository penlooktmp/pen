// AUTO GENERATED
// DO NOT MODIFY
package controller
import (
	. "github.com/penlook/pengo"
	. "github.com/penlook/pengo/cmd/pengo/app/generate/extend"
)
type Index struct { Controller }
func (index Index) Start() {
	Pengo()
	index.Pick("Start")
}
// @Pick "Before Action"
func (index Index) Before() {
}
// @Pick "After Action"
func (index Index) After() {
}
// @Route /index/index
// @Method GET
// @Pick "Index Action"
func (index Index) Index() {
	index.View(Data{"title": "Index Page",})
	index.View(Data{"hello": "Welcome to Index Page",})
	index.Pick("Before call pk")
	index.Pick("After call pk")
	index.Pick("Assign slogan and author")
}
