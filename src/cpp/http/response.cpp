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
 
#include <http/response.h>

namespace http {

	HttpResponse &HttpResponse::setBody(char* body)
	{
		this->body = body;
		return *this;
	}

	char* HttpResponse::getBody()
	{
		return body;
	}

	HttpResponse &HttpResponse::setBodyLength(int length)
	{
		this->body_length = length;
		return *this;
	}
	
	int HttpResponse::getBodyLength()
	{
		return body_length;
	}
}