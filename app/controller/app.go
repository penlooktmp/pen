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
	//"fmt"
)

type App struct {
	Controller
}

func (app App) Before() {
	app.Pick("Before action")
}

func (app App) After() {
	app.Pick("After action")
}

// @router /index/loint
func (app App) Index() {

	app.Pick("Assign Title")
	app.View <- Data {
		"title" : "Index Page",
	}

	app.Pick("Assign slogan and author")
	app.View <- Data {
		"slogan" : "Welcome to Index Page",
		"author" : "Loi Nguyen",
	}
}

// @router /home/loint
func (app App) Home() {

	app.Pick("Assign Title")
	app.View <- Data {
		"title" : "Home Page",
	}

	app.Pick("Assign sample")
	app.View <- Data {
		"sample" : "This is Homepage",
		"image" : "http://image.spreadshirtmedia.com/image-server/v1/products/16685204/views/1,width=378,height=378,appearanceId=2/Golang-Fan-Shirt.jpg",
	}
}
