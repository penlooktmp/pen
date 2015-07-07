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
#include "app.h"

using namespace std;
using namespace http;

static Model *model = new Model;

typedef struct {
    ngx_str_t name;
} ngx_http_app_loc_conf_t;

// Create app location configuration
static void *
ngx_http_app_create_loc_conf(ngx_conf_t *cf)
{
    ngx_http_app_loc_conf_t *conf;
    conf = (ngx_http_app_loc_conf_t*) ngx_pcalloc(cf->pool, sizeof(ngx_http_app_loc_conf_t));
    if (conf == NULL) {
        return NULL;
    }
    return conf;
}

// Module context register
static ngx_http_module_t ngx_http_app_module_ctx = {
    NULL,                          /* preconfiguration */
    NULL,                          /* postconfiguration */

    NULL,                          /* create main configuration */
    NULL,                          /* init main configuration */

    NULL,                          /* create server configuration */
    NULL,                          /* merge server configuration */

    ngx_http_app_create_loc_conf,  /* create location configuration */
    NULL
};

/*
Nginx Http Request
https://github.com/nginx/nginx/blob/master/src/http/ngx_http_request.h#L359
*/
static ngx_int_t ngx_http_app_handler(ngx_http_request_t *request)
{
    /*
    string str = "Hello world";
    char* html = (char*) str.c_str();
    int html_length = str.length();
    */
    Http *http = app_bridge(request, model);
    HttpResponse *response = http->getResponse();

    char *html = response->getBody();
    int html_length = response->getBodyLength();
    
    // Deallocate memory for application
    delete http;
    
    cout << html << "\n\n";
    ngx_buf_t *buffer;
    ngx_chain_t out;

    /* Type casting */
    u_char* u_html = (u_char*) html;

    /* Set the Content-Type header. */
    request->headers_out.content_type.len  = sizeof("text/html") - 1;
    request->headers_out.content_type.data = (u_char *) "text/html";

    /* Allocate a new buffer for sending out the reply. */
    buffer = (ngx_buf_t*) ngx_pcalloc(request->pool, sizeof(ngx_buf_t));

    /* Insertion in the buffer chain. */
    out.buf = buffer;
    out.next = NULL; /* just one buffer */

    buffer->pos = u_html; /* first position in memory of the data */
    buffer->last = u_html + html_length; /* last position in memory of the data */
    buffer->memory = 1; /* content is in read-only memory */
    buffer->last_buf = 1; /* there will be no more buffers in the request */

    /* Sending the headers for the reply. */
    request->headers_out.status = NGX_HTTP_OK; /* 200 status code */
    /* Get the content length of the body. */
    request->headers_out.content_length_n = html_length;
    ngx_http_send_header(request);

    /* Send the body, and return the status code of the output filter chain. */
    return ngx_http_output_filter(request, &out);
}


static char *ngx_http_app(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t* clcf;
    clcf = (ngx_http_core_loc_conf_t*) ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_app_handler;
    
    cout << "LOCATION :";
    ngx_str_t* args;
    args = (ngx_str_t*) cf->args->elts;
    for (int i=0; i < cf->args->nelts; i++) {
        cout << args[i].data << "\n";
    }
    cout << "\n\n";

    return NGX_CONF_OK;
}

static ngx_command_t ngx_http_app_commands[] = {
    {
        ngx_string("app"),
        NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_ANY,
        ngx_http_app,
        NGX_HTTP_LOC_CONF_OFFSET,
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


