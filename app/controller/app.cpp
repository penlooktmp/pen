@include (
	std
	http
)

@namespace (
	http
	std
)

@controller app base

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

After() 
{
	
}