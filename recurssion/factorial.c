#include<stdio.h>

int factorial(int a)
{
	if (a == 1) 
		return a;
	else 
		return a * factorial(a-1);
}
main()
{
	printf("%d\n", factorial(4));
}
