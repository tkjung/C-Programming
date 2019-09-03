#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 버전4 : FILE *fp fopen, fclose, fscanf 추가.
// a.out 으로 했을 때 실행 잘 됨.


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
    int **pscorelist; // 점수 이중포인터
} stlist;

typedef struct score_t
{
    int *scores; // 국어~도덕 점수 배열
} score_t;


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

score_t *getScore(FILE *fp3)
{
    score_t *pscore;
    pscore = (score_t*)malloc(sizeof(score_t));

    pscore->scores = (int*)malloc(sizeof(int) * 5); // 성적 5개 입력가능한 크기 할당
    for(int i = 0 ; i < 5 ; i++)
    {
        fscanf(fp3, "%d", pscore->scores );
    }

    return pscore;
}


// getStudent를 call하여 간접적으로 입력하는 함수
stlist *getStList(FILE *fp, FILE *fp3)
{
    stlist *psl;
    psl = (stlist*)malloc(sizeof(stlist)); // 구조체 크기만큼 할당

    fscanf(fp,"%d", &psl->numStu); // 학생수 입력받음.

    printf("입력된 학생은 총 %d명입니다. 명단은 아래와 같습니다.\n"
            "이름  학번\n", psl->numStu);

    // 포인터 크기를 학생수만큼 할당
    psl->pstulist = (stu_t**)malloc(sizeof(stu_t*) * psl->numStu );

    for ( int i = 0 ; i < psl->numStu ; i++)
    {
        psl->pstulist[i] = getStudent(fp);
        psl->pscorelist[i] = getScore(fp3);
    }

    return psl;
}

void printAll(stlist *psl, int mode)
{
    if ( mode == 0 )
    {
        for(int i = 0 ; i < psl->numStu ; i++)
        {
            printf("%s %s\n", psl->pstulist[i]->name, psl->pstulist[i]->id);
        }
    }

    else if (mode == 1 )
    {
        int i = 0;
        int j = 0;
        for( ; i < psl->numStu ; i++)
        {
            printf("%s %s   ", psl->pstulist[i]->name, psl->pstulist[i]->id);

            for( ; j < 5 ; j++)
            {
                printf("%d   ", psl->pscorelist[j]->scores);
            }

            printf("\n");
        }
    }
}

void getCourses()
{
    printf("\n입력된 순서대로 된 성적표입니다.\n---\n");
    char courses[200];

    FILE *fp2;
    fp2 = fopen("courses.txt", "r");

    int numSubject;
    fscanf(fp2, "%d", &numSubject );

    printf("이름  학번    ");
    for(int i = 0 ; i < numSubject; i++)
    {
        fscanf(fp2, "%s", courses);
        printf("%s   ", courses);
    }
    printf("합계\n");
}

/*void sort(stlist *psl)
{

    if ( int i = 0 ; i < psl->num1


} */


int main(int ac, char *av[])
{
    //-------파일1: studata.txt ----------

    printf("학생 성적 처리 프로그램입니다.\n"
           "학생 데이터가 들어있는 파일명을 입력하세요: ");

    char data[20];
    scanf("%s", data);

    //-------강길동, 60190001만 입출력했던 초기 버전 ----------

    FILE *fp;
    fp = fopen(data, "r");

    FILE *fp3;
    fp3 = fopen("scores.txt", "r");

    stlist *psl;
    psl = getStList(fp, fp3);
    printAll(psl, 0);

    //-------파일2: courses.txt ----------

    printf("\n교과목 데이터 파일명을 입력하세요: ");

    char courses[200];
    scanf("%s", courses); // courses.txt라고 입력받는다.

    FILE *fp2;
    fp2 = fopen(courses, "r");

    int numSubject;
    fscanf(fp2, "%d", &numSubject ); // txt의 첫줄의 5를 읽는다.
    printf("교과목은 총 %d과목입니다. 과목명은 다음과 같습니다.\n\n", numSubject);

    // 과목명 입출력 반복
    for(int i = 0 ; i < numSubject; i++)
    {
        // 1회차: 국어, 2회차: 영어, 3:수학, 4: 사회, 5: 도덕
        fscanf(fp2, "%s", courses);
        printf("%s   ", courses);
    }

    //---------파일3: scores.txt ------------

    printf("\n\n성적 데이터가 들어있는 파일명을 입력하세요: ");

    char scores[20];
    scanf("%s", scores); // scores.txt라고 입력받는다.

    // FILE *fp3;
    // fp3 = fopen(scores, "r");
    getCourses();
    printAll(psl, 1);


    fclose(fp);
    fclose(fp2);
    fclose(fp3);
}



