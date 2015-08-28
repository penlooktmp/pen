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

#ifndef APP_LANGUAGE_H_
#define APP_LANGUAGE_H_

#include <map>
#include <string>

using std::string;
using std::map;

#define LanguageList map<string, Language>

namespace app
{
	class Language
	{
		private:
			string name;
		public:
			// Constructor
			Language();
			Language(string name);
			// Name
			Language *setName(string name);
			string getName();
			// Word
			Language *setListLanguage(char** languages);
			char** getListLanguage();
	};
}

#endif