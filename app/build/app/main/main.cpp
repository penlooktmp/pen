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
		Action action = app->getController()->getAction();
		map<char*, char*> data;
		data[(char*) "title"] = (char*) "abc";
		Template::layout(app, data);
	}
}
