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

#ifndef APP_COMMAND_OUTPUT_H_
#define APP_COMMAND_OUTPUT_H_

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace app
{
	namespace command
	{
		class Output
		{
			private:
				string content;
			public:
				// Constructor
				Output();
				// Destructor
				~Output();
				// Content
				Output *appendContent(string content);
				string getContent();
				Output *println(string content);
		};
	}
}

using app::command::Output;

#endif