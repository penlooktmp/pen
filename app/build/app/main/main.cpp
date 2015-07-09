// AUTO GENERATED
#include "view.h"

namespace app
{
	void prepare(Model *model)
	{
		cout << "Model preparation" << "\n";
	}

	void handler(App *app)
	{
		map<const char*, any> data;
		data["title"] = "abc";
		app->getController()->getAction()->setData(data);
		Template::layout(app);
	}
}
