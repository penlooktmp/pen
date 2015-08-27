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
#include <app/view.h>
#include <functional>
#include <stdexcept>
#include <vector>
#include <queue>
#include <map>

using std::map;
using std::function;
using std::string;
using std::queue;
using std::vector;

#define ListController map<string, Controller*>
#define ListAction map<string, Action*>
#define ListMapping map<string, vector<string>>
#define ActionData map<string, any>
#define ActionArgumentList queue<ActionArgument*>
#define ActionCallback function<void(Controller*)>
#define ViewCallback function<void(View*)>

namespace app
{
	class ActionArgument
	{
		private:
			string type;
			string variable;
		public:
			ActionArgument(string, string);
			// Type
			ActionArgument *setType(string);
			string getType();
			// Variable
			ActionArgument *setVariable(string);
			string getVariable();
	};

	class Action
	{
		private:
			string name;
			string hash;
			ActionData data;
			queue<ActionArgument*> args;
			ViewCallback viewCallback;
		public:
			// Name
			Action *setName(string);
			string getName();
			// Hash
			Action *setHash(string);
			string getHash();
			// Argument List
			Action *addArgument(ActionArgument*);
			ActionArgumentList getArguments();
			// Data
			Action *setData(ActionData);
			ActionData getData();
			// View Callback
			Action *setViewCallback(ViewCallback);
			ViewCallback getViewCallback();
	};

	class Controller
	{
		private:
			string name;
			string hash;
			Action *action;
			ListAction actions;
			View *view;
		public:
			Controller();
			~Controller();
			// Name
			Controller *setName(string);
			string getName();
			// Hash
			Controller *setHash(string);
			string getHash();
			// Current action
			Controller *setAction(Action*);
			Action *getAction();
			// Action management
			Controller *addAction(Action*);
			Action *getAction(string);
			ListAction getActions();
			// View
			Controller *setView(View*);
			View *getView();
			// Processor
			Controller *Before();
			Controller *After();
			Controller *Run(ActionCallback);
			Controller *Render();
	};
}

// Export
using app::Controller;
using app::Action;
#endif