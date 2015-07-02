// AUTO GENERATED
#include "view.h"

namespace app
{
	void prepare(Model* model)
	{
		cout << "Model preparation" << "\n";
	}

	void handler(App* app)
	{
		map<string, any> data;
		data["title"] = "Hello world";
		data["number"] = 12345;
		//data["user"] = user;
		Template::layout(app, data);
	}
}
