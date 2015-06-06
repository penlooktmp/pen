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

#include <app/toolbar.h>

Debug::Debug()
{
	
}

Debug &Debug::addBuffer(string buffer)
{
	buffer = trimSpace(trimLine(buffer));
	this->bufferStack.push_back(buffer);
	return *this;
}

string Debug::getBuffer()
{
	int bufferStackSize = this->bufferStack.size();
	return (bufferStackSize == 0) ? " " : this->bufferStack[bufferStackSize - 1];
}

vector<string> Debug::getBufferStack()
{
	return this->bufferStack;
}

bool Debug::isError(string buffer)
{
	string listErrorPattern = {
		"[a-zA-Z0-9/.]+:[0-9]+:[0-9]+:.*"
	};
	
	return true;
}

bool Debug::isBreakPoint()
{
	return this->breakPoint;
}

string Debug::getDebugInfo()
{
	return "<html>Error in line 104</html>";
}

void Debug::compile()
{
	FILE *in;
	char buf[1024];
	
	if (!(in = popen("./build.sh", "r"))) {
		return;
	}

	while (fgets(buf, sizeof(buf), in) != NULL) {
		string buffer(buf);
		debug.addBuffer(buffer);
		buffer = trimSpace(trimLine(buffer));
		cout << buffer << "\n";

		if (isMatch(buffer, "[a-zA-Z0-9/.]+:[0-9]+:[0-9]+:.*")) {
			_response->body << buffer;
			pclose(in);
			break;
		}
		
		if (buffer == "Listening on port 8080") {
			_response->body << getHttpContent("http://localhost:8080/");
			pclose(in);
			break;
		}
	}
}