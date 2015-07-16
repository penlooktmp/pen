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
using std::string;
using std::vector;

#define ListController map<string, Controller*>
#define ListAction map<string, Action*>
#define ListMapping map<string, vector<string>>
#define ActionData map<string, any>

namespace app
{
	class ActionArgument
	{
		private:
			string type;
			string variable;
		public:
			ActionArgument(string, string);
			ActionArgument *setType(string);
			string getType();
			ActionArgument *setVariable(string);
			string getVariable();
	};

	class Action
	{
		private:
			string name;
			string hash;
			ActionData data;
			vector<ActionArgument*> args;
		public:
			Action *setName(string);
			string getName();
			Action *setHash(string);
			string getHash();
			Action *addArgument(ActionArgument*);
			vector<ActionArgument*> getArguments();
			Action *setData(ActionData);
			ActionData getData();
	};

	class Controller
	{
		private:
			string name;
			ListAction actions;

		public:
			Controller();
			~Controller();

			Controller *setName(string);
			string getName();

			// Action
			Controller *addAction(Action*);
			Action *getAction();
			Action *getAction(string);
			ListAction getActions();

		protected:
			void Before();
			void After();
	};
}

#endif