
// AUTO GENERATED
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;
namespace View {

template <typename T>
string output(T variable) {
	if (typeid(variable).name() == "PKc") {
		return variable;
	} else return "Unknown type";
}

void index_html(map<string, string> data) {
cout <<"<html>\n"
<<"<title>{{ title }}</title>\n"
<<"<head>\n"
<<"</head>\n"
<<"<body>\n"
<<"{{ message }}\n"
<<"</body>\n"
<<"</html>\n"
<<"";
}}
		int main() {
	map<string, string> data;
	View::index_html(data);
	return 0;
}