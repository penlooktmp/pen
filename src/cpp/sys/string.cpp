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

#include <sys/core.h>

string trimLine(string str)
{
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
	return str;
}

string trimSpace(string str)
{
	str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
	str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
	return str;
}

bool isMatch(string test, string pattern)
{	
	regex str(pattern);
	if (regex_match(test, str)) {
		return true;
	}
	return false;
}

int indexOf(string str_origin, string str_find)
{
	static string::size_type loc = str_origin.find(str_find, 0);
	if (loc != string::npos) {
		return (int) loc;
	}
	return -1;
}

vector<string> split(string str, char delim)
{
    vector<string> result;
    istringstream iss(str);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}