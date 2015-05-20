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

#include "cli/handler.h"
#include "cli/cli.h"

int main(int argc, char* argv[]) {
	Handler cmd;
	Cli pengo = Cli(argc, argv);
	pengo.add("new",   "Create new application", 
			(cli_callback) cmd.create)
		 .add("run",   "Run app under hot-code reload", 
		 	(cli_callback) cmd.run)
		 .add("build", "Build app for production mode",
		 	(cli_callback) cmd.build)
		 .add("debug", "Debug application components",
		 	(cli_callback) cmd.debug)
		 .add("test",  "Run unit or benchmark testing",
		 	(cli_callback) cmd.test)
		 .add("help", "Pengo help !",
		 	(cli_callback) cmd.help)
		 .run();
	return 0;
}