#include <stdio.h>

int get_int()
{
	int c;
	int value = 0;

	c = getchar();

	while ( c == ' ' || c == '\t' || c == '\n' )
	{
		c = getchar();
	}

	if ( c < '0' || c > '9' )
	{
		return -9999999;
	}

	while ( c >= '0' && c <= '9' )
	{
		value = value * 10 + ( c - '0' );
		
		c = getchar();
	}

	return value;
}

int main(int ac, char *av[])
{
	int n;

	n = get_int();

	while ( n != -9999999 )
	{
		printf("%d\n", n);
		n = get_int();
	}

	return 0;
}
