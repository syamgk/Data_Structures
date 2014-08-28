#include<stdio.h>

void print(int a,int b)
{
	if( a <= b) {
		printf("%d\n",a);
		print(a+1 ,b);
	}
}

main()
{
	print(1,10);
}

