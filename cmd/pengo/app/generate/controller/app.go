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
	// TODO
}
// @Pick "After Action"
func (app App) After() {
	// TODO
}
// @Route /login/:username/:password
// @Method GET
// @Pick "Sample Login"
func (app App) Login(userid int, password string) {
	app.Pick("Start session")
	// Assign to session
	app.Session("key", "value")
	app.Pick("End session")
	// Assign variable to template
	app.View(Data{"title": "Index Page",})
	app.View(Data{"sample": "Welcome to golang",})
	app.View(Data{"userid": userid,})
	app.View(Data{"password": password,})
	app.View(Data{"image": "http://www.unixstickers.com/image/cache/data/stickers/golang/golang.sh-600x600.png",})
	// SELECT * FROM `User` WHERE id=1
	// Print username
	//Print(user.Name)
}
