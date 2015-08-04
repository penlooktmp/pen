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

#include <app/command.h>

namespace app
{
	Command::Command()
	{
		// TODO
	}
	
	Command::~Command()
	{
		// TODO
	}

	Command *Command::setName(string name)
	{
		this->name = name;
		return this;
	}
	
	string Command::getName()
	{
		return this->name;
	}

	Command *Command::setDescription(string description)
	{
		this->description = description;
		return this;
	}
	
	string Command::getDescription()
	{
		return this->description;
	}
	
	Command *Command::addArgument(string name, string description)
	{
		InputArgument *arg = new InputArgument();
		arg ->setName(name)
			->setDescription(description);
		this->arguments.push_back(arg);
		return this;
	}

	ArgumentList Command::getArguments()
	{
		return this->arguments;
	}

	Command *Command::addOption(string name, string description, int inputFlag, string value)
	{
		InputOption *option = new InputOption();
		option ->setName(name)
			   ->setDescription(description)
			   ->setFlag(inputFlag)
			   ->setDefault(value);
		this->options.push_back(option);
		return this;
	}

	OptionList Command::getOptions()
	{
		return this->options;
	}
}