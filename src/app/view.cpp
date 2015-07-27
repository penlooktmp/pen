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

#include <app/view.h>

namespace app
{

	ViewData *ViewData::setValueHolder(ViewValueHolder valueHolder)
	{
		this->valueHolder = valueHolder;
		return this;
	}

	ViewValueHolder ViewData::getValueHolder()
	{
		return this->valueHolder;
	}

	View::View()
	{
		content = (char*) '\0';
		data = (ViewData*) malloc(sizeof(ViewData));
	}

	View::~View()
	{
		free(data);
	}

	View *View::setData(ViewData *data)
	{
		this->data = data;
	}

	ViewData *View::getData()
	{
		return this->data;
	}

	View *View::setContent(char *content)
	{
		this->content = content;
		return this;
	}

	View *View::appendContent(char *content)
	{
		char *data[] = {
			this->content,
			content
		};
		this->content = join((char**) data);
		return this;
	}

	char *View::getContent()
	{
		return this->content;
	}
}