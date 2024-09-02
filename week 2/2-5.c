#include <stdio.h>

int main(){
    int i=10;
    int *p;
    p=i;
    *p=20;
    printf("%d\n",i);
    return 0;
}