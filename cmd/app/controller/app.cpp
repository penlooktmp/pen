#include <iostream>

using namespace http;

@Controller Base
App() 
{
	// Controller constructor
}

@Override
Before()
{
	// Before action
}

@Route /index/:uid/:password
@Method GET POST
Index(int uid, string password)
{
	$title = "Index Page";
	$id = uid;
	$password = password;
}

@Override
After()
{
	// After action
}

~App() 
{
	// Controller destructor
}