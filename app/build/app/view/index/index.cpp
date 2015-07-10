// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void index_index(App* app) {
char const *html[] = {
"<html>","<title>{{ title }}</title>","<head>","</head>","<body>","<h2>{{ username }}</h2>","<h3>{{ password }}</h3>","<img src=\"{{ image }}\" width=\"400px\" />","</body>","</html>",'\0'
};
app->getHttpResponse()->setBody(join((char**)html, "\n"));
}
}
}