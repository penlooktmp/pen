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
 	"reflect"
 	"github.com/julienschmidt/httprouter"
 	"strconv"
 	"encoding/json"
 	//"fmt"
)

func CastParamType(param string, typeName string) reflect.Value {
	switch typeName {
		case "int":
			arg, err := strconv.Atoi(param)
			if err != nil {
				arg = 0
			}
			return reflect.ValueOf(arg)
		case "string":
			arg := string(param)
			return reflect.ValueOf(arg)
		default:
			panic("Unsupported type ! " + typeName)
	}
}

func ReflectActionArgument(argumentString string, params httprouter.Params) []reflect.Value {

	var arguments Arguments

	if err := json.Unmarshal([]byte(argumentString), &arguments); err != nil {
        panic(err)
    }

	input := []reflect.Value {}

	for i:=0; i<len(arguments.Order); i++ {
		argumentName := arguments.Order[i]
		typeName := arguments.Type[argumentName]

		// Mapping action argument with request parameter
		param := params.ByName(argumentName)
		input = append(input, CastParamType(param, typeName))
	}

	return input
}