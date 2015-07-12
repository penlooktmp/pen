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
		request    = new HttpRequest;
		response   = new HttpResponse;
		controller = new Controller;
		router     = new Router;
		storage    = new Storage;
		view       = new View;
		model	   = new Model;
	}
	
	App::~App()
	{
		delete request;
		delete response;
		delete controller;
		delete router;
		delete storage;
		delete view;
		delete model;
	}

	App *App::setHttpRequest(HttpRequest *request_)
	{
		memcpy(this->request, request_, sizeof(HttpRequest));
		return this;
	}

	HttpRequest *App::getHttpRequest()
	{
		return this->request;
	}

	App *App::setHttpResponse(HttpResponse *response_)
	{
		memcpy(this->response, response_, sizeof(HttpResponse));
		return this;
	}

	HttpResponse *App::getHttpResponse()
	{
		return this->response;
	}

	App *App::setRouter(Router *router_)
	{
		memcpy(this->router, router_, sizeof(Router));
		return this;
	}

	Router *App::getRouter()
	{
		return this->router;
	}

	App *App::setStorage(Storage *storage_)
	{
		memcpy(this->storage, storage_, sizeof(Storage));
		return this;
	}

	Storage *App::getStorage()
	{
		return this->storage;
	}

	App *App::setControllers(ListController controllers_)
	{
		this->controllers = controllers_;
		return this;
	}

	ListController App::getControllers()
	{
		return this->controllers;
	}

	App *App::setView(View *view_)
	{
		memcpy(this->view, view_, sizeof(View));
		return this;
	}

	View *App::getView()
	{
		return this->view;
	}

	App *App::setModel(Model *model_)
	{
		memcpy(this->model, model_, sizeof(Model));
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