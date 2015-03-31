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
)

type Table struct {
	Name string
	Driver interface {}
}

func (table *Table) SetDriver(driver interface {}) {
	table.Driver = driver
}

func (table Table) Find() {
	var deleted_users []User
	db.Table("user").Find(&deleted_users)
}

func (table Table) First() {}
func (table Table) Delete() {}


// Column family
// SQLite
// MySQL
// SQLServer
// Oracle
// Cassandra
// HBase