#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 학생 정보를 담는 구조체
typedef struct student
{
    char *name; // 이름, 동적할당 필요
    char id[9]; // 학번
    int year; // 학년
} stu_t;

// 전체를 아우르는 구조체
typedef struct stlist
{
    int numStu;
    stu_t  **stulist;
} stlist ;

// 학생 정보 구조체에 입력받는다.
stu_t *getStudent(FILE *stuinfo) //-------------------
{
    stu_t *ps; // 학생 정보를 가리키는 포인터
    ps = (stu_t*)malloc(sizeof(stu_t)); // 학생 정보의 크기만큼  동적할당-------------

    // 학생 이름 입력
    char temp_name[200];

    fscanf(stuinfo, "%s", temp_name);  // ------------------

    ps->name = (char*)malloc(strlen(temp_name)+1); // 이름 크기만큼 동적할당----------
    strcpy(ps->name, temp_name);

    // ----------------------------
    fscanf(stuinfo, "%s %d", ps->id, &ps->year); // 학생 학번, 학년 입력 -> 구조체 완성

    return ps;
}


// call getStudent()로 인덱스별로 학생수만큼 입력받는다.
stlist *getStuList(FILE *stuinfo)  // -------------------매개변수만 추가
{
    stlist *psl; // = main의 theStList
    psl = (stlist*)malloc(sizeof(stlist)); // stlist의 2개 요소만큼 동적할당---------------

    fscanf(stuinfo ,"%d", &psl->numStu); // 학생수 입력  // ----------------------- scanf-> fscanf
    psl->stulist = (stu_t**)malloc(sizeof(stu_t*) * psl->numStu); // 학생수만큼 *(곱하기) 동적할당

    for(int i = 0 ; i < psl->numStu ; i++)
    {
        psl->stulist[i] = getStudent(stuinfo); //----------------매개변수만 추가-
    }

    return psl;
}

void printAll(stlist *psl)
{
    for(int i = 0 ; i < psl->numStu ; i++)
    {
        printf("%s %s %d\n", psl->stulist[i]->name, psl->stulist[i]->id, psl->stulist[i]->year);
    }
}

void sort(stlist *psl)
{
    //FILE *sort = fopen("SortedData", "w");   // 새로운 파일(정렬된 텍스트) 만들기 연습. w : 쓰기모드.

    for(int j = 0 ; j < psl->numStu - 1 ; j++)
    {
        for(int i = 0; i < psl->numStu - 1 ; i++)
       {
            if( strcmp(psl->stulist[i]->name, psl->stulist[i+1]->name) > 0)
            {
                stu_t *temp;

                temp = psl->stulist[i];
                psl->stulist[i] = psl->stulist[i+1];
                psl->stulist[i+1] = temp;
            }
        }
    }

    /*for(int i = 0 ; i < psl->numStu ; i++)
    {
        fprintf(sort, "%s %s %d\n", psl->stulist[i]->name, psl->stulist[i]->id, psl->stulist[i]->year);
    } */
}

int main(int ac, char *av[])
{
    stlist *theStList; // 전체를 아우르는 구조체를 가리키는 포인터


    FILE *stuinfo; //----------------------------------
    stuinfo = fopen("studentinfo.txt", "r"); //---------------------------------


    theStList = getStuList(stuinfo);  //------------------------매개변수만 추가

    printAll(theStList);

    sort(theStList);

    printf("\n-----------정렬 후---------\n");
    printAll(theStList);


    fclose(stuinfo); //------------------

    return 0;
}
