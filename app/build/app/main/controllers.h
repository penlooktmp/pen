// AUTO GENERATED
#include <map>
#include <vector>
#include <functional>
#include <app/controller.h>

namespace app {
	ListController getControllers()
	{
		ListController controllers = new ListController();
		controllers["Index"] = (new Controller)
									->setName("Index")
									->addAction(
										(new Action)
											->setName("Home")
											->addArgument("")
											->setHash("");
		return controllers;
	}
}