#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu
{
	int id;
	char name[20];
	float gpa;
} stu_t;


stu_t *getStudent()
{
	// stu_t의 포인터를 선언하고, 동적할당 받는다.
	stu_t *p;
	p = malloc(sizeof(stu_t));

	// 학생 정보를 입력받는다.
	printf("학번 입력: ");
	scanf("%d", &p->id);

	printf("이름 입력: ");
	scanf("%s", p->name);

	printf("평점 입력: ");
	scanf("%f", &p->gpa);

	// 포인터(주소값)을 반환한다.
	return p;
}


void printStudent(stu_t *p)
{
	printf("학번: %d   이름: %s   평점: %.2f\n", p->id, p->name, p->gpa);
}


int main(int ac, char *av[])
{	
	stu_t *kim[3];

	for(int i = 0; i < 3; i++)
	{
		kim[i] = getStudent();
	}
	
	for(int j = 0; j < 3; j++)
	{
		printStudent(kim[j]);
	}
}
