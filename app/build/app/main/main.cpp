// AUTO GENERATED
#include "controller.h"
#include "model"
#include "view.h"

namespace app
{
	
	// Model static storage
	void prepare(Model *model)
	{
		model->setControllers(app::getControllers());
		model->setViews(app::getViews());
		model->setModels(app::getModels());
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
