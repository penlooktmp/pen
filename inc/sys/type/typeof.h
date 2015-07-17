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

#ifndef SYS_TYPE_TYPEOF_H
#define SYS_TYPE_TYPEOF_H

#include <string>
#include <map>
#include <vector>
#include "any.h"

using std::string;
using std::map;
using std::vector;

template <typename T> const string typeof(T&);
template<> const string typeof(any&);
template<> const string typeof(int&);
template<> const string typeof(int*&);
template<> const string typeof(short&);
template<> const string typeof(short*&);
template<> const string typeof(long&);
template<> const string typeof(long*&);
template<> const string typeof(unsigned&);
template<> const string typeof(unsigned*&);
template<> const string typeof(unsigned short&);
template<> const string typeof(unsigned short*&);
template<> const string typeof(unsigned long&);
template<> const string typeof(unsigned long*&);
template<> const string typeof(float&);
template<> const string typeof(float*&);
template<> const string typeof(double&);
template<> const string typeof(double*&);
template<> const string typeof(long double&);
template<> const string typeof(long double*&);
template<> const string typeof(string&);
template<> const string typeof(string*&);
template<> const string typeof(char&);
template<> const string typeof(signed char&);
template<> const string typeof(unsigned char&);
template<> const string typeof(char*&);
template<> const string typeof(signed char*&);
template<> const string typeof(unsigned char*&);
template<> const string typeof(char**&);
template<> const string typeof(signed char**&);
template<> const string typeof(unsigned char**&);

#endif