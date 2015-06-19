#include <iostream>

using namespace http;

@Router /index
@Method GET
@Type HTML
class IndexController : Controller
{
	protected Before()
	{
		User $user;
	}
	
	@Route /index/:uid/:password
	@Method GET POST
	@Type JSON
	public Index(int uid, string password)
	{
		int a = 1;
	}

	protected After()
	{
		// After action
	}
};