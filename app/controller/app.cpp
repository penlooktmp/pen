#include <iostream>

using namespace http;

@Controller
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
@Type JSON
Index(int uid, string password)
{
	
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