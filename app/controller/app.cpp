#include <iostream>

using namespace http;

class appController {

	public int a;
	public int b;

	private Before()
	{
		// Before action
	}
	
	@Route /index/:uid/:password
	@Method GET POST
	@Type JSON
	public Index(int uid, string password)
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
};