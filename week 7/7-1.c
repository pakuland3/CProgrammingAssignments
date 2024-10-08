#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

typedef struct{
    int x,y;
} POINT;

int main(){
    POINT point[SIZE];
    srand(time(NULL));
    for(int i=0;i<SIZE;i++){
        point[i].x=rand()%101;
        point[i].y=rand()%101;
    }
    for(int i=0;i<SIZE;i++) printf("point[%3d] : (%3d, %3d)\n",i,point[i].x,point[i].y);
    for(int i=0;i<SIZE-1;i++){
        int least=i;
        for(int j=i+1;j<SIZE;j++){
            if(point[j].x<point[least].x) least=j;
            if(point[j].x==point[least].x && point[j].y<point[least].y) least=j;
        }
        POINT tmp;
        tmp=point[i];
        point[i]=point[least];
        point[least]=tmp;
    }
    printf("after sorting\n");
    for(int i=0;i<SIZE;i++) printf("point[%3d] : (%3d, %3d)\n",i,point[i].x,point[i].y);
    return 0;
}