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
	"crypto/md5"
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

type User struct {
	Id       int64
	Username string `sql:"type:varchar(100);"`
	Email    string `sql:"type:varchar(100);"`
	Password string `sql:"type:varchar(200);"`
}

func TestMySql(t *testing.T) {

	assert := assert.New(t)

	mysql := MySql {
		Name:     "Penlook",
		Server:   "localhost",
		Port:     3306,
		Database: "test",
		Charset:  "utf8",
		Username: "root",
	}.Connect()

	mysql.DropTableIfExists(&User{})
	mysql.CreateTable(&User{})

	for i := 0; i < 100; i++ {
		mysql.Create(User{
			Username: "loint",
			Email:    "loint@penlook.com",
			Password: fmt.Sprintf("%x", md5.Sum([]byte("12345"))),
		})
	}

	var users []User
	var count int

	// Assert number of rows
	mysql.Find(&users).Count(&count)
	assert.Equal(100, count)

	// Cleanup
	mysql.DropTableIfExists(&User{})
}