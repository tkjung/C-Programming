#include <stdio.h>
#include <ctype.h>

// scan_int2는 두자리 정수를 읽어서 값을 포인터를 통해 돌려주는 함수로서
// scanf와 비슷하지만 포맷을 사용하지 않는다.
// 또한 성공 여부를 반환값을 통하여 알려주어야 한다.
// 1이면 성공 0이면 실패

int scan_int2( int *mydata )
{

	int c1, c2;
	
	// 두 개의 숫자 문자를 읽어서 정수를 만들어 준다.
	// 문제를 단순화해서 숫자 전에 빈칸 같은 것은 입력하지 않는 걸로 가정
	c1 = getchar(); 
	c2 = getchar();
	
	
	if (isdigit(c1) && isdigit(c2))
	{
		// 계산해서 파라메터를 통해 정수 저장하고
		*mydata = (  10 * ( c1 - '0')  ) + ( c2 - '0'); 
		return 1; // 1을 반환
	} 
	
	else 
	{
		return 0; // 실패니까 0을 반환
	}

}
int main()
{
	int mydata;
	int nResult;
	
	nResult = scan_int2(&mydata);
	
	if ( nResult == 1 )
	{
		printf("읽은 값은 %d 입니다.\n", mydata);
	} 
	
	else 
	{
		printf("읽기에 실패.\n");
	}
	
	return 0;

}
