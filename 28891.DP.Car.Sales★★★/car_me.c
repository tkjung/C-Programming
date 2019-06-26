#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 버전6:


typedef struct branch
{
	char *brname; // 대리점 이름, 강변대리점
	char *manager; // 매니저 이름, 강길동
	int *numsold; // 각 자동차별 판매량, 1 11 21 31 18
} branch;

typedef struct branchList
{
	int numCar; // 차 이름 개수
	int numBr; // 대리점 이름 개수
	char **carname; // 차 이름들을 가리키는 이중포인터
	branch **thebrs; // 대리점 이름, 매니저 이름, 판매량을 가진 구조체를 가리키는 이중포인터
} blist;

// 강변대리점, 강길동, 판매량 담는 구조체
branch * getBr(FILE *fp)
{
	branch *pbr; 
	pbr = (branch*)malloc(sizeof(branch)); // 판매정보 구조체 크기만큼 동적할당

	char buffer[200];
	fscanf(fp,"%s", buffer);
	pbr->brname = (char*)malloc(strlen(buffer) + 1); // 강변대리점 동적할당
	strcpy(pbr->brname , buffer);
	
	fscanf(fp,"%s", buffer);
	pbr->manager = (char*)malloc(strlen(buffer) + 1); // 강길동 동적할당
	strcpy(pbr->manager, buffer); 

	return pbr;
}

// 판매정보 구조체를 입력하는 함수를 call하는 함수
blist * getBrList(FILE *fp)
{	
	blist *pbl;
	pbl = (blist*)malloc(sizeof(blist)); // 구조체 크기만큼 동적할당 

	printf("입력된 순서대로 된 실적표입니다.\n----\n대리점이름  매니저  ");

	fscanf(fp,"%d", &pbl->numBr); 
	
	pbl->thebrs = (branch**)malloc( sizeof(branch*) * pbl->numBr); // 포인터 개수만큼 동적할당
	
	for(int i = 0; i < pbl->numBr ; i++)
	{
		pbl->thebrs[i] = getBr(fp);  // 강변대리점, 강길동 입력
	}

	return pbl;
}

void getCarName(blist *pbl, FILE *fp)
{

	fscanf(fp, "%d", &pbl->numCar);
	
	char buffer2[200];
	pbl->carname = (char**)malloc(sizeof(char*) * pbl->numCar);
	
	for(int i = 0 ; i < pbl->numCar ; i++)
	{
		fscanf(fp, "%s", buffer2);
		pbl->carname[i] = (char*)malloc(strlen(buffer2) + 1);
		strcpy(pbl->carname[i] , buffer2);
	}

	for( int j = 0 ; j < pbl->numCar ; j++)
	{
		printf("%s  ", pbl->carname[j]);
	}
}

void printAll(blist *pbl)
{
	for(int i = 0; i < pbl->numBr ; i++)
	{
		printf("%s  %s\n", pbl->thebrs[i]->brname , pbl->thebrs[i]->manager );
	}

}

int main(int ac, char *av[])
{
	printf("데이터가 들어있는 파일 명을 입력하세요: ");
	char datafile[30];
	scanf("%s", datafile);

	FILE *fp;
	fp = fopen(datafile, "r");




	blist *theblist;
	
	theblist = getBrList(fp);

	getCarName(theblist, fp);

	printAll(theblist);



	fclose(fp);
}
