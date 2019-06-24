#include <stdio.h>

void rstrcpy(char *cpy , char *org)
{
	// cpy = {   } , org = { abcdefg }
	
	       // printf("%p\n", org); // 주소지가 1000번지라면
	       // printf("%c\n", *org); // 거기엔 'abcdefg' 중에 'a'가 들어있을 것이다.
	
	// 배열의 끝까지 반복
	while( *org != 0 )
	{
		org++; 
	}
	
	       // printf("%p\n", org); // 주소지가 1007번지라 되었을 것이다.
	       // printf("%c\n", *org); // 거기엔 쓰레기값이 들어있다.
	

	org--; // 주소지가 1006번지이다. 거기엔 'abcdefg' 중에 'g'가 들어있다.


	while( *org != 0 )
	{
		*cpy = *org;  // 'g'를 cpy의 첫번째가 가리키게 한다.
		cpy++;        // cpy는 다음 번지수로 
		org--;        // org는 이전 번지수로
	} 
  
  *cpy = 0; // 끝처리는 꼭 해준다.
}


int main(int ac, char *av[])
{
	char org[100];
	char cpy[100];
	
	scanf("%s", org);
	
	rstrcpy(cpy, org);
	
	printf("%s %s\n", org, cpy);
	// 원래 스트링이 abcdefg였다면, abcdefg  gfedcba가 출력
	
}
