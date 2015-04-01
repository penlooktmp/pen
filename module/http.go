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
	"net/http"
)

type Http struct {
	Request *http.Request
	Response http.ResponseWriter
}

func (http Http) GET(key string) string {
	return "GET"
}

func (http Http) POST(key string) string {
	return "POST"
}

func (http Http) PUT(key string) string {
	return "PUT"
}

func (http Http) PATCH(key string) string {
	return "PATCH"
}

func (http Http) DELETE(key string) string {
	return "DELETE"
}