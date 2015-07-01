// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void layout(App* app, map<string, any> data) {
string title = any_cast<char*>(data["title"]);
int number = any_cast<int>(data["number"]);

app->out+="<html>\n";
app->out+="<title>" + title + "</title>\n";
app->out+="<head>\n";
app->out+="</head>\n";
app->out+="<body>\n";
app->out+="<h2>{{ username }}</h2>\n";
app->out+="<h3>{{ password }}</h3>\n";
app->out+="</body>\n";
app->out+="</html>\n";
}
}
}