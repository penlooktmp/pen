#include <stdio.h>

int main()
{
char hi[6] = "Hello";
char earth[] = "World";
char text[] = "%s %s";
__asm__ {
	lea eax,earth // eax = address of earth
	push eax   // put eax at the top of the stack
	lea eax,hi  // eax = address of hi
push eax
lea eax,text
push eax
call DWORD ptr printf
	pop ebx // clean up the stack
	pop ebx
pop ebx
}
getchar();// wait for any key
}