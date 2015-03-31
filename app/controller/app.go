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
	. "github.com/penlook/pengo/builtin"
	. "github.com/penlook/pengo"
	"github.com/penlook/pengo/model/table"
)

type App struct {
	Controller
}

func (app App) Index() {

	table    := app.Table("User").Find()
	document := app.Document("Status").Find()
	username := app.POST("username")

	/*
	status := app.Model("Document.Status")
	*/

	app.View <- Data {
		"key1" : "value1",
		"key2" : user,
	}

	app.View <- Data {
		"key3" : "software developer",
		"key4" : "value2",
	}
}