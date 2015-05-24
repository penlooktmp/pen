@Controller app base

@Method
Before()
{
	
}

@Route /index/:uid/:password
@Method GET POST
Index(int uid, string password)
{
	$title = "Index Page";
	$id = uid;
	$password = password;
}

After() 
{
}