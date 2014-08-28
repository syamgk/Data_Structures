#include<stdio.h>
#include<math.h>
int hcf( int a, int b)
{
	if(a%b == 0) return b;
	return hcf(b,a%b);
}
main()
{
	printf("%d\n",hcf(16,12));
}

