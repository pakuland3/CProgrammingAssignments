#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}POINT;

int main(){
    POINT *points;
    int count;
    scanf("%d",&count);
    points=(POINT*)malloc(count*sizeof(POINT));
    for(int i=0;i<count;i++){
        points[i].x=rand()%100;
        points[i].y=rand()%100;
        printf("x - %d, y - %d\n",points[i].x,points[i].y);
    }
    free(points);
    return 0;
}