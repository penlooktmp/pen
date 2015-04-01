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
package pengo

import (
	engine "github.com/flosch/pongo2"
    "strings"
)

type View struct {
	Controller ViewBridge
	Directory string
}

func (view View) Render() {
	// Testing
    var template = engine.Must(engine.FromFile("../" + strings.ToLower(view.Directory) + "/" + strings.ToLower(view.Controller.Name) + "/" + strings.ToLower(view.Controller.ActionName) + ".html"))
    err := template.ExecuteWriter(view.Controller.ViewData, view.Controller.Http.Response)
    if err != nil {
        panic(err)
    }
}