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

namespace app {
	
	Action *Action::setName(char *name)
	{
		this->name = name;
		return this;
	}

	char *Action::getName()
	{
		return this->name;
	}
	
	Action *Action::setData(action_data data)
	{
		this->data = data;
		return this;
	}
	
	action_data Action::getData()
	{
		return this->data;
	}
	
	Controller::Controller()
	{
		this->action = new Action;
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
	
	Controller *Controller::setAction(Action *action)
	{
		this->action = action;
		return this;
	}

	Action *Controller::getAction()
	{
		return this->action;
	}

	Controller::~Controller()
	{
		delete action;
	}
}