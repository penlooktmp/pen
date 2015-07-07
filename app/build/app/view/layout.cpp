// AUTO GENERATED
#include "view.h"
namespace app {
namespace Template {
void layout(App* app, map<const char*, any> data) {
char const *html[] = {
"<html><title>{{ title }}</title><head></head><body><h2>{{ username }}</h2><h3>{{ password }}</h3></body></html>"," "
};
app->getHttpResponse()->setBody(join((char**)html));
}
}
}