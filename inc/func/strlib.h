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

#ifndef FUNC_STRING_H_
#define FUNC_STRING_H_

#include <func/gen/len.h>

char  *str_replace(const char *target, const char *find, const char *replace_with);
char **str_substr(char *target, int from, int to);
char **str_split(char *target, const char *delim);
char **str_slice(char **target, const char *flag);
char  *str_join(char **target, char const *delim);
int    str_index(char *target, char *subtarget);
char  *str_trim(char *target);
int   *str_match(char **target, char *regex);

#endif