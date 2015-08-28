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

#ifndef APP_COMMAND_CLI_H_
#define APP_COMMAND_CLI_H_

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace app
{
	namespace command
	{
		class Cli
		{
			private:
				string name;
				string description;
				string value;
				string defaultValue;
				int    mode;
			public:
				// Mode
				const static int OPTIONAL;
				const static int REQUIRED;
				// Name
				InputArgument *setName(string);
				string getName();
				// Description
				InputArgument *setDescription(string);
				string getDescription();
				// Value
				InputArgument *setValue(string);
				string getValue();
				// Default
				InputArgument *setDefault(string);
				string getDefault();
				// Mode
				InputArgument *setMode(int);
				int getMode();
		};
	}
}

// Export
using app::command::Cli;

#endif