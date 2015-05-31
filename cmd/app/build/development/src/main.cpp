#include <iostream>
#include <http/http.h>

using namespace std;

// Mockup Nginx server
int main()
{
	HttpRequest _request;
	HttpResponse _response;
	Http server(_request, _response);
	server.get("/", [](Request* request_, Response* response_) {		
		HttpRequest request;
		HttpResponse response;
		Http http(request, response);
		http.process();
		response->body << http.getResponse().getBody();
	});
	server.listen(80);
	return 0;
}
