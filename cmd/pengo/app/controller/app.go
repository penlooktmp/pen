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

// Library
@use penlook
@use google as g

// App Controller
@controller App

func Before() {
	@Pick("Before action")
}

func After() {
	@Pick("After action")
}

@route /login/:id/:password
@method GET
func Login(id int, password string) {

	Print(id)

	@Pick("Home action")

	// Assign variable to template
	$title  = "Index Page"
	$sample = "Welcome to application home"
	$image  = "http://img3.wikia.nocookie.net/__cb20140410201208/pokemon/images/e/ef/025Pikachu_SSB4.png"

	// SELECT * FROM `User` WHERE id=1
	//user := #User.Find(1)

	// Print username
	//Print(user.Name)
}
