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
	. "github.com/penlook/pengo/model"
)

type Model struct {
	Table_ Table
	Document_ Document
	KeyValue_ KeyValue
	Graph_ Graph
}

func (model Model) New() {

}

func (model Model) Build() {
	model.UseTable()
	model.UseDocument()
	model.UseKeyValue()
	model.UseGraph()
}

func (model Model) Table(table string) {}
func (model Model) Document(document string) {}
func (model Model) Key(key string) {}
func (model Model) Graph(document string) {}


