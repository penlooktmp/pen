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

#include <app/command/output.h>

namespace app
{
	namespace command
	{
		Output::Output()
		{
			content = "";
			console = true;
		}
		
		Output::~Output()
		{
			// TODO
		}

		Output *Output::appendContent(string message)
		{
			this->content += message;
			return this;
		}

		string Output::getContent()
		{
			return this->content;
		}

		Output *Output::println(string message)
		{
			this->appendContent(message + "\n");
			if (this->isConsole()) {
				cout << message << endl;
				cout.flush();
			}
			return this;
		}
		
		bool Output::isConsole()
		{
			return this->console;
		}

		Output *Output::setConsole(bool console)
		{
			this->console = console;
			return this;
		}
	}
}