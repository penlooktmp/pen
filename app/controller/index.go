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
	. "github.com/penlook/pengo/app/generate"
)

type Index struct {
	Controller
}

func (i Index) Before() {
	i.Pick("Before action")
}

func (i Index) After() {
	i.Pick("After action")
}

// @router /index/:id
// @less abc.less
// @dart xxx.dart
// @error 408
func (i Index) Index() {

	i.Pick("Test Index Action")
	user := i.Table("User", Schema {
		Username: "Loi Nguyen",
		Email: "loint@penlook.com",
		Password: "12345",
	})

	user.Create()

	// Select first user
	//user.First()
}

// @Router /home
// @Method GET
func (i Index) Home() {

	i.GET("abc")
	i.POST("pl")
	i.Session()

	i.Pick("Test Index Action")

	user := i.Table("User", Schema {
		Username: "Loi Nguyen",
		Email: "loint@penlook.com",
		Password: "12345",
	})

	user.Create()

	// Select first user
	//user.First()
}