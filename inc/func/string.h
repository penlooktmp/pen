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

#ifndef FUNC_STRING_H
#define FUNC_STRING_H

// C Interface
#ifdef __cplusplus
extern "C" {
#endif
int    count(char **target);
char  *replace(const char *target, const char *find, const char *replace_with);
char **substr(char *target, int from, int to);
char **split(char *target, const char *delim);
char **slice(char **target, const char *flag);
char  *join(char **target, char const *delim);
int    index(char *target, char *subtarget);
char  *trim(char *target);
int   *match(char **target, char *regex);
#ifdef __cplusplus
}
#endif
#endif