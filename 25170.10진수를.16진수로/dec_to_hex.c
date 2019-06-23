#include <stdio.h>
int main(int ac, char *av[])
{
	char hexname[17] = "0123456789ABCDEF";
	int integer = 0;
	unsigned int mask = 0xf0000000;
	int temp = 0;
	int on_off1 = 0;
	int on_off2 = 0;

	scanf("%d", &integer);  // integer = 255 = 0x 0000 00ff
	

	// 첫번째 비트 (mask이동 없음)
	temp = integer & mask;   // temp = 0x 0000 00ff  & 0x f000 0000 = 0x 0000 0000
	temp>>=28;
	
	if ( temp != 0 )
	{
		on_off1 = 1;
	}

	if ( on_off1 == 1 ) 
	{
		putchar(hexname[temp]);
	}



	// 두번째 비트 ~ 마지막 비트 (mask이동 있음, 반복문)
	for(int i = 2 ; i <= 8 ; i++)
	{
		mask >>= 4;
		temp = integer & mask;
		temp >>= 32 - (4*i);
		
		if ( temp != 0 )
		{
			on_off2 = 1;
		}

		if ( on_off2 == 1 ) 
		{
			putchar(hexname[temp]);
		}

	} 


}
