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

namespace app {

	App::App()
	{
		this->request    = new HttpRequest();
		this->response   = new HttpResponse;
		this->controller = new Controller;
		this->view       = new View;
		this->model		 = new Model;
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

	App *App::setController(Controller *controller)
	{
		this->controller = controller;
		return this;
	}

	Controller *App::getController()
	{
		return this->controller;
	}

	App *App::setView(View *view)
	{
		this->view = view;
		return this;
	}

	View *App::getView()
	{
		return this->view;
	}

	App *App::setModel(Model *model)
	{
		this->model = model;
		return this;
	}
	
	Model *App::getModel()
	{
		return this->model;
	}
	
	App *App::handleCommand(char *command)
	{
		char **com = str_split(command, " ");
		// TODO
		// Append action argument
		this->getController()->setName(com[1])
				        	 ->getAction()->setName(com[2]);
		return this;
	}

	App *App::push(char* html)
	{
		return this;
	}

	App::~App()
	{
		delete request;
		delete response;
		delete router;
		delete controller;
		delete action;
		delete view;
		delete model;
	}
}