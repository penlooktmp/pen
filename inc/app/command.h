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

#ifndef APP_COMMAND_H_
#define APP_COMMAND_H_

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sys/func.h>
#include <sys/type.h>
#include <app/command/input.h>
#include <app/command/output.h>

using std::string;
using std::map;

#define CommandList  map<string, Command*>

namespace app
{
	class Command
	{
		private:
			string name;
			string description;
			InputArgumentList arguments;
			InputOptionList options;
		public:
			// Constructor
			Command();
			// Destructor
			~Command();
			// Name
			Command *setName(string);
			string getName();
			// Description
			Command *setDescription(string);
			string getDescription();
			// Input Argument
			Command *addArgument(InputArgument*);
			InputArgumentList getArgumentList();
			// Input Option
			Command *addOption(InputOption*);
			InputOption *getOption(string);
			InputOptionList getOptionList();
			// Inheritance
			virtual void configure() {}
			virtual void execute(Input*, Output*) {}
	};

	class Cli
	{
		private:
			CommandList cmds;
		public:
			Cli();
			~Cli();
			// Command
			Cli *addCommand(Command*);
			Command *getCommand(string);
			CommandList getCommands();
			// Parse
			Cli *parse(int argc, char* argv[]);
	};
}

// Export
using app::Command;
using app::Cli;
#endif