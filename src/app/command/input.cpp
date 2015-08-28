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

#include <app/command/input.h>

namespace app
{
	namespace command
	{
		InputArgument *InputArgument::setName(string name)
		{
			this->name = name;
			return this;
		}
		
		string InputArgument::getName()
		{
			return this->name;
		}
		
		InputArgument *InputArgument::setDescription(string description)
		{
			this->description = description;
			return this;
		}
		
		string InputArgument::getDescription()
		{
			return this->description;
		}
		
		InputArgument *InputArgument::setValue(string value)
		{
			this->value = value;
			return this;
		}

		string InputArgument::getValue()
		{
			return this->value;
		}
		
		InputArgument *InputArgument::setDefault(string defaultValue)
		{
			this->defaultValue = defaultValue;
			return this;
		}

		string InputArgument::getDefault()
		{
			return this->defaultValue;
		}
		
		InputArgument *InputArgument::setMode(int mode)
		{
			this->mode = mode;
			return this;
		}

		int InputArgument::getMode()
		{
			return this->mode;
		}

		const int InputOption::OPTIONAL   = 0;
		const int InputOption::REQUIRED   = 1;
		const int InputOption::VALUE_NONE = 2;

		InputOption *InputOption::setName(string name)
		{
			this->name = name;
			return this;
		}

		string InputOption::getName()
		{
			return this->name;
		}

		InputOption *InputOption::setDescription(string description)
		{
			this->description = description;
			return this;
		}

		string InputOption::getDescription()
		{
			return this->description;
		}
		
		InputOption *InputOption::setValue(string value)
		{
			this->value = value;
			return this;
		}

		string InputOption::getValue()
		{
			return this->value;
		}
		
		InputOption *InputOption::setDefault(string defaultValue)
		{
			this->defaultValue = defaultValue;
			return this;
		}

		string InputOption::getDefault()
		{
			return this->defaultValue;
		}

		InputOption *InputOption::setMode(int mode)
		{
			this->mode = mode;
			return this;
		}

		int InputOption::getMode()
		{
			return this->mode;
		}
		
		/*
		Input *Input::setOption(InputOption *option)
		{
			this->options.push_back()
		}

		InputOption *Input::getOption(string optionName)
		{
			return NULL;
		}

		vector<InputOption*> Input::getOptions()
		{
			vector<InputOption*> sample;
			return sample;
		}

		InputArgument *Input::getArgument(string name)
		{
			return NULL;
		}

		vector<InputArgument*> Input::getArguments()
		{
			vector<InputArgument*> sample;
			return sample;
		}*/
	}
}