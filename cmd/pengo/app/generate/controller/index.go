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
// AUTO GENERATED
// DO NOT MODIFY
package controller
import (
	. "github.com/penlook/pengo"
	. "github.com/penlook/pengo/cmd/pengo/app/generate/extend"
)
type Index struct { Controller }
func (index Index) Start() {
	Pengo()
	index.Pick("Start")
}
// @Controller Index
// @Pick "Before Action"
func (index Index) Before() {
	// TODO
}
// @Pick "After Action"
func (index Index) After() {
	// TODO
}
// @Route /index/index
// @Method GET
// @Pick "Index Action"
func (index Index) Index() {
	index.View(Data{"title": "Index Page",})
	index.View(Data{"hello": "Welcome to Index Page",})
	index.Pick("Before call pk")
	index.Pick("After call pk")
	index.Pick("Assign slogan and author")
}
