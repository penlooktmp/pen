#include <stdio.h>
#include <string.h>

char[] Concat(char* str1, char* str2) {
	int len_total = strlen(str1) + strlen(str2);
	char result[len_total];
	strcpy(result, str1);
	return result;	
}

int main() {
	char[] abc = Concat("Hello", " World");
	printf("STR = %s \n", abc);
	return 0;
}