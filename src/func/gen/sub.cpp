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

#ifdef __cplusplus
extern "C" {
#endif
#include <func/func.h>
#ifdef __cplusplus
}
#endif

#define P_SUB(TYPE); \
		TYPE *sub(TYPE* t, int from, int to) {\
			return sub_pointer_##TYPE(t, from, to);\
		}
#define P_P_SUB(TYPE); \
		TYPE **sub(TYPE** t, int from, int to) {\
			return sub_pointer_pointer_##TYPE(t, from, to);\
		}

P_SUB(char);
P_P_SUB(char);
P_SUB(int);
P_SUB(double);