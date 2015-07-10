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
		this->request    = new HttpRequest();
		this->response   = new HttpResponse;
		this->controller = new Controller;
		this->router     = new Router;
		this->view       = new View;
		this->model		 = new Model;
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

	App *App::setController(Controller *controller_)
	{
		memcpy(this->controller, controller_, sizeof(Controller));
		return this;
	}

	Controller *App::getController()
	{
		return this->controller;
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

	App *App::handleCommand(char *command)
	{
		// Controller Action [ArgumentType ArgumentValue ...]
		char **com = str_split(command, " ");
		char  *controllerName = com[0];
		char  *actionName = com[1];
		char **actionArgs = seg(com, 2, len(com) - 1);

		// Append action argument
		this->getController()->setName(controllerName)
				        	 ->getAction()
				        	 	->setName(actionName)
				        	 	->setArgument(actionArgs);
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
		delete view;
		delete model;
	}
}