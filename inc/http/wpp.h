/*
    Web++
    An Open Source web server for C++
    https://github.com/konteck/wpp
*/

#include <dirent.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#define SERVER_NAME "Pengo"
#define SERVER_VERSION "1.0.1"
#define http_callback function<void(Request*, Response*)>
#define BUFSIZE 8096

using namespace std;

namespace http {
    
    class Request {
        public:
            std::string method;
            std::string path;
            std::string params;
            map<string, string> headers;
            map<string, string> query;
            map<string, string> cookies;
    };

    class Response {
        public:
            Response() {
                code = 200;
                phrase = "OK";
                type = "text/html";
                body << "";
                
                // set current date and time for "Date: " header
                char buffer[100];
                time_t now = time(0);
                struct tm tstruct = *gmtime(&now);
                strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S %Z", &tstruct);
                date = buffer;
            }
            int code;
            string phrase;
            string type;
            string date;
            stringstream body;
        
            void send(string str) {
               body << str;
            };
            void send(const char* str) {
               body << str;
            };
        private:
    };

    class Exception : public std::exception {
        public:
            Exception() : pMessage("") {}
            Exception(const char* pStr) : pMessage(pStr) {}
            const char* what() const throw () { return pMessage; }
        private:
            const char* pMessage;
    };

    struct Route {
        string path;
        string method;
        http_callback callback;
        string params;
    };

    class Server {
        public:
            void get(string,  http_callback callback);
            void post(string, http_callback callback);
            void all(string,  http_callback callback);
            void get(string,  string);
            void post(string, string);
            void all(string,  string);
            bool start(int,   string);
            bool start(int);
            bool start();
        private:
            void* main_loop(void*);
            static void* process(void *threadid);
            void parse_headers(char*, Request*, Response*);
            bool match_route(Request*, Response*);
            string trim(string);
            void split(string, string, int, vector<string>*);
    };
}