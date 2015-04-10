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

@Controller App

@Pick "Before Action"
@Before() {
	@@login = true
}

@Route /login/:uid/:password
@Method GET
@Pick "Simple Login Form"
@Login(uid int, password string) {

	// Save login data to session
	@Session("id", uid)
	@Session("password", password)

	// Get data from table User
	user := #User {
		Username: "Loi",
		Password: 1234,
	}

	Print(user)

	// Call model of app controller
	// users := #ListAll()

	// Assign variable to template
	$title  = "Index Page"
	$hello  = "Welcome to golang"
	$avatar = "http://i.share.pho.to/fcf739b8_o.png"
	$id     = uid
	$pass   = password
}

@Abc() {
	// TODO
}

@Pick "After Action"
@After() {
	@@login = false
}


