#include <stdio.h>
#include <ctype.h>

// scan_int는 정수를 읽어서 값을 포인터를 통해 돌려주는 함수로서
// scanf와 비슷하지만 포맷을 사용하지 않는다.
// 또한 성공 여부를 반환값을 통하여 알려주어야 한다.
// 1이면 성공 0이면 실패

int scan_int( int * pData )
{
	int c;
	int value = 0;  // 정수 계산할 값, *pData에 넣어줄 값  
	
	
	c = getchar(); 
	// printf("c는: %c\n", c);
	
	// 빈칸, 탭, 줄바꿈일 떄 반복문 들어간다.
	while ( c == ' '  ||  c == '\t'  ||  c =='\n' )
	{
		c = getchar();
	}
	
	if ( isdigit(c) )
	{
		// 숫자가 들어왔으니까, 그 수를 자리수 별로 순차적으로 getchar로 읽어들인다.
		while ( '0' <= c && c <= '9' )
		{
			value = value * 10 + ( c - '0' );  // 첫번째 자리 수
			c = getchar(); // 둘째 자리수 getchar
		}	
		// printf("%d\n", value);
		
		*pData = value;
		return 1;
	}
	
	else
	{
		return 0;
	}
	
	
}

int main()
{
	int mydata;
	
	while ( scan_int(&mydata) == 1 )
	{
		printf("읽은 값은 %d 입니다.\n", mydata);
	}
	
	return 0;
}
