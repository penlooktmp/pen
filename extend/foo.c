#include <stdio.h>
#include <stdio.h>
#include <string.h>

void Abc() {
    char str[80];
	int i;

	printf("Enter a string: ");
	fgets(str, 10, stdin);

	i = strlen(str)-1;
	if (str[i] == '\n') {
	  	str[i] = '\0';
	}

	printf("This is your string: %s", str);
}

int main() {
	Abc();
	return 0;
}