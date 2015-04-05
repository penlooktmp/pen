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
package lib

import (
  	"os"
  	"strings"
)

type Data map[string] interface{}

type Generate struct {}

func (gen Generate) Clean(path string) {
	err := os.Remove(path)
	if err != nil {
	  	return
	}
}

func (gen Generate) Write(template string, path string) {
	if _, err := os.Stat(path); os.IsNotExist(err) {
    	os.Create(path)
	}
	file, err := os.OpenFile(path, os.O_APPEND, 0666)
	defer file.Close()
	if err != nil {
		panic(err)
	}
	file.WriteString(template)
}

func (gen Generate) Replace(template string, variable string, content string) string {
	variable = "{{ " + variable + " }}"
	template = strings.Replace(template, variable, content, -1)
	return template
}

func (gen Generate) Schema() {
}

func (gen Generate) Extend() {
}

func (gen Generate) Main(template string, path string, data Data) {
	gen.Clean(path)
	template = gen.Replace(template, "router", `
		ABCDEF
	`)
	gen.Write(template, path)
}