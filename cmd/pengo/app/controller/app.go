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
func Before() {
	// TODO
}

@Pick "After Action"
func After() {
	// TODO
}

@Route /login/:userid/:password
@Method GET
@Pick "Sample Login"
func Login(userid int, password string) {

	@Pick("Start session")

	// Assign to session
	@Session("key", "value")

	@Pick("End session")

	// Assign variable to template
	$title  = "Index Page"
	$sample = "Welcome to golang"
	$userid = userid
	$password = password
	$image  = "http://www.unixstickers.com/image/cache/data/stickers/golang/golang.sh-600x600.png"

	// SELECT * FROM `User` WHERE id=1
	//user := #User.Find(1)

	// Print username
	//Print(user.Name)
}
