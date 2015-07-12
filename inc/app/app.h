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

#ifndef APP_APP_H_
#define APP_APP_H_

#include <http/request.h>
#include <http/response.h>
#include <app/controller.h>
#include <app/model.h>
#include <app/view.h>
#include <app/router.h>
#include <app/storage.h>
#include <sys/func.h>
#include <functional>
#include <cstring>
#include <map>

using namespace http;
using std::string;

namespace app
{
	class App 
	{
		private:
			HttpRequest    *request;
			HttpResponse   *response;
			Router         *router;
			Storage        *storage;
			Controller     *controller;
			ListController controllers;
			View           *view;
			Model          *model;
			string          hash;

		public:
			// Application
			App();
			~App();

			// Http Request
			App *setHttpRequest(HttpRequest*);
			HttpRequest *getHttpRequest();

			// Http Response
			App *setHttpResponse(HttpResponse*);
			HttpResponse *getHttpResponse();

			// Router
			App *setRouter(Router*);
			Router *getRouter();

			// Storage
			App *setStorage(Storage*);
			Storage *getStorage();

			// Controller
			App *setControllers(ListController);
			ListController getControllers();

			// Model
			App *setModel(Model*);
			Model *getModel();

			// View
			App *setView(View*);
			View *getView();

			// Hash
			App *setHash(string);
			string getHash();

			// Processor
			App *handleRequest(char*, function<void(HttpRequest*, HttpResponse*)> callback);
	};

	// Dependency injection
	void boot(Storage*);
	void handler(App*);

}

#endif