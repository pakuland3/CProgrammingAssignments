#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int main(){
    int number[SIZE];
    int most,tmp;
    srand(time(NULL));
    for(int i=0;i<SIZE;i++) number[i]=rand()%10000+1;
    for(int i=0;i<SIZE-1;i++){
        most=i;
        for(int j=i+1;j<SIZE;j++) if(number[most]<number[j]) most=j;
        swap(&number[i],&number[most]);
    }
    for(int i=0;i<SIZE;i++){
        printf("%5d\t",number[i]);
        if((i+1)%10==0) printf("\n");
    }
    return 0;
}