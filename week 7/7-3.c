#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

typedef struct{
    int x,y;
} POINT;

void input_random_point(POINT* p, int size){
    for(int i=0;i<size;i++){
        (p+i)->x=rand()%101;
        (p+i)->y=rand()%101;
    }
}

void swap_point(POINT* p1, POINT* p2){
    POINT tmp;
    tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}

void print_point_array(POINT* p, int size){
    for(int i=0;i<size;i++) printf("point[%3d] : (%3d, %3d)\n",i,p[i].x,p[i].y);
}

void selection_sort_point(POINT* point, int size){
    for(int i=0;i<SIZE-1;i++){
        int least=i;
        for(int j=i+1;j<SIZE;j++){
            if(point[j].x<point[least].x) least=j;
            if(point[j].x==point[least].x && point[j].y<point[least].y) least=j;
        }
        swap_point(&point[i],&point[least]);
    }
}

int main(){
    POINT point[SIZE];
    srand(time(NULL));
    input_random_point(point,SIZE);
    print_point_array(point,SIZE);
    selection_sort_point(point,SIZE);
    printf("after sorting\n");
    print_point_array(point,SIZE);
    return 0;
}