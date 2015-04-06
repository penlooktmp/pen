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
	. "github.com/penlook/pengo/cmd/pengo/app/generate"
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

// @route /app/index
// @method GET
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
