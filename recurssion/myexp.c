#include<stdio.h>
#include<math.h>
int factorial(int a)
{
	if (a == 1) 
		return a;
	else 
		return a * factorial(a-1);
}
float myexp(float x, int n)
{
	if( n ==0 ) return 1;
	return pow(x,n)/factorial(n) + myexp(x,n-1);
}
main()
{
	printf("%f\n",myexp(1,4));
}
