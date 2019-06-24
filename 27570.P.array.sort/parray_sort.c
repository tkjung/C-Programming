#include <stdio.h>
#include <string.h>

int main(int ac, char *av[])
{
	char name[20][100];
	char *ptr[20]; // 포인터 배열
	int count = 0;  // 입력된 이름의 개수
	char *tmp = 0; // 정렬시 임시로 옮겨주는 변수

	// count는 총 개수를 가지고 있다.
	while ( count < 20 && scanf("%s", name[count]) == 1 )	
	{
		count++;
		
	}
		// 포인터 배열 ptr을 초기화 한다.
		for(int i = 0; i < count; i++)
		{
			ptr[i] = name[i];
		}

	
	printf("--- 초기 데이터---\n");
	
	for(int j = 0; j < count; j++)
	{	
		printf("%s\n", ptr[j]);
	}
	
	printf("-----------------\n\n");


	for ( int c = 0 ; c < count-1 ; c++)
	{
		for (int r = 0 ; r < count-1 ; r++ ) 
		{
			// ptr[0], ptr[1] 비교. 윗행이 아랫행보다 크면(알파벳 나중이면) 바꾼다.
			if (    strcmp( ptr[r], ptr[r+1] ) > 0    ) 
			{
				// ptr[0] <-> ptr[1] 자리 교체
				tmp = ptr[r];
				ptr[r] = ptr[r+1]; 
				ptr[r+1] = tmp;	
			}
		}	
	}

	printf("--- 정렬 후 데이터---\n");
	
	for(int k = 0; k < count; k++)
	{	
		printf("%s\n", ptr[k]);
	}
	
	printf("-----------------\n");


}
