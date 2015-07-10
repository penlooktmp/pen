// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void layout(App* app) {
char const *html[] = {
"<html>","<title>{{ title }}</title>","<head>","</head>","<body>","<h2>{{ username }}</h2>","<h3>{{ password }}</h3>","</body>","</html>",'\0'
};
app->getHttpResponse()->setBody(join((char**)html, "\n"));
}
}
}