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
		//action->getData();
		map<string, string> data;
		Template::layout(app, data);
	}
}
