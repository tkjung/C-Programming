#include <stdio.h>

int fact(int n)
{
	
	if( n == 1 )
	{
		return 1;
	}

	else
	{	
		return n * fact(n-1);
	}
	
}

int main(int ac, char *av[])
{
	int n;
	int result;

	scanf("%d", &n);

	result = fact(n);

	printf("%d\n", result);
}
