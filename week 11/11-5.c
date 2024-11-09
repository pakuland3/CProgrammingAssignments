#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}POINT;

int inputMenu(){
    int input;
    printf("1. 만들기, 2. 출력하기, 3. 클리어, 4. 파일 저장, 5. 파일 로드, -1. 종료 : ");
    scanf("%d",&input);
    return input;
}

POINT* makePoint(int *count, int *sizes){
    scanf("%d",&sizes[*count]);
    POINT *p=(POINT*)malloc(sizes[*count]*sizeof(POINT));
    for(int i=0;i<sizes[*count];i++){
        p[i].x=rand()%100;
        p[i].y=rand()%100;
    }
    *count=*count+1;
    printf("잘 만들었습니다.\n");
    return p;
}

void printPoint(POINT *points[], int count, int sizes[]){
    printf("%d\n",sizes[0]);
    for(int i=0;i<count;i++){
        for(int j=0;j<sizes[i];j++){
            printf("x:%d, y:%d\n",(points[i]+j)->x,(points[i]+j)->y);
        }
    }
}

void freePoints(POINT *points[], int count){
    for(int i=0;i<count;i++) free(points[i]);
    printf("프로그램을 종료합니다.");
}

int saveFile(POINT *points[], int count, int *sizes){
    FILE *fp;
    if((fp=fopen("points.bin","wb"))==NULL) return 0;
    for(int i=0;i<count;i++){
        fwrite(&sizes[i],sizeof(int),1,fp);
        fwrite(points[i],sizeof(POINT),sizes[i],fp);
    }
    int endoffile=0;
    fwrite(&endoffile,sizeof(int),1,fp);
    fclose(fp);
    return 1;
}

int loadFile(POINT *points[], int *count, int *sizes){
    FILE *fp;
    if((fp=fopen("points.bin","rb"))==NULL) return 0;
    fseek(fp,0,SEEK_END);
    int fSize=ftell(fp);
    // int fCount=fSize/sizeof(POINT);
    rewind(fp);
    int idx=0;
    while(1){
        fread(&sizes[idx],sizeof(int),1,fp);
        if(sizes[idx]==0) break;
        points[idx]=(POINT*)malloc(sizeof(POINT)*sizes[idx]);
        fread(points[idx],sizeof(POINT),sizes[idx],fp);
        idx++;
    }
    fclose(fp);
    *count=idx;
    return fSize;
}

int main(){
    int menu;
    POINT *points[100];
    int sizes[100];
    int count=0;
    do{
        menu=inputMenu();
        switch(menu){
            case 1:
                points[count]=makePoint(&count,sizes);
                break;
            case 2:
                printPoint(points,count,sizes);
                break;
            case 3:
                system("cls");
                break;
            case 4:
                saveFile(points,count,sizes);
                break;
            case 5:
                loadFile(points,&count,sizes);
                break;
            case -1:
                freePoints(points,count);
                break;
        }
    }
    while(menu!=-1);
    return 0;
}