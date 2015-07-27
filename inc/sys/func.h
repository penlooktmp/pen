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

#ifndef SYS_FUNC_H
#define SYS_FUNC_H

// C Interface
#ifdef __cplusplus
extern "C" {
#endif

#include <func/gen.h>
#include <func/strlib.h>
#include <func/cryptolib.h>

#ifdef __cplusplus
}
#endif

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sys/type.h>

using std::string;
using std::map;
using std::vector;

// GERNERIC FUNCTION TEMPLATE
#define LEN(TYPE); int len(TYPE);
#define STR(TYPE); char *str(TYPE);
#define SEG(TYPE); TYPE seg(TYPE, int, int);
#define SEG_CONST(TYPE); TYPE seg(const TYPE, int, int);
#define JOIN(TYPE); char *join(TYPE);
#define JOIN_DELIM(TYPE); char *join(TYPE, const char*);
#define ADD(TYPE); TYPE add(TYPE, const char*);
#define MD5(TYPE); char *md5(TYPE);

// LEN (Length)
// len(target)
// Use to retrive length of data type
int len(map<any, any>);
int len(vector<any>);
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

// STR (String - char pointer )
// str(target)
// Convert char pointer and number to string (char pointer)
STR(string);
STR(string*);
STR(char*);
STR(const char*);
STR(short);
STR(const short);
STR(int);
STR(const int);
STR(long);
STR(const long);
STR(double);
STR(const double);
STR(float);
STR(const float);

// ADD (Addition)
// add(target, append)
ADD(char**);

MD5(char*);
MD5(const char*);

// SEG (Segment)
// seg(target, left, right)
// Use to retrive segment of string or array from left to right
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

// JOIN (Join)
// join(target_array)
// join(target_array, delimiter)
// Use to join item in array with delimiter or not
JOIN(char**);
JOIN_DELIM(char**);
JOIN(short*);
JOIN_DELIM(short*);
JOIN(int*);
JOIN_DELIM(int*);
JOIN(long*);
JOIN_DELIM(long*);
JOIN(double*);
JOIN_DELIM(double*);
JOIN(float*);
JOIN_DELIM(float*);

#endif