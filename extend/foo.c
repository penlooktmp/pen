#include <stdio.h>
#include <string.h>
#include <assert.h>

void Abc() {
    char str[80];
	int i;

	printf("Enter a string: ");
	fgets(str, 10, stdin);
	int a = 1;

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