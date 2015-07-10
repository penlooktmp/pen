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

#include <sys/type.h>
#include <sys/func.h>
#include <functional>
#include <vector>
#include <map>

using std::map;
using std::function;

#define ListController map<char*, Controller*>
#define ListAction map<char*, Action*>
#define ActionArg char**
#define ActionData map<const char*, any>

namespace app
{
	class Action
	{
		private:
			char *name;
			char *hash;
			ActionArg args;
			ActionData data;
		public:
			Action *setName(char*);
			char *getName();
			Action *setHash(char*);
			char *getHash();
			Action *setArgument(ActionArg args);
			ActionArg getArgument();
			Action *setData(ActionData data);
			ActionData getData();
	};

	class Controller
	{
		private:
			char *name;
			ListAction actions;

		public:
			Controller();
			~Controller();

			Controller *setName(char*);
			char *getName();

			// Action
			Controller *addAction(Action*);
			Action *getAction();
			Action *getAction(char*);
			ListAction getActions();

		protected:
			void Before();
			void After();
	};
}

#endif