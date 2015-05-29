
#include <sys/func.h>
#include <net/restclient.h>
#include <sys/param.h>
#include <unistd.h>

string get_http_content(string url)
{
	RestClient::response response = RestClient::get(url);
	return response.body;
}

string get_cwd()
{
	char *buffer = new char[MAXPATHLEN];
    getcwd(buffer,MAXPATHLEN);
    if(buffer != NULL){
        string ret(buffer);
        delete[] buffer;
        return ret;
    } else {
        return string();
    }
}

void make_app()
{
	string build = get_cwd() + "/build";
	chdir(build.c_str());
	system("./build.sh");
}

int indexof(string str_origin, string str_find)
{
	static string::size_type loc = str_origin.find(str_find, 0);
	if (loc != string::npos) {
		return (int) loc;
	}
	return -1;
}