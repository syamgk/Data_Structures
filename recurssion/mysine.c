#include<stdio.h>
#include<math.h>
#define sineq(x,n) "pow(x,"
int factorial(int a)
{
	if (a == 1) 
		return a;
	else 
		return a * factorial(a-1);
}
/*	returns sine value approx to n terms in
	sine expansion */
float mysine( float x,int n)
{
	if (n == 0) return x;
	return pow(-1, n)*pow(x, (2*n) +1)/factorial((2*n) +1) + mysine(x,n-1);
}
main()
{
	printf("%f\n",mysine(0,4));
	printf("%f\n",mysine(1.57,4));
}
