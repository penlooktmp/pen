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
package controller

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

// @router /index/:id
// @method GET POST
// @less abc.less
// @dart xxx.dart
// @error 408
func (a App) Index() {

	a.Pick("Assign Title")
	a.View(Data{
		"title" : "Index Page",
	})

	a.Pick("Assign slogan and author")
	name := a.GET("name")

	a.View(Data{
		"slogan" : "Welcome to Index Page",
		"author" : name,
	})
}

// @router /home/loint
func (a App) Home() {

	a.Pick("Assign Title")
	a.View(Data{
		"title" : "Home Page",
	})

	a.Pick("Assign sample")
	a.View(Data{
		"sample" : "This is Homepage",
		"image" : "http://image.spreadshirtmedia.com/image-server/v1/products/16685204/views/1,width=378,height=378,appearanceId=2/Golang-Fan-Shirt.jpg",
	})
}
