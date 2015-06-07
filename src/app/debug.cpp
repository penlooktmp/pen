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

#include <app/debug.h>
#include <sys/core.h>

const int Debug::CMD_BUFFER = 1024;

Debug::Debug()
{
	
}

Debug &Debug::addBuffer(char* buf)
{
	string buffer(buf);
	this->buffer = trimSpace(trimLine(buffer));
	this->bufferStack.push_back(this->buffer);
	return *this;
}

string Debug::getBuffer()
{
	return this->buffer;
}

void Debug::outputBuffer()
{
	cout << this->buffer << "\n";
}

vector<string> Debug::getBufferStack()
{
	return this->bufferStack;
}

bool Debug::isError()
{
	if (isMatch(this->buffer, "[a-zA-Z0-9/.]+:[0-9]+:[0-9]+:.*")) {
		this->response->body << this->getDebugInfo();
		return true;
	}
	return false;
}

bool Debug::isEnd()
{
	if (this->buffer == "Listening on port 8080") {
		this->response->body << getHttpContent("http://localhost:8080/");
		return true;
	}
	return false;
}

string Debug::getDebugInfo()
{	
	vector<string> com = split(this->buffer, ':');
	string file = com[0];
	string err = com[3];
	int line = stoi(com[1]);
	int col  = stoi(com[2]);
	return this->renderDebugInfo(file, line, col, err);
}

string Debug::renderDebugInfo(string file, int line, int col, string err)
{
	map<string, string> data;
	Template view;

	data["title"] = "12345";
	
	return  view.setPath(this->viewPath)
				.setView("debug/error")
				.setData(data)
				.render();
}

Debug &Debug::setResponse(http::Response* response)
{
	this->response = response;
	return *this;
}

Debug &Debug::setViewPath(string viewPath)
{
	this->viewPath = viewPath;
	return *this;
}

void Debug::compile()
{
	FILE *in = popen("./build.sh", "r");
	char buf[Debug::CMD_BUFFER];
	while (fgets(buf, sizeof(buf), in) != NULL) {
		this->addBuffer(buf);
		this->outputBuffer();
		if (this->isError()) {
			pclose(in);
			break;
		}
		if (this->isEnd()) {
			pclose(in);
			break;
		}
	}
}