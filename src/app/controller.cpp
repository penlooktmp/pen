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
	Action *Action::setName(char *name_)
	{
		this->name = name_;
		return this;
	}

	char *Action::getName()
	{
		return this->name;
	}

	Action *Action::setData(ActionData data_)
	{
		this->data = data_;
		return this;
	}
	
	ActionData Action::getData()
	{
		return this->data;
	}

	Action *Action::setArgument(ActionArg args_)
	{
		this->args = args_;
		return this;
	}
	
	ActionArg Action::getArgument()
	{
		return this->args;
	}

	Controller::Controller()
	{
		// TODO
	}

	Controller *Controller::setName(char *name)
	{
		this->name = name;
		return this;
	}

	char *Controller::getName()
	{
		return this->name;
	}

	Controller *Controller::addAction(Action *action_)
	{
		char *actionName = action_->getName();
		this->actions[actionName] = action_;
		return this;
	}

	Action *Controller::getAction(char *actionName)
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