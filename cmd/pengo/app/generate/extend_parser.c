#include <stdio.h>
#include <stdio.h>
#include <string.h>

void Pk() {
	int i;
	int b = 0;
	for (i=1; i<100000000; i++) {
		b += 1;
	}
	printf("SUM B = %d\n", b);
}

char* Abc() {
    static char str[80];
	int i;

	printf("Enter a string: ");
	fgets(str, 10, stdin);

	i = strlen(str)-1;
	if (str[i] == '\n') {
	  	str[i] = '\0';
	}
	return str;
}