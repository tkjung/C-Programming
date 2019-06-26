#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
	char *name; // 최대길이 200바이트
	char id[15]; // 주민번호 - 포함
	char dept_code; // 1~100의 정수
}emp;

emp* getEmployee() {
	emp * ep = (emp*)malloc(sizeof(emp)); // 구조체 포인터형태의 매모리 할당
	char buffer[200];
	printf("Enter the name\n");
	scanf("%s",buffer);
	ep->name =(char*)malloc(sizeof(strlen(buffer))+1); // 문자열의 크기 + 1
	strcpy(ep->name,buffer);
	printf("Enter the ID\n");
	scanf("%s",ep->id);

	while(1) {
		printf("Enter the Code\n");
		scanf("%d",&ep->dept_code);
		if(ep->dept_code >= 1 && ep->dept_code <= 100) break;
	}
	return ep;
}

emp* copyEmployee(emp * ep){
	emp *cEp = (emp*)malloc(sizeof(emp));
	cEp->name =(char*)malloc(sizeof(strlen(ep->name)));
	strcpy(cEp->name,ep->name);
	strcpy(cEp->id, ep->id);
	cEp->dept_code = ep->dept_code;
	return cEp;
}

void printEmployee(emp * ep) {

	printf("NAME:%s\n",ep->name);
	printf("ID:%s\n",ep->id);
	printf("DEPTCODE:%d\n",ep->dept_code);
}

int main(int ac, char *av[]) {

	emp *ep1, *ep2;
	ep1 = getEmployee();
	ep2 = copyEmployee(ep1);
	printEmployee(ep1);
	printEmployee(ep2);

	ep1->name[0] = 'A';
	printEmployee(ep1);
	printEmployee(ep2);

}
