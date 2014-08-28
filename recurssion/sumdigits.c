#include<stdio.h>
// returns sums of the digits in a number
int sumdigits(int a)
{
	if(a == 0) return;
	return a%10 + sumdigits(a/10);
}
main()
{
	printf("%d\n",sumdigits(332));
}
