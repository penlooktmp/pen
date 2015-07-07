extern "C" {
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
}

#include <http/http.h>
#include "app.h"

using namespace http;

Http *app_bridge(ngx_http_request_t* request, Model *model)
{
    HttpRequest *http_request;
    HttpResponse *http_response;
    ngx_str_t uri_obj = request->uri;
    char *uri = reinterpret_cast<char*>(uri_obj.data);
    http_request->setUri(uri);
    char command[] = "Index Home int id string password";
    Http *http = new Http;
    http->setCommand(command)
        ->setModel(model)
        ->serveRequest(app::handler);
   return http;
}