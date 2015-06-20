#include <iostream>

using namespace http;

@Router /index
@Method GET
@Type HTML
class IndexController : Controller {
	
	public static int a;
	private App app;
	protected static int name;

	protected Abc() 
	{
		// TODO
	}
	
	protected Before()
	{
		User $user;
		// Before action
	}
	
	private processAbc()
	{
		// TODO
	}
	
	@Route /index/:uid/:password
	@Method GET POST
	@Type JSON
	public Index(int uid, string password)
	{
		// Index action
	}

	protected After()
	{
		// After action
	}
};