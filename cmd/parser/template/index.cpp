
// AUTO GENERATED
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T> const char* typeof(T&) { return "unknown"; }
template<> const char* typeof(int&) { return "int"; }
template<> const char* typeof(short&) { return "short"; }
template<> const char* typeof(long&) { return "long"; }
template<> const char* typeof(unsigned&) { return "unsigned"; }
template<> const char* typeof(unsigned short&) { return "unsigned short"; }
template<> const char* typeof(unsigned long&) { return "unsigned long"; }
template<> const char* typeof(float&) { return "float"; }
template<> const char* typeof(double&) { return "double"; }
template<> const char* typeof(long double&) { return "long double"; }
template<> const char* typeof(std::string&) { return "string"; }
template<> const char* typeof(char&) { return "char"; }
template<> const char* typeof(signed char&) { return "signed char"; }
template<> const char* typeof(unsigned char&) { return "unsigned char"; }
template<> const char* typeof(char*&) { return "char*"; }
template<> const char* typeof(signed char*&) { return "signed char*"; }
template<> const char* typeof(unsigned char*&) { return "unsigned char*"; }

namespace View {

template <typename T>
string output(T variable) {
	return "";
}

void index_html(map<string, string> data) {
cout <<"<html>\n"
<<"<title>"
<< output("title") << "</title>\n"
<<"<head>\n"
<<"</head>\n"
<<"<body>\n"
<<"{{ message }}\n"
<<"</body>\n"
<<"</html>\n"
<<"";
}}

int main() {
	string abc;
	cout << typeof(abc);
	map<string, string> data;
	//View::index_html(data);
	return 0;
}
