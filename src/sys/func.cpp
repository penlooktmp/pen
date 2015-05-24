
#include <sys/func.h>

int indexof(string str_origin, string str_find)
{
	static string::size_type loc = str_origin.find(str_find, 0);
	if (loc != string::npos) {
		return (int) loc;
	}
	return -1;
}