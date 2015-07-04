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

template <typename T> const int len(T&);
template <> const int len(char *&t);
template <> const int len(const char *&t);
template <> const int len(char **&t);
template <> const int len(int *&t);
template <> const int len(const int *&t);

#endif