#include <iostream>
#include <map>

#include <http/http.h>

using namespace WPP;

void web(Request* req, Response* res) {
    res->body << "HELLO";
}

int main(int argc, const char* argv[]) {
    try {
        std::cout << "Listening on port 5000" << std::endl;
        WPP::Server server;
        server.get("/", &web);
        server.all("/dir", "./");
        server.start(5000);
    } catch(WPP::Exception e) {
        std::cerr << "WebServer: " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}