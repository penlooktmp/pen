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

Before() {
	@@login = true
}

@Route /hello/:uid/:password/:action
@Method GET
Login(uid string, password string, action int) {

	user := #mysql.User
	status := #mongo.Status

	Abc()
	Abc()



	//$listUser = #GetAllUser()

	//user.Find()

	// Save login data to session
	//Session("id", uid)
	//Session("password", password)

	$title  = "Index Page"
	$hello  = "Welcome to golang"
	$avatar = "http://i.share.pho.to/fcf739b8_o.png"
	$action = action
	$id     = uid
	$pass   = password
}

@Route /demo
Abc() {
	Send()
	a := "ABC"
	$name = a
}

After() {
	@@login = false
}


