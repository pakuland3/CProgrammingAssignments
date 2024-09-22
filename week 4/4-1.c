#include <stdio.h>

int main(){
    char message[]="char pointer";
    printf("%s\n",message);
    for(int i=0;;i++){
        if(message[i]==0) break;
        message[i]='0';
    }
    printf("%s",message);
    return 0;
}