#include <stdio.h>

// 보조함수: 한 글자씩 비교
int fsub(char *sub_haystack, char *sub_needle)
{
	// 두 스트링의 첫글자가 일치하면 1, 불일치하면 0 반환
	if( *sub_haystack != *sub_needle )
	{
		return 0;
	}

	else
	{
		return 1;
	}
}


int find_str(char *haystack, char *needle)
{
	// one[100] = abcdef,  two[20] = cd
	// *haystack = a ,     *needle = c

	// fsub를 1이 나올 때까지 계속 부른다. 
	// fsub 반환값이 1이 되면, 그때부터 뒤의 알파벳들도 같은지 검사
	
	
	while ( *haystack != 0 )
	{
		while(  fsub(haystack, needle) == 1 )
		{
			// c = c 인 경우
			haystack++; // d
			needle++; // d

			// d = d 라면
			if( *haystack == *needle  )	
			{
				return 1; // 일치하는 것이 있음
			}

		}

		haystack++; // 1회차일 때: 다음 회차는 bcdef를 부른다.
	}	

	return 0; // 배열에 값이 더이상 없을 시엔 0 반환 = "일치하는게 없음"
}


int main(int ac, char *av[])
{
	char one[100]; // haystack
	char two[20]; // needle

	while ( scanf("%s %s", one, two) == 2 ) // 입력항목이 2개일때 진행
	{
		if( find_str(one, two)==1 ) // 배열 = 포인터. 배열로 파라메터 전달하여 포인터로 받는다.
		{
			printf("있음\n");
		}

		else
		{
			printf("없음\n");
		}
	}
}
