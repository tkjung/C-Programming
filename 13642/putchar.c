#include <stdio.h>

int main(int ac, char *av[])
{
	int num;
	scanf("%d", &num); // 321

	int digit;

	
	int started = 0; // 0 아닌 숫자가 시작됐는지 여부
	// 1이면 시작된 것
	// 첫 자리 계산

	int div = 1000000000;

	while(div > 0)
	{
		digit = num / div; // 1회:0, 2회:3
		
		if ( started || digit > 0  )
		{
			started = 1;
			digit = digit + '0';
			putchar(digit);
		}
		
		num = num % div; // 1회: 321

		div = div / 10; // 1회: 100
	}





/*	int count=0; // 몇자리 수

	num_for_count = num;
	
	while( num_for_count > 0 )
	{
		num_for_count = num_for_count / 10;
		count++;
		printf("%d자리수\n", count);
	}

	while ( count >= 0 )
	{	
		putchar(num-'0');
		count--;
		num /= 10;
	}
 */ 
	printf("\n");
}
