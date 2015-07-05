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
#define SEG(TYPE); TYPE seg(TYPE t, int from, int to);
#define SEG_CONST(TYPE); TYPE seg(const TYPE t, int from, int to);

// LEN (Length)
// len(target)
// Use to retrive length of string or pointer
LEN(string);
LEN(string*);
LEN(char*);
LEN(const char*);
LEN(char**);
LEN(short);
LEN(const short);
LEN(short*);
LEN(int);
LEN(const int);
LEN(int*);
LEN(long);
LEN(const long);
LEN(long*);
LEN(double);
LEN(const double);
LEN(double*);
LEN(float);
LEN(const float);
LEN(float*);

// SEG (Segment)
// seg(target, from, to)
// Use to retrive segment of string or array
SEG(char*);
SEG_CONST(char*);
SEG(char**);
// SEG(int);
// SEG_CONST(int);
SEG(short*);
SEG(int*);
SEG(long*);
SEG(double*);
SEG(float*);

#endif