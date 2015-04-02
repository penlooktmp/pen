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
	"github.com/penlook/mgo"
)

type Mongo struct {
	Name     string
	Server   []string
	connection *mgo.Session
}

// JSON Format for input data
type Json map[string]interface {}

// MongoDB Database
type Database struct {
	*mgo.Database
}

// MongoDB Collection
type Collection struct {
	*mgo.Collection
}

// Get multiple servers IP & Port
func (mongo Mongo) getServers() string {
	servers := ""
	for _, server := range mongo.Server {
		servers += server + ","
	}
	return servers
}

// Set connection
func (mongo *Mongo) SetConnection(connection *mgo.Session) {
	mongo.connection = connection
}

// Get connection
func (mongo Mongo) GetConnection() *mgo.Session{
	return mongo.connection
}

// Establish new connection
func (mongo Mongo) Connect() Mongo {
	connection, err := mgo.Dial(mongo.getServers())

	if err != nil {
		panic(err)
	}

	mongo.SetConnection(connection)
	mongo.connection.SetMode(mgo.Monotonic, true)
	return mongo
}

// Close connection
func (mongo Mongo) Close() {
	mongo.GetConnection().Close()
}

// Choose database
func (mongo Mongo) Database(name string) Database {
	database := Database{mongo.connection.DB(name)}
	return database
}

// Choose collection
func (db Database) Collection(name string) Collection {
	collection := Collection{db.C(name)}
	return collection
}