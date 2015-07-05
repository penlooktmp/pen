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

#define P_SEG(TYPE); \
		TYPE *seg(TYPE* t, int from, int to) {\
			return segment_pointer_##TYPE(t, from, to);\
		}
#define P_C_SEG(TYPE); \
		TYPE *seg(const TYPE* t, int from, int to) {\
			return segment_pointer_constant_##TYPE(t, from, to);\
		}
#define P_P_SEG(TYPE); \
		TYPE **seg(TYPE** t, int from, int to) {\
			return segment_pointer_pointer_##TYPE(t, from, to);\
		}

P_SEG(char);
P_C_SEG(char);
P_P_SEG(char);
P_SEG(int);
P_SEG(double);