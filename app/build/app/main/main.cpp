// AUTO GENERATED
#include "controller.h"
#include "model"
#include "view.h"

namespace app
{
	// Static storage
	void boot(Storage *storage)
	{
		cout << "APPLICATION BOOT";
		cout.flush();
		storage ->setControllers(app::getControllers())
				->setModels(app::getModels())
				->setViews(app::getViews());
		cout << "SYSTEM IS READY !";
		cout.flush();
	}

	// Request handler
	void handler(App *app)
	{
		// Index Controller
		Controller controller = app->getController();
		cout << controller->getName();

		/*
		// Home action
		Action action = controller->getAction();
		// MVC Lifecycle
		controller->beforeAction();
		action->run();
		controller->afterAction();
		// Render to view
		app->render();*/
	}
}
