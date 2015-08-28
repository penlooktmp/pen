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
#include <app/command/parser.h>

namespace app
{
	Command::Command()
	{
		this->addOption((new InputOption())
			->setName("env")
			->setAlias('e')
			->setDescription("Environment type")
			->setDefault("prod")
			->setRequired(false)
		);
	}
	
	Command::~Command()
	{
		clear(options);
		clear(arguments);
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
	
	Command *Command::addArgument(InputArgument *argument)
	{
		this->arguments.push_back(argument);
		return this;
	}

	InputArgumentList Command::getArgumentList()
	{
		return this->arguments;
	}

	Command *Command::addOption(InputOption *option)
	{
		this->options[option->getName()] = option;
		return this;
	}
	
	InputOption *Command::getOption(string name)
	{
		return this->options[name];
	}

	InputOptionList Command::getOptionList()
	{
		return this->options;
	}

	Cli::Cli()
	{
		// TODO
	}
	
	Cli::~Cli()
	{
		for (auto it : this->cmds) {
			delete it.second;
		}
	}
	
	Cli *Cli::addCommand(Command *command)
	{
		command->configure();
		this->cmds[command->getName()] = command;
		return this;
	}
	
	Command *Cli::getCommand(string name)
	{
		return this->cmds[name];
	}

	CommandList Cli::getCommands()
	{
		return this->cmds;
	}
	
	Cli *Cli::parse(int argc, char* argv[])
	{
		// Ignore first argument
		argv = seg(argv, 1, argc--);

		// Could not find suitable command
		if (this->cmds.find(argv[0]) == this->cmds.end()) {
			cout << "Error: command not found !" << endl;
			return this;
		}
		
		// Retreive input option from command configuration
		Command *command = this->cmds[argv[0]];
		InputOptionList options = command->getOptionList();
		
		Parser parser;
		InputOption *option;
		for (auto it : options) {
			option = it.second;
			parser.add<string>(
				option->getName(),
				option->getAlias(),
				option->getDescription()
			);
			cout << "ADDED" << option->getName() << "\n\n";
			cout.flush();
		}
		
		parser.parse_check(argc, argv);
		return this;
	}
}