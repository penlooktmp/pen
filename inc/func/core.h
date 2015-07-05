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

#ifndef FUNC_CORE_H
#define FUNC_CORE_H

// C Interface
#ifdef __cplusplus
extern "C" {
#endif

#include "func.h"
#include "string.h"
#include "number.h"

#ifdef __cplusplus
}
#endif

#include <iostream>
using namespace std;

// GENERIC FUNCTION

#define LEN(TYPE); int len(TYPE t);
#define SUB(TYPE); TYPE sub(TYPE t, int from, int to);

// len(pointer)
LEN(char*);
LEN(const char*);
LEN(char**);
LEN(string);
LEN(int);
LEN(int*);
LEN(const int*);

// sub(pointer, from, to)
SUB(char*);
SUB(const char*);
SUB(char**);
SUB(int*);
SUB(const int*);

#endif