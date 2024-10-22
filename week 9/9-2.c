#include <stdio.h>

int getLine(char* line){
    int ch;
    int i=0;
    while((ch=getchar())!='\n') line[i++]=ch;
    line[i]='\0';
    return i;
}

char input[100];

int main(){
    FILE *fp_src,*fp_dest;
    if((fp_src=fopen("output.txt","r"))==NULL){
        printf("error");
        return 0;
    }
    if((fp_dest=fopen("output2.txt","w"))==NULL){
        printf("error");
        return 0;
    }
    while(!feof(fp_src)){
        fgets(input,100,fp_src);
        printf("출력 중\n");
        fputs(input,fp_dest);
    }
    fclose(fp_src);
    fclose(fp_dest);
    return 0;
}