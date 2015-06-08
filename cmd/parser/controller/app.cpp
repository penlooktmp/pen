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
@Type HTML
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