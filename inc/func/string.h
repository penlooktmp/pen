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

int    count(char **target);
char  *replace(const char *target, const char* find, const char* replace_with);
char **substr(char *target, int from, int to);
char **split(char* target, char* delimiter);
char  *join(char* target[], char* delimiter);
int    index_of(char* target, char* subtarget);
char  *trim(char* target);

#ifdef __cplusplus
}
#endif