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

type Driver struct {
	Table Table
	Document Document
	KeyValue KeyValue
	Graph Graph
}

type Model struct {
	Config Config
	Driver Driver
	Flow Flow
}

func (model *Model) Initialize() {
	model.Driver = Driver {}
}

func (model Model) Connect() {
	model.ConnectTable()
	model.ConnectDocument()
	model.ConnectKeyValue()
	model.ConnectGraph()
	model.Flow("after model connection")
}

// Fork concurrency connection to increase performance

func (model *Model) ConnectTable() {
	go func(model *Model) {
		model.Driver.Table = Table {
			Name:     "SQL Connection",
			Server:   "localhost",
			Port:     3306,
			Database: "test",
			Charset:  "utf8",
			Username: "root",
			Password: "root",
		}
		model.Driver.Table.Connect()
		model.Flow("after table connection")
	}(model)
}

func (model *Model) ConnectDocument() {
	go func(model *Model) {
		model.document.Connect()
	}(model)
}

func (model *Model) ConnectKeyValue() {
	go func(model *Model) {
		model.keyValue.Connect()
	}(model)
}

func (model *Model) ConnectGraph() {
	go func(model *Model) {
		model.graph.Connect()
	}(model)
}

// API ------------------------------------

func (model Model) Table(table string) string {
	return model.Driver.Table.
}

func (model Model) Document(document string) string {
	return document
}

func (model Model) Key(key string) string {
	return key
}

func (model Model) Graph(graph string) string {
	return graph
}