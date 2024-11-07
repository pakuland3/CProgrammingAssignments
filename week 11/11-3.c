#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}POINT;

int menu;
POINT *points[100];
int size[100];
int count=0;

int inputMenu(){
    int input;
    printf("메뉴 입력(1. 구조체 만들기, 2. 구조체 출력하기, -1. 종료) : ");
    scanf("%d",&input);
    return input;
}

POINT* makePoint(){
    scanf("%d",&size[count]);
    POINT *p=(POINT*)malloc(size[count]*sizeof(POINT));
    for(int i=0;i<size[count];i++){
        p[i].x=rand()%100;
        p[i].y=rand()%100;
    }
    count++;
    printf("잘 만들었습니다.\n");
    return p;
}

void printPoint(POINT *points[], int count, int size[]){
    for(int i=0;i<count;i++){
        for(int j=0;j<size[i];j++) printf("x:%d, y:%d\n",points[i][j].x,points[i][j].y);
    }
}

void freePoints(POINT *points[], int count){
    for(int i=0;i<count;i++) free(points[i]);
    printf("프로그램을 종료합니다.");
}

int main(){
    while(menu=inputMenu()){
        if(menu==1) points[count]=makePoint();
        if(menu==2) printPoint(points,count,size);
        if(menu==-1){
            freePoints(points,count);
            break;
        }
    }
    return 0;
}