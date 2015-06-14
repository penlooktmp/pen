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

#include <http/http.h>

namespace http {

    Http::Http(HttpRequest request, HttpResponse response)
    {
        this->request = request;
        this->response = response;
        this->response.body = "";
    }

    Http Http::setRequest(HttpRequest request)
    {
        this->request = request;
        return *this;
    }

    HttpRequest Http::getRequest()
    {
        return this->request;
    }

    Http Http::setResponse(HttpResponse response)
    {
        this->response = response;
        return *this;
    }

    HttpResponse Http::getResponse()
    {
        return this->response;
    }

    Http Http::serveRequest(function<void(App*)> app_callback)
    {
        App app;
        app.setHttpRequest(this->getRequest())
           .setHttpResponse(this->getResponse());
        app_callback(&app);
        this->response.body = App::out.str();
        return *this;
    }

    void Http::get(string router, http_callback callback)
    {
        server.get(router, callback);
    }

    void Http::post(string router, http_callback callback)
    {
        server.get(router, callback);
    }

    void Http::listen(int port)
    {
        try {
            cout << "Listening on port " << port << endl;
            server.start(port);
        } catch(Exception e) {
            cerr << "WebServer: " << e.what() << endl;
        }
    }

}