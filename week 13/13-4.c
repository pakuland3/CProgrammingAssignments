#include <stdio.h>
#include <stdlib.h>
#define ROW 100
#define COL 100

int main(){
    int array[ROW][COL];
    int r,c;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            array[i][j]=rand()%1000;
            printf("[%3d] ",array[i][j]);
        }
        putchar('\n');
    }
    return 0;
}