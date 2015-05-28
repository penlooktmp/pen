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

#include <iostream>
#include <map>
#include <http/wpp.h>
#include <http/request.h>
#include <http/response.h>

using namespace std;

namespace http {
    class Http {
    private:
        Server server;
        HttpRequest request;
        HttpResponse response;
        
    public:
        // Self server
        void get(string, http_callback);
        void post(string, http_callback);
        void listen(int port = 80);
        
        // Handle from Nginx
        Http(HttpRequest, HttpResponse);
        HttpRequest getRequest();
        HttpResponse getResponse();
        void process();
    };

}