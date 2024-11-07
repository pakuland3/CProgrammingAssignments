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
    printf("메뉴 입력==========================\n");
    printf("1. point 만들기\n");
    printf("2. point 출력하기\n");
    printf("3. 화면 클리어\n");
    printf("-1. 종료\n");
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

int saveFile(){

}

int loadFile(){
    
}

int main(){
    do{
        menu=inputMenu();
        switch(menu){
            case 1: points[count]=makePoint();
            case 2: printPoint(points,count,size);
            case 3: system("cls");
            case 4:
            case 5: 
            case -1: freePoints(points,count);
        }
    }
    while(menu!=-1);
    return 0;
}