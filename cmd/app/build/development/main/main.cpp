#include <iostream>
#include <http/http.h>

using namespace std;
using namespace http;

// Mockup Nginx server
int main()
{
	HttpRequest proxyRequest;
	HttpResponse proxyResponse;
	Http server(proxyRequest, proxyResponse);
	server.get("/", [](Request* _request, Response* _response) {
		HttpRequest request;
		HttpResponse response;
		Http http(request, response);
		http.process();
		_response->body << http.getResponse().getBody();
	});
	server.listen(80);
	return 0;
}