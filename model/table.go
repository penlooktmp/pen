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