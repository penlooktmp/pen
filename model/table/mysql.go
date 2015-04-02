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
	"fmt"
	"github.com/penlook/gorm"
	_ "github.com/penlook/mysql"
)

type MySql struct {
	Name     string
	Server   string
	Port     int
	Database string
	Charset  string
	Username string
	Password string
	Connection gorm.DB
}

func (mysql *MySql) Connect() {

	dsn := fmt.Sprintf("%s:%s@tcp(%s:%d)/%s?charset=%s&parseTime=True",
		mysql.Username,
		mysql.Password,
		mysql.Server,
		mysql.Port,
		mysql.Database,
		mysql.Charset,
	)

	connection, err := gorm.Open("mysql", dsn)

	if err != nil {
		panic(err)
	}

	connection.DB()
	err = connection.DB().Ping()

	if err != nil {
		panic(err)
	}

	connection.DB().SetMaxIdleConns(10)
	connection.DB().SetMaxOpenConns(100)
	connection.SingularTable(true)

	mysql.Connection = connection
}