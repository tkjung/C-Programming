#include <stdio.h>

void hexprint(int n)
{	
	// 과제 [숙제 hexprint]에서 했던 char 배열을 이용한다.
	char hexname[17] ="0123456789ABCDEF";

	if ( 0 <= n && n <= 15 ) // n = 0~15 중 하나면,
	{
		putchar(hexname[n]); // 그 n 자체가 마지막 자리 16진수
	}
	
	else
	{
		hexprint( n/16 ); //  다음 16진수 자리를 재귀 호출한다.
		putchar( hexname[n%16] ); // 나머지를 뒤에 출력
	}

}

int main(int ac, char *av[])
{
	int n;

	scanf("%d", &n);

	hexprint(n);


	printf("\n");	
}
