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

template <typename T> const string typeof(T&) { return "unknown"; }
template<> const string typeof(int&) { return "int"; }
template<> const string typeof(short&) { return "short"; }
template<> const string typeof(long&) { return "long"; }
template<> const string typeof(unsigned&) { return "unsigned"; }
template<> const string typeof(unsigned short&) { return "unsigned short"; }
template<> const string typeof(unsigned long&) { return "unsigned long"; }
template<> const string typeof(float&) { return "float"; }
template<> const string typeof(double&) { return "double"; }
template<> const string typeof(long double&) { return "long double"; }
template<> const string typeof(string&) { return "string"; }
template<> const string typeof(map<string, string>&) { return "map"; }
template<> const string typeof(char&) { return "char"; }
template<> const string typeof(signed char&) { return "signed char"; }
template<> const string typeof(unsigned char&) { return "unsigned char"; }
template<> const string typeof(char*&) { return "char*"; }
template<> const string typeof(signed char*&) { return "signed char*"; }
template<> const string typeof(unsigned char*&) { return "unsigned char*"; }