#include<stdio.h>
#include<string.h>
void reverse_str(char* start, char* str)
{
	if(*str == '\0') return;
	char c = *str; 		// copying char at fornt to c.
	int pos = strlen(str)-1;
	reverse_str(start,(str+1));
	*(start + pos) = c;	// pasting the previously captured char
}
main()
{
	char a[] = "0123456\0";
	printf("Before \t");
	printf("\t%s\n",a);
	reverse_str(a,a);
	printf("After\t");
	printf("\t%s\n",a);
}
