// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void app_index(App* app, map<const char*, any> data) {
char const *html[] = {
"<html><title>{{ title }}</title><head></head><body><h2>{{ username }}</h2><h3>{{ password }}</h3><img src=\"{{ image }}\" width=\"400px\" /></body></html>"," "
};
app->getHttpResponse()->setBody(join((char**)html));
}
}
}