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

#include "cli.hpp"

int main(int argc, char *argv[])
{
	Cli pengo;
	pengo.setName("pengo")
		 .addOption<string>("new", 'n', "Create application", false, "")
		 .addOption("run", '\0', "Run application under hot-code reload")
		 .addOption<string>("build", 'b', "Build and install application", false)
		 .addOption<string>("test", 't', "Test application", false, "unit", 
								cmdline::oneof<string>("unit", "benchmark"))
		 .addOption("help", 0, "Show pengo help");
	return 0;
}