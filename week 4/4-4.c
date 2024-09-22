#include <stdio.h>

int ch;
int i=0;
char message[100];

int main(){
    while((ch=getchar())!='\n') message[i++]=ch;
    printf("%s",message);
    return 0;
}