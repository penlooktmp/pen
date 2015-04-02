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
package model

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

type Person struct {
	Name  string
	Phone string
}

func TestMongo(t *testing.T) {
	assert := assert.New(t)

	mongo := Mongo {
		Name: "Penlook",
		Server: []string{
			"localhost:27017",
		},
	}.Connect()

	penlook := mongo.Database("penlook")
	person := penlook.Collection("person")

	// Insert some documents
	err1 := person.Insert(
		Person{"Ale", "+55 53 8116 9639"},
		Person{"Cla", "+55 53 8402 8510"},
	)

	assert.Nil(err1)

	// Retrieve result
	count, err2 := person.Find(Json{}).Count()
	assert.Nil(err2)
	assert.Equal(2, count)

	// Clean up
	_, err3 := person.RemoveAll(Json{})
	assert.Nil(err3)

	// Close connection
	doc.Close()
}