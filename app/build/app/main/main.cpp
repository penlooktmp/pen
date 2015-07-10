// AUTO GENERATED
#include "controllers.h"
#include "models.h"
#include "views.h"

namespace app
{
	// Static storage
	void boot(Storage *storage)
	{
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
