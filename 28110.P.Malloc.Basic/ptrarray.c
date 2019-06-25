#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int ac, char *av[])
{
	char *ptr[3]; // 3개의 char 포인터를 갖는 배열
	char buf[80]; // 임시 버퍼, 스트링 읽어들임
	
	// *ptr[3]에는 포인터를 넣을 공간만 있는 상태
	// 스트링을 따로 저장할 공간은 아직 안 받음.
	
	
	scanf("%s", buf); // buf에 읽어준다.
		
	ptr[0] = (char*)malloc(strlen(buf)+1); // malloc으로 메모리 할당해준다.
	strcpy(ptr[0], buf); // buf를 pp[0]에 복사해준다.
	// 위의 두 줄은 ptr[0] = strdup(buf) 으로 통합할 수 있다.

	
	scanf("%s", buf);
	ptr[1] = strdup(buf);

	scanf("%s", buf);
	ptr[2] = strdup(buf);


	printf("%s\n", ptr[2]);
	printf("%s\n", ptr[1]);
	printf("%s\n", ptr[0]);
}
