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

#include <app/controller.h>

namespace app 
{
	ActionArgument::ActionArgument(string type, string variable)
	{
		this->type = type;
		this->variable = variable;
	}

	ActionArgument *ActionArgument::setType(string type)
	{
		this->type = type;
		return this;
	}

	string ActionArgument::getType()
	{
		return this->type;
	}
	
	ActionArgument *ActionArgument::setVariable(string variable)
	{
		this->variable = variable;
		return this;
	}

	string ActionArgument::getVariable()
	{
		return this->variable;
	}

	Action *Action::setName(string name)
	{
		this->name = name;
		return this;
	}

	string Action::getName()
	{
		return this->name;
	}

	Action *Action::setData(ActionData data)
	{
		this->data = data;
		return this;
	}
	
	ActionData Action::getData()
	{
		return this->data;
	}

	Action *Action::addArgument(ActionArgument *arg)
	{
		this->args.push_back(arg);
		return this;
	}
	
	vector<ActionArgument*> Action::getArguments()
	{
		return this->args;
	}
	
	Action *Action::setHash(string hash)
	{
		this->hash = hash;
		return this;
	}

	string Action::getHash()
	{
		return this->hash;
	}

	Controller::Controller()
	{
		// TODO
	}

	Controller *Controller::setName(string name)
	{
		this->name = name;
		return this;
	}

	string Controller::getName()
	{
		return this->name;
	}

	Controller *Controller::addAction(Action *action)
	{
		string actionName = action->getName();
		this->actions[actionName] = action;
		return this;
	}

	Action *Controller::getAction(string actionName)
	{
		return this->actions[actionName];
	}
	
	ListAction Controller::getActions()
	{
		return this->actions;
	}

	Controller::~Controller()
	{
		// TODO
	}
}