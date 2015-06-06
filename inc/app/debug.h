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

#include <sys/core.h>
#include <http/http.h>

class Debug
{
	static const int CMD_BUFFER;

	private:
		string buffer;
		vector<string> bufferStack;
		bool breakPoint;
		http::Response* response;

	public:
		Debug();
		Debug &addBuffer(char*);
		string getBuffer();
		void outputBuffer();
		vector<string> getBufferStack();
		string getDebugInfo();
		string renderDebugInfo(string, int , int, string);
		void setResponse(http::Response*);
		void compile();
		bool isError();
		bool isEnd();
};