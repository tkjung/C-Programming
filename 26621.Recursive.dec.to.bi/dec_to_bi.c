#include <stdio.h>

void rprint(int n)
{
	
	if ( 0 <= n && n <= 1 )
	{
		printf("%d", n);  // 0, 1은 그 n 자체가 이진수 마지막자리이다.
	}

	else 
	{	
		rprint( n/2 );       // 재귀 호출을 먼저한다.
		printf("%d", n % 2); // 나머지를 뒤에 출력한다.
	}
}


int main(int ac, char *av[])
{
	int n;

	scanf("%d", &n);

	rprint(n);
	
	printf("\n");
}
