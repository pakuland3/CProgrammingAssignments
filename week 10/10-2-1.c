#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){
    char input[SIZE];
    FILE *fp;
    if((fp=fopen("output.bin","rb"))==NULL){
        printf("error...");
        return 0;
    }
    int i=0;
    while(!feof(fp)) fread(&input[i++],1,1,fp);
    input[--i]='\0';
    printf("%s",input);
    fclose(fp);
    return 0;
}