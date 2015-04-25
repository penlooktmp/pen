#include <stdio.h>
#include <string.h>

void Send() {
	int i;
	for (i=1; i<=100; i++) {
		printf("Hello %s", i);
	}
}