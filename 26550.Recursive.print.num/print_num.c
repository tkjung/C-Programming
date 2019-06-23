#include <stdio.h>


void print_all(int n)
{

	if (n > 0 )
	{
		printf("%d ", n);

		return print_all(n-1);
	}
}




int main(int ac, char *av[])
{
	int n;
	scanf("%d", &n);

	print_all(n);

}
