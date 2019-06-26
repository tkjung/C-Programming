#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char * name; // 학생 이름을 가리키는 포인터. 동적할당 필요.
    char id[9]; // 60191234  처럼
    int year;
} stu_t;

// 전체 학생을 아우르는 구조체
typedef struct stlist {
    int numStu;  // 학생 수
    stu_t **stulist;  // 동적 할당을 받은 학생 구조체들을 가리키는 포인터 배열로 사용.
} stlist;

// 포인터 배열 중 하나가 구조체 stu_t를 가리킨다. stu_t는 학생의 정보 3가지를 갖는다.
stu_t *getStudent()
{
    stu_t *pi; // 학생 info를 가리키는 pointer
    pi = (stu_t*)malloc(sizeof(stu_t)); // 학생정보가 차지하는 공간만큼 동적할당------

    char temp_name[200];
    scanf("%s", temp_name); // 학생 이름 입력
    (*pi).name = (char*)malloc(strlen(temp_name) + 1); // 학생이름 공간만큼  동적할당------
    strcpy(pi->name, temp_name); // 복사
    // 한줄로는: s->name = strdup(temp_name); // 학생 이름 동적할당+복사

    scanf("%s %d", (*pi).id, &pi->year); // 학생 학번, 학년 입력. 구조체 완성

    return pi;
}

// 구조체 stlist를 가리키는 포인터. 반환 포인터는 메인함수의 *theStList가 받는다.
stlist *getStuList()
{
    stlist *pl; // 학생 list를 가리키는 pointer
    pl = (stlist*)malloc(sizeof(stlist)); // stlist 구조체가 차지하는 공간만큼 동적할당----

    scanf("%d", &pl->numStu);

    pl->stulist = (stu_t**)malloc(sizeof(stu_t*) *pl->numStu ); // 학생수만큼 동적할당-----
    
        // pl->stlist[0~numStu] 학생정보 반복 입력 = call getStudent()
    for(int i = 0 ; i < pl->numStu ; i++) // 조건문 우항 numStu (x), pl->numStu (o)
    {
        ////////// 이중 포인터에도 인덱스를 넣을 수 있다!!!!!!!-------------------
        pl->stulist[i] = getStudent();
    }

    return pl;
}

// 출력 함수
void printAll(stlist *pl)
{
    for (int i = 0 ; i < pl->numStu ; i++)
    {
        printf("%s %s %d\n", pl->stulist[i]->name, pl->stulist[i]->id, pl-> stulist[i]->year);
    }
}


// 정렬함수
void sort(stlist *pl)
{
    for(int i = 0 ; i < pl->numStu -1 ; i++) // 조건문 numStu (x), pl->numStu (o)
    {
        for(int j = 0 ; j < pl->numStu -1 ; j++)
        {
            // 윗이름이 아랫이름보다 나중 알파벳이면
            if(strcmp(pl->stulist[j]->name, pl->stulist[j+1]->name) > 0)
            {
                // 포인터끼리 바꿔준다.
                stu_t *temp; // 학생정보 바꿔줄 임시 포인터
                temp = pl->stulist[j]; // 10010번지[이름:bb]를 가리키던 포인터를 temp도 가리킴
                (*pl).stulist[j] = pl->stulist[j+1]; // 10010번지도 10020번지[이름:aa] 가리키게
                (*pl).stulist[j+1] = temp; // 10020번지가 [이름:bb]를 가리키게 함.
            }
        }
    }
}


int main(){
    stlist * theStList;
    // *theStuList는 stlist 구조체를 가리킨다. stlist는 2개 요소만을 갖는다.

    theStList = getStuList( );

    printAll(theStList);

    sort(theStList);  // 이름을 기준으로 오름차순 정렬

    printf("-------------정렬 후---------------\n");
    printAll(theStList);

    return 0;
}
