#include<stdio.h>
void printstring(char *s)
{
	if( *s == '\0') return;
	printstring(s+1);
	printf("%c",*s);
}
main()
{
	printstring("123hello");
	printf("\n");
}
	
