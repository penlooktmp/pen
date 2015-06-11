extern "C" {
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
}

#include <iostream>
#include <http/http.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace http;

static ngx_http_module_t ngx_http_app_module_ctx = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/*
Nginx Http Request
https://github.com/nginx/nginx/blob/master/src/http/ngx_http_request.h#L359
*/
static ngx_int_t ngx_http_app_handler(ngx_http_request_t *request)
{
    ngx_buf_t *buffer;
    ngx_chain_t out;

    HttpRequest http_request;
    HttpResponse http_response;

    ngx_str_t uri_obj = request->uri;
    string uri = reinterpret_cast<const char*>(uri_obj.data);
    http_request.setUri(uri);

    Http http(http_request, http_response);
    http.process();

    string html = http.getResponse().getBody();

    /* Type casting */
    u_char* u_html = (u_char*) html.c_str();
        
    /* Set the Content-Type header. */
    request->headers_out.content_type.len  = html.length();
    request->headers_out.content_type.data = u_html;

    /* Allocate a new buffer for sending out the reply. */
    buffer = (ngx_buf_t*) ngx_pcalloc(request->pool, sizeof(ngx_buf_t));

    /* Insertion in the buffer chain. */
    out.buf = buffer;
    out.next = NULL; /* just one buffer */

    buffer->pos = u_html; /* first position in memory of the data */
    buffer->last = u_html + html.length(); /* last position in memory of the data */
    buffer->memory = 1; /* content is in read-only memory */
    buffer->last_buf = 1; /* there will be no more buffers in the request */

    /* Sending the headers for the reply. */
    request->headers_out.status = NGX_HTTP_OK; /* 200 status code */
    /* Get the content length of the body. */
    request->headers_out.content_length_n = html.length();
    ngx_http_send_header(request);

    /* Send the body, and return the status code of the output filter chain. */
    return ngx_http_output_filter(request, &out);
}

static char *ngx_http_app(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t* clcf;
    clcf = (ngx_http_core_loc_conf_t*) ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_app_handler;
    return NGX_CONF_OK;
}

static ngx_command_t ngx_http_app_commands[] = {
    {
        ngx_string("app"),
        NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
        ngx_http_app,
        0,
        0,
        NULL
    },
    ngx_null_command
};

ngx_module_t ngx_http_app_module = {
    NGX_MODULE_V1,
    &ngx_http_app_module_ctx,
    ngx_http_app_commands,
    NGX_HTTP_MODULE,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NGX_MODULE_V1_PADDING
};