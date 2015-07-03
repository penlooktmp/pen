// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void index_index(App* app, map<string, any> data) {
app->out+="<html>\n";
app->out+="<title>{{ title }}</title>\n";
app->out+="<head>\n";
app->out+="</head>\n";
app->out+="<body>\n";
app->out+="<h2>{{ username }}</h2>\n";
app->out+="<h3>{{ password }}</h3>\n";
app->out+="<img src=\"{{ image }}\" width=\"400px\" />\n";
app->out+="</body>\n";
app->out+="</html>\n";

}
}
}