// AUTO GENERATED
#include "view.h"
#include <sys/type.h>

class User {
	private:
		string name;
	public:
		User setName(string);
		string getName();
};

User User::setName(string name)
{
	this->name = name;
	return *this;
}

string User::getName()
{
	return this->name;
}

namespace app
{
	void prepare(Model* model)
	{
		cout << "Model preparation" << "\n";
	}

	void handler(App* app)
	{
		User user;
		user.setName("loint");

		map<string, any> data;
		data["title"] = "Hello world";
		data["number"] = 12345;
		data["user"] = user;
		Template::layout(app, data);
	}
}