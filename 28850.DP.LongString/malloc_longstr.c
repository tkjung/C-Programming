#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 200
#define INIT_SIZE 8

char * getString()
{
	// 빈칸 탭 newline 으로 구분된 스트링
	char *s = (char*)malloc(INIT_SIZE);
	int c; // 입력을 위한 변수
	int len=0; // 현재까지 입력 길이.
	int curSize = INIT_SIZE;
	
	c = getchar();
	while ( c == ' ' || c == '\t' || c == '\n' )
	{
		c = getchar();
	}

	// printf("[%c]\n", c);

	while( c != ' ' && c != '\t' && c != '\n' && c != EOF )
	{
		// len이 7이고 curSize = 8이면
		if(len+1 >= curSize)
		{
			// 공간이 더 필요하다.
			char *t; t = s;
			
			s = (char*)malloc(curSize*2);
			
			for (int k=0; k<len; k++)
			{
				s[k] = t[k];
			}
			free(t);	
			curSize *= 2;
			printf("차지한 길이: %d  새 크기: %d\n", len, curSize);
		}

		s[len] = c;
		len++;
		c=getchar();
	}
	
	s[len] = 0;

	return s;
}


int main(int ac, char *av[])
{
	char *s;
	s = getString();
	printf("[%s]\n", s);
}
