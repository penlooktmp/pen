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

#include <cli/cmd.h>
#include <sys/core.h>

namespace cli
{
	
	Cmd::Cmd(int _argc, char* _argv[])
	{
		argc = _argc;
		argv = _argv;
	}
	
	Cmd &Cmd::addOption(string name, string desc, cli_callback func)
	{
		Option option;
		option.setName(name)
			  .setDescription(desc)
			  .setCallback(func);
		options[name] = option;
		return *this;
	}
	
	void Cmd::runOption(string name, string param = "")
	{
		if (options.find(name) == options.end()) {
			runOption("help");
			return;
		}
		Option option = options[name];
		cli_callback callback = option.getCallback();
		callback(param);
	}

	void Cmd::run()
	{
		if (argc < 2) {
			runOption("help");
			return;
		}	
		string name  = argv[1];
		if (argc == 3) {
			runOption(name, argv[2]);
			return;
		}
		runOption(name);
	}
	
}