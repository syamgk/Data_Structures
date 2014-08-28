#include<stdio.h>
int sumseries( int a, int b)
{
	if(a == b) return b;
	else
		return a + sumseries(a+1, b);
}
main()
{
	printf("%d\n",sumseries(1,3));
}
