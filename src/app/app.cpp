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
		request  = (HttpRequest*)   malloc(sizeof(HttpRequest));
		response = (HttpResponse*)  malloc(sizeof(HttpResponse));
		router   = (Router*)        malloc(sizeof(Router));
		storage  = (Storage*)       malloc(sizeof(Storage));
		view     = (View*)          malloc(sizeof(View));
		model	 = (Model*)         malloc(sizeof(Model));
	}

	App::~App()
	{
		free(request);
		free(response);
		free(router);
		free(storage);
		free(view);
		free(model);
	}

	App *App::setHttpRequest(HttpRequest *request)
	{
		memcpy(this->request, request, sizeof(HttpRequest));
		return this;
	}

	HttpRequest *App::getHttpRequest()
	{
		return this->request;
	}

	App *App::setHttpResponse(HttpResponse *response)
	{
		memcpy(this->response, response, sizeof(HttpResponse));
		return this;
	}

	HttpResponse *App::getHttpResponse()
	{
		return this->response;
	}

	App *App::setRouter(Router *router)
	{
		memcpy(this->router, router, sizeof(Router));
		return this;
	}

	Router *App::getRouter()
	{
		return this->router;
	}

	App *App::setStorage(Storage *storage)
	{
		memcpy(this->storage, storage, sizeof(Storage));
		return this;
	}

	Storage *App::getStorage()
	{
		return this->storage;
	}

	ListController App::getControllers()
	{
		return this->getStorage()->getControllers();
	}

	Controller *App::getController()
	{
		ListMapping mapping = this->getStorage()->getListMapping();
		ListMapping::iterator it = mapping.find(this->getHash());
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
		if (controller->getName() != "Unknown") {
			return controller->getAction();
		}
		return NULL;
	}

	App *App::setView(View *view)
	{
		memcpy(this->view, view, sizeof(View));
		return this;
	}

	View *App::getView()
	{
		return this->view;
	}

	App *App::setModel(Model *model)
	{
		memcpy(this->model, model, sizeof(Model));
		return this;
	}

	Model *App::getModel()
	{
		return this->model;
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