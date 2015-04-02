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
	//"fmt"
	goredis "github.com/penlook/redis/redis"
)

type Redis struct {
	Name       string
	Server     string
	Do         func(cmd string, args ...interface{}) (interface{}, error)
	connection goredis.Conn
}

// Get server
func (redis Redis) GetServer() string {
	return redis.Server
}

// Set connection
func (redis *Redis) SetConnection(connection goredis.Conn, err error) {

	if err != nil {
		panic(err)
	}

	redis.connection = connection

	// Alias function
	redis.Do = redis.connection.Do
}

// Establish new connection
func (redis Redis) Connect() Redis {
	redis.SetConnection(goredis.Dial("tcp", redis.GetServer()))
	return redis
}

// Close connection
func (redis Redis) Close() {
	redis.connection.Close()
}