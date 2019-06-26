#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct branch {
    char *name; // 대리점 이름 저장
    int *sale;
}branch;

typedef struct branchList{
    int cNum;   //차 종류 갯수
    int bNum;   // 대리점 갯수
    char **car; // 차의 종류 저장해줄 더블포인터
    branch ** br;
}bList;

branch * getBranch(FILE * bI) {
    branch * br =(branch*)malloc(sizeof(branch));
    char Buffer[100];
    fscanf(bI,"%s",Buffer);
    br->name =(char*)malloc(strlen(Buffer) + 1);
    strcpy(br->name,Buffer);

    return br;
}

bList * getBranchList(FILE * bI, FILE * cI) {
    bList * bL = (bList*)malloc(sizeof(bList));
    fscanf(bI,"%d",&bL->bNum); // 대리점 갯수 입력받기
    fscanf(cI,"%d",&bL->cNum); // 차종류
    char Buffer[100];
    bL->br =(branch**)malloc(sizeof(branch*) * bL->bNum);
    bL->car =(char**)malloc(sizeof(char*) * bL->cNum + 1); // 합계

    for (int i = 0 ; i < bL->bNum ; i++) {
        bL->br[i] = getBranch(bI);
    }
    for(int i = 0 ; i <= bL->cNum ; i++) {
        fscanf(cI,"%s",Buffer);
        bL->car[i] = malloc(strlen(Buffer)+1);
        if(bL->cNum == i) {
            bL->car[i] = malloc(sizeof(char) * 3);
            bL->car[i] = "합계";
            break;
        }
        strcpy(bL->car[i],Buffer);
    }
    return bL;
}

void getSales (bList ** List,FILE * sI);
void printAll(bList * List);
int main() {
    FILE * salesInfo = fopen("sales.txt","r");
    FILE * branchInfo = fopen("branch.txt","r");
    FILE * carInfo = fopen("car.txt","r");
    bList * bList = getBranchList(branchInfo,carInfo);

    for (int i = 0 ; i <= bList->cNum ; i++) {
        printf("%s  ",bList->car[i]);
    }

    printf("\n");
    getSales(&bList,salesInfo);
    printAll(bList);
}
void printAll(bList * List) {

    for (int i = 0 ; i < List->bNum ; i++) {
        printf("%s ",List->br[i]->name);
        for(int j = 0 ; j<= List->cNum ; j++) {
            printf("%d ",List->br[i]->sale[j]);
        }
        printf("\n");
    }

}
void getSales (bList ** List,FILE * sI) {
    for(int i = 0 ; i < (*List)->bNum; i++ ) {
        (*List)->br[i]->sale = (int *) malloc(sizeof(int) * (*List)->cNum );
        (*List)->br[i]->sale[(*List)->cNum] = 0;
        for(int j = 0 ; j < (*List)->cNum; j++ ) {
            fscanf(sI,"%d",&(*List)->br[i]->sale[j]);
            (*List)->br[i]->sale[(*List)->cNum] += (*List)->br[i]->sale[j];
        }
    }
}
