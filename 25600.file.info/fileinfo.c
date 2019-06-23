#include <stdio.h>

char pack(char info[])
{
	// 4개의 정보를 하나의 char에 집어 넣는다.
	// 각 정보를 한 비트로 나타내면 된다.
	// 맨 왼쪽 비트는 파일/디렉토리 여부, 그다음은 읽기 권한, 쓰기 권한
	// 그리고 실행 권한을 나타내게 한다.
	
	// 첫째자리 둘째자리 셋째자리 넷째자리 
	//  d / f    r / -    w / -    x / -

	char result = 0;


	// 첫째자리
	if ( info[0] == 'd' ) 	
	{
		result = result + 1;
	}
	else if ( info[0] == 'f' )
	{
		result = result + 0;
	}

	result <<= 1;


	// 둘째자리
	if ( info[1] == 'r' ) 	
	{
		result = result + 1;
	}	
	else if ( info[1] == '-' )
	{
		result = result + 0;
	}

	result <<= 1;


	// 셋째자리
	if ( info[2] == 'w' ) 	
	{
		result = result + 1;
	}	
	else if ( info[2] == '-' )
	{
		result = result + 0;
	}

	result <<= 1;


	// 넷째자리
	if ( info[3] == 'x' ) 	
	{
		result = result + 1;
	}
	else if ( info[3] == '-' )
	{
		result = result + 0;
	}

	return result;
}


void print_info(char packed_info)
{
	// 하나의 char에 저장된 정보를 
	// frwx,  dr-x, d-wx  같은 형태로 출력한다.
	
	printf("파일정보: ");

	// 첫째자리 d / f 출력
	if (packed_info >= 8)
	{
		printf("d");
	}
	
	else 
	{
		printf("f");
	}
	
	// 둘째자리 r / - 출력
	if ( packed_info / 4 == 1 || packed_info / 4 == 3)
	{
		printf("r");
	}

	else
	{
		printf("-");
	}

	// 셋째자리 w / - 출력
	if ( packed_info / 2 == 7 || packed_info / 2 == 5 || 
		packed_info / 2 == 3 || packed_info / 2 == 1 )	
	{
		printf("w");
	}

	else
	{
		printf("-");
	}
	
	// 넷째자리 x / - 출력
	if ( packed_info % 2 == 1 )
	{
		printf("x");
	}

	else
	{	
		printf("-");
	}

	printf("\n");
}


int main()
{
	char info[5];  // file, read, write, execute 정보를 가져온다.
	scanf("%s", info);
	
	// 이건 그냥 확인용이니까 코멘트 처리한다.
	// printf("테스트: %c %c %c %c\n", info[0], info[1], info[2], info[3]); 

	char packed_info;
	packed_info = pack(info);  // packed_info 에 4가지 정보를 담는다.
	printf("저장된 char 값: %hhx\n", packed_info);  // 추가된 줄.
	print_info(packed_info);   // 정보를 drwx 같은 형태로 출력한다.
	return 0;
}
