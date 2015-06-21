#include <iostream>
using namespace http;

@Router /index
@Method GET
@Type HTML
class Home : Controller
{
	public static User a;
	private App app;
	protected static int name;

	@Route /app/home
	@Method GET POST
	@Type JSON
	public App(int uid, string password);
	
	@Route /home/index
	public Index();
};