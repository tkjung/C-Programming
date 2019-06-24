#include <stdio.h>

void mystrcpy(char *cpy, char *org)
{
	// cpy = {  }  , org = {abc}

	// 배열의 끝까지 반복
	while( *org != 0  )
	{	
		*cpy = *org;
		org++; // org도 다음 주소로
		cpy++; // cpy도 다음 주소로
	}
	
	cpy--; // 마지막에 org, cpy++ 되어서, 
	       // 만약 그대로 cpy를 출력하면 쓰레기값이 1개 달려나온다.
		   // 그래서 cpy-- 한번 해줘야 원하던 값까지만 출력한다.
	*cpy = 0; // 끝처리는 꼭 해준다.
}


int main(int ac, char *av[])
{
	char org[100]; // 원본 스트링
	char cpy[100]; // 복사본 스트링

	scanf("%s", org); // abc 입력

	mystrcpy(cpy, org); // {   } , {abc} 전달

	printf("%s\n", cpy);
}
