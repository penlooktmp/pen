extern "C" {
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
}

#include <http/http.h>
#include "app.h"

using namespace http;

HttpResponse app_bridge(ngx_http_request_t* request, Model model)
{
    cout << "New Request" << "\n";

    HttpRequest http_request;
    HttpResponse http_response;

    ngx_str_t uri_obj = request->uri;
    string uri = reinterpret_cast<const char*>(uri_obj.data);
    http_request.setUri(uri);
    string command = "Index Home int id string password";

    Http http(http_request, http_response);
    return http.setCommand(command)
               .setModel(model)
               .serveRequest(app::handler)
               .getResponse();
}