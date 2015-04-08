/**
 * Pengo Project
 *
 * Copyright (c) 2015 Penlook Development Team
 *
 * --------------------------------------------------------------------
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * Author:
 *     Loi Nguyen       <loint@penlook.com>
 */
package pengo

import (
	engine "github.com/flosch/pongo2"
	"github.com/penlook/pengo/module"
	"github.com/penlook/pengo/model"
	"github.com/julienschmidt/httprouter"
	"container/list"
	"time"
	"reflect"
	"fmt"
)

type Controller struct {
	Name string
	ActionName string
	Http module.Http
	Router module.Router
	ViewData engine.Context
	Template View
	TotalDeclared int
	TotalEmit int
	Translator module.Translator
	Signal chan int
	StopOnSignal chan bool
	End chan bool

	Config Config
	Model Model
	Flow module.Flow
	Module Module
}

// Share properties with View
type ViewBridge struct {
	Name string
	ActionName string
	Http module.Http
	Router module.Router
	ViewData engine.Context
}

// MVC -------------------------------------

// Controller initialization
func (controller *Controller) Initialize() {

	// Properties initialization
	controller.ViewData = engine.Context {}
	controller.TotalDeclared = 0
	controller.TotalEmit = 0

	// Setup for template
	controller.Template = View {
		Controller: ViewBridge {
			Name: controller.Name,
			ActionName: controller.ActionName,
			Http: controller.Http,
			Router: controller.Router,
			ViewData: controller.ViewData,
		},
		Directory: "view",
	}

	// Setup for model
	controller.Model = Model {
		Flow: controller.Flow,
	}

	controller.Model.Initialize()

	// Setup for module
	controller.Module = Module {}

	// Setup for flow
	controller.Flow = module.Flow {
		Tracking: list.New(),
		Unit: time.Millisecond * 10,
		Mode: "DEBUG",
	}

	// Multiple signal in life cycle
	controller.Signal = make(chan int, 10)

	// End flag for signal
	controller.StopOnSignal = make(chan bool, 1)

	// End flag for controller
	controller.End = make(chan bool, 1)
}

func (controller Controller) Start() {
	controller.Flow.Pick("start controller")
}

// Action initialization
func (controller Controller) InitAction() {

	// Broadcast signal
	controller.Signal <- SignalInitAction
}

// Add data to View
func (controller *Controller) View(data Data) {
	for key, value := range data {
		controller.ViewData[key] = value
	}
}

func (controller Controller) BeforeAction(parent interface {}) {
	beforeActionVal := reflect.ValueOf(parent).MethodByName("Before")
    if beforeActionVal.IsValid() {
    	beforeActionInterface := beforeActionVal.Interface()
    	beforeAction := beforeActionInterface.(func())
    	beforeAction()
    }
}

func (controller *Controller) Action(parent interface {}, argumentString string, params httprouter.Params) {
    actionVal := reflect.ValueOf(parent).MethodByName(controller.ActionName)
    if actionVal.IsValid() {
		args := ReflectActionArgument(argumentString, params)
    	actionVal.Call(args)
    } else {
   		controller.ActionName = ""
    }
}

func (controller *Controller) AfterAction(parent interface {}) {

	if controller.ActionName == "" {
		Print("Action does not exist !")
		return
	}

	afterActionVal := reflect.ValueOf(parent).MethodByName("After")
    if afterActionVal.IsValid() {
    	afterActionInterface := afterActionVal.Interface()
    	afterAction := afterActionInterface.(func())
    	afterAction()
    }

    controller.RenderTemplate()
}

func (controller Controller) RenderTemplate() {
	controller.Template.Render()
}

func (controller Controller) Test() {
	fmt.Fprint(controller.Http.Response, "Welcome!\n")
}

// MODULE ----------------------------------

func (controller Controller) Pick(message string) {
	controller.Flow.Pick(message)
}

func (controller Controller) Service(service string) string {
	return "Service"
}

func (controller Controller) Session(key string, value interface {}) string {
	return "Session values"
}

func (controller Controller) Cookie(key string, value string) string {
	return "Cookie values"
}

func (controller Controller) Translate(word string) string {
	return "ABC"
}

// MODEL Alias --------------------------------

func (controller Controller) Table(args ...interface {}) model.Table {
	controller.Model.Table()
	switch len(args) {
		case 1:
			tableName := args[0].(string)
			type Empty struct {}
			return controller.Model.Driver.Table.ByTable(tableName, Empty {})
		case 2:
			tableName := args[0].(string)
			schema := args[1]
			return controller.Model.Driver.Table.ByTable(tableName, schema)
		default:
			return model.Table {}
	}
}

func (controller Controller) Document(document string) interface {} {
	return "controller.Model.Document(document)"
}

func (controller Controller) Key(key string) interface {} {
	return "controller.Model.Key(key)"
}

func (controller Controller) Graph(graph string) interface {} {
	return "controller.Model.Graph(graph)"
}

// Http Alias -----------------------------------

func (controller Controller) GET(key string) string {
	return controller.Http.GET(key)
}

func (controller Controller) POST(key string) string {
	return controller.Http.POST(key)
}

func (controller Controller) PUT(key string) string {
	return controller.Http.PUT(key)
}

func (controller Controller) PATCH(key string) string {
	return controller.Http.PATCH(key)
}

func (controller Controller) DELETE(key string) string {
	return controller.Http.DELETE(key)
}



