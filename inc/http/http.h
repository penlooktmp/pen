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

#ifndef HTTP_H
#define HTTP_H

#include <http/wpp.h>
#include <app/app.h>

using namespace app;

namespace http {
    class Http {
    private:
        Server *server;
        HttpRequest *request;
        HttpResponse *response;
        Storage *storage;
        char *hash;

    public:
        Http();
        ~Http();

        // Self server
        Http *get(const char*,  http_callback);
        Http *post(const char*, http_callback);
        Http *listen(int port = 80);

        Http(HttpRequest*, HttpResponse*);
        Http *setApp(App*);
        App *getApp();
        Http *setRequest(HttpRequest*);
        HttpRequest *getRequest();
        Http *setResponse(HttpResponse*);
        HttpResponse *getResponse();
        Http *setStorage(Storage*);
        Storage *getStorage();
        Http *setHash(char*);
        char *getHash();

        // HTTP Processor
        Http *serveRequest(function<void(App*)>);
    };
}

#endif