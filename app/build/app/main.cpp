// AUTO GENERATED
#include "view.h"

namespace app
{
	void start(App* app)
	{
		map<string, string> data;
		data["title"] = "Hello World";
		Template::layout(app, data);
	}
}