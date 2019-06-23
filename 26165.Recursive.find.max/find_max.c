#include <stdio.h>

int rmax(int a[], int start, int size)
{
	int max;
	
	if ( start == 0)
	{
		max = a[0];
		return max;
	}
	
	else if ( a[start] < a[start +1] )
	{
		max = a[start+1];
		return rmax( a[start +1] , start+1 , size-1);
	}
}


int main(int ac, char *av[])
{
	int a[10] = { 17, 14, 19, 12, 15, 11, 20, 13, 18, 16 };
	int result = 0;

	result = rmax(a,0,10);

	printf("%d", result);
}
