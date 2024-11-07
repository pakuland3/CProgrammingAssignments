#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int x,y;
} POINT;

POINT makePoint(){
    POINT p;
    scanf("%d%d",&p.x,&p.y);
    return p;
}

void makeRandomPoints(POINT *p, int size){
    srand(time(NULL));
    for(int i=0;i<size;i++){
        p[i].x=rand()%100;
        p[i].y=rand()%100;
    }
}

void printPoints(POINT *p, int size){
    for(int i=0;i<size;i++) printf("point[%d] = x : %d, y = %d\n",i,p[i].x,p[i].y);
}

void saveFile(POINT *p, int size){
    FILE *fp;
    if((fp=fopen("struct.bin","wb"))==NULL) exit(-1);
    fwrite(p,sizeof(POINT),size,fp);
    fclose(fp);
}

void loadFile(POINT *p, int size){
    FILE *fp;
    if((fp=fopen("struct.bin","rb"))==NULL) exit(-1);
    fread(p,sizeof(POINT),size,fp);
    fclose(fp);
} 

int main(){
    FILE *fp;
    POINT p[10];
    POINT p2;
    // makeRandomPoints(p,10);
    loadFile(p,10);
    printPoints(p,10);
    // saveFile(p,10);
    if((fp=fopen("struct.bin","rb"))==NULL) return -1;
    fseek(fp,sizeof(POINT)*3,SEEK_SET);
    int pi=ftell(fp);
    printf("%d\n",pi);
    fread(&p2,sizeof(POINT),1,fp);
    printf("p2 -> x : %d, y : %d\n",p2.x,p2.y);
    fseek(fp,sizeof(POINT)*-2,SEEK_END);
    fread(&p2,sizeof(POINT),1,fp);
    printf("p2 -> x : %d, y : %d\n",p2.x,p2.y);
    fseek(fp,0,SEEK_END);
    printf("%d",ftell(fp));
    fclose(fp);
    return 0;
}