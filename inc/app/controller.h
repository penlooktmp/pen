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

#ifndef APP_CONTROLLER_H_
#define APP_CONTROLLER_H_

#include <map>
#include <functional>

using std::map;
using std::function;

#define action_arg map<char*, char*>
#define action_data map<const char*, char*>

namespace app {
	
	class Action {
		private:
			char *name;
			action_arg args;
			action_data data;
		public:
			Action *setName(char*);
			char *getName();
			Action *setArgument(action_arg args);
			action_arg getArgument();
			Action *setData(action_data data);
			action_data getData();
	};

	class Controller {
		private:
			char *name;
			Action *action;
		public:
			Controller();
			~Controller();
			Controller *setName(char*);
			char *getName();
			Controller *setAction(Action*);
			Action *getAction();
			
	};
}

#endif