#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stu
{
	int id;
	char name[20];
	float gpa;
};

struct stu *getStudent()
{
	// 포인터를 이용하여 동적할당을 받는다.
	struct stu *p1;
	p1 = malloc(sizeof(struct stu));
	
	// 구조체의 내용을 입력한다.
	printf("학번 입력: ");
	scanf("%d", &p1->id);

	printf("이름 입력: ");
	scanf("%s", p1->name);
	
	printf("평점 입력: ");
	scanf("%f", &p1->gpa);
	
	// 포인터(주소)를 돌려준다.
	return p1;
}

void printStudent(struct stu *kim)
{
	printf("학번: %d   이름: %s   평점: %.1f\n", (*kim).id, kim->name, (*kim).gpa);
}


int main(int ac, char *av[])
{
	struct stu *kim;

	kim = getStudent(); // 주소p1을 돌려받아 kim에 저장. *kim에는 6019, KimMinsu, 4.3이 있다. 

	printStudent(kim);

}
