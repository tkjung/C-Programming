#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char *wlist[], int size)
{
	char *tmp;

	for(int c=0; c < size-1; c++)  // c < size 하면 세그멘테이션 오류
	{
		for(int r=0; r < size-1; r++) 
		{
			if(   strcmp( wlist[r], wlist[r+1] ) > 0   )
			{
				tmp = wlist[r];
				wlist[r] = wlist[r+1];
				wlist[r+1] = tmp;
			}
		}
	}
}

void printall(char *wlist[], int size) 
{
	int i;

	for( i = 0; i < size; i++)
	{
		printf("%s\n", wlist[i]);
	}
}


int main(int ac, char *av[])
{
	char *word_list[100]; // 최대 100개 단어를 갖는 char 포인터 배열
	char buf[80]; // 임시 버퍼 배열, 스트링 읽어들임

	int i = 0; // 반복문 임시변수
	int numWords = 0; // 입력된 단어 개수를 세어줌.
	
	while( scanf("%s", buf) == 1 ) // ctrl + d 누르면 입력 종료
	{
		numWords++;
		word_list[i] = strdup(buf); // 꼭 필요한 만큼의 메모리만 malloc으로 할당
		i++;
	}

	printf("---정렬 전---\n");
	printall(word_list, numWords); // 출력 함수 호출
	
	sort(word_list, numWords); // 정렬 함수 호출
		
	printf("---정렬 후---\n");
	printall(word_list, numWords); // 출력 함수 호출


	//-------------------- 버전3: 정렬 완료--------------------//
}
