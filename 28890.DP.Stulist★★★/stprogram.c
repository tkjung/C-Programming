#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 버전4 : FILE *fp fopen, fclose, fscanf 추가. 
// a.out 으로 했을 때 실행 잘 됨.
// 제가 공부한 방식이 [파일명 입력하세요: 파일명 입력]이 아니라서 하는 법을 잘 모르고, 
// a.out 할 때 studata.txt에서 자동으로 입력해주고, 
// 바로 출력이 나오도록 한 방식이어서 이렇게 했습니다.


typedef struct student
{
	char *name; // 강길동
	char id[9]; // 60190001
} stu_t;

// 전체를 아우르는 구조체
typedef struct stlist
{
	int numStu; // 학생 수   8
	stu_t **pstulist; 
} stlist;


stu_t *getStudent(FILE *fp)
{
	stu_t *ps;
	ps = (stu_t*)malloc(sizeof(stu_t)); // 구조체 크기만큼 할당

	// 학생 이름 입력
	char buffer[200];
	fscanf(fp, "%s", buffer);
	ps->name = (char*)malloc(strlen(buffer) + 1); // 이름 길이만큼 할당
	strcpy(ps->name, buffer);

	// 학생 학번 입력
	fscanf(fp,"%s", ps->id);

	return ps;
}


stlist *getStList(FILE *fp)
{
	stlist *psl;
	psl = (stlist*)malloc(sizeof(stlist)); // 구조체 크기만큼 할당

	fscanf(fp,"%d", &psl->numStu); // 학생수 입력받음. 

	psl->pstulist = (stu_t**)malloc(sizeof(stu_t*) * psl->numStu );  
	// 포인터 크기를 학생수만큼 할당
	
	for ( int i = 0 ; i < psl->numStu ; i++)
	{
		psl->pstulist[i] = getStudent(fp);
	}

	return psl;
}

void printAll(stlist *psl)
{
	for(int i = 0 ; i < psl->numStu ; i++)
	{
		printf("%s %s\n", psl->pstulist[i]->name, psl->pstulist[i]->id);
	}

}

/*void sort(stlist *psl)
{
	
	if ( int i = 0 ; i < psl->num1


} */

int main(int ac, char *av[])
{
	stlist *psl;

	FILE *fp;
	fp = fopen("studata.txt", "r");
	
	psl = getStList(fp);
		
	printAll(psl);

	fclose(fp);
}
