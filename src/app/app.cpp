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

#include <app/app.h>

namespace app
{
	App::App()
	{
		request  = nullptr;
		response = nullptr;
		router   = nullptr;
		storage  = nullptr;
	}

	App::~App()
	{
		clear(request);
		clear(response);
		clear(router);
		// Do not delele storage
		// clear(storage);
	}

	App *App::setHttpRequest(HttpRequest *request)
	{
		this->request = request;
		return this;
	}

	HttpRequest *App::getHttpRequest()
	{
		return this->request;
	}

	App *App::setHttpResponse(HttpResponse *response)
	{
		this->response = response;
		return this;
	}

	HttpResponse *App::getHttpResponse()
	{
		return this->response;
	}

	App *App::setRouter(Router *router)
	{
		this->router = router;
		return this;
	}

	Router *App::getRouter()
	{
		return this->router;
	}

	App *App::setStorage(Storage *storage)
	{
		this->storage = storage;
		return this;
	}

	Storage *App::getStorage()
	{
		return this->storage;
	}

	ControllerList App::getControllers()
	{
		return this->getStorage()->getControllers();
	}

	Controller *App::getController()
	{
		MappingList mapping = this->getStorage()->getMappingList();
		MappingList::iterator it = mapping.find(this->getHash());
		if (it != mapping.end()) {
			vector<string> com = it->second;
			string controllerName = com[0];
			Controller *controller = this->getControllers()[controllerName];
			controller->setHash(this->getHash());
			return controller;
		}
		return NULL;
	}

	Action *App::getAction()
	{
		Controller *controller = this->getController();
		if (instanceof<Controller*>(controller)) {
			return controller->getAction();
		}
		return NULL;
	}

	App *App::setHash(string hash)
	{
		this->hash = hash;
		return this;
	}

	string App::getHash()
	{
		return this->hash;
	}
}