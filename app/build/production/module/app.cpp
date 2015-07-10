extern "C" {
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
}

#include "app.h"

using namespace http;

Http *app_bridge(ngx_http_request_t* ngxRequest, Storage *storage)
{
    HttpRequest *request = new HttpRequest;
    HttpResponse *response = new HttpResponse;

    // Copy config from nginx
    ngx_str_t ngx_uri_obj = ngxRequest->uri;
    char *uri = reinterpret_cast<char*>(ngx_uri_obj.data);
    request->setUri(uri);

    // Example
    char hash[] = "2d62bde79116359c6c0fbbbcfcb17076";

    Http *http = new Http;
    http->setRequest(request)
        ->setResponse(response)
        ->setHash(hash)
        ->setStorage(storage)
        ->serveRequest(app::handler);
   return http;
}