#include <stdio.h>
#include <stdlib.h>

int main(){
    char *pChar;
    int count,*pInt;
    scanf("%d",&count);
    pInt=malloc(count*sizeof(int));
    for(int i=0;i<count;i++) pInt[i]=rand()%100;
    for(int i=0;i<count;i++) printf("%d ",pInt[i]);
    pChar=pInt;
    while(getchar()!='\n');
    gets(pChar);
    puts(pChar);
    free(pChar);
    return 0;
}