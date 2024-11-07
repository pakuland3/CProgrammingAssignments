#include <stdio.h>

int main(){
    int array[100];
    FILE *fp;
    if((fp=fopen("array.bin","rb"))==NULL) return -1;
    // for(int i=0;i<100;i++) array[i]=i;
    // fwrite(array,4,100,fp);
    // fread(array,sizeof(int),100,fp);
    fread(array,4,100,fp);
    for(int i=0;i<100;i++) printf("%d\n",array[i]);
    fclose(fp);
    return 0;
}