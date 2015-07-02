// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void layout(App* app, map<string, any> data) {
any title = data["title"];
any number = data["number"];
app->out+=string(title.cast<const char*>());
cout << number.cast<char*>();
cout.flush();
app->out+="<html><title>{{ title }}</title><head></head><body><h2>{{ username }}</h2><h3>{{ password }}</h3></body></html>";
}
}
}