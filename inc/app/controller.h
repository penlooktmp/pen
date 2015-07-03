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

#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include <map>
#include <iostream>

using namespace std;

namespace app {
	
	class Action {
		private:
			string name;
			map<string, string> args;
			map<string, string> data;
		public:
			Action &setName(string);
			string getName();
			Action &setArgument(map<string, string> args);
			map<string, string> getArgument();
			Action &setData(map<string, string> data);
			map<string, string> getData();
	};

	class Controller {
		private:
			string name;
			Action action;
		public:
			Controller &setName(string);
			string getName();
			Controller &setAction(Action);
			Action getAction();
	};

}

#endif