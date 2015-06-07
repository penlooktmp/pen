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

#include <view/template.h>

Template &Template::setPath(string path)
{
	this->path = path;
	return *this;
}

Template &Template::setView(string view)
{
	this->view = view;
	return *this;
}

Template &Template::setData(map<string, string> data)
{
	this->data = data;
	return *this;
}

string Template::render()
{
	string voltPath = this->path + "/" + this->view + ".html";
	string line, content;
	ifstream voltFile(voltPath);
	
	if (voltFile.is_open())
	{
		while (getline (voltFile, line) )
		{
			content += line;
		}
		voltFile.close();
	} else content = "Unable to open file";

	return content;
}