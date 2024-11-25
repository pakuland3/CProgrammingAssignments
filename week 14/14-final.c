#include <stdio.h>
#include <string.h>
#define MAX 17

int binaryToDecimal(char *n){
    char tmp[MAX];
    int num=0;
    int cur=1;
    for(int i=0;i<16;i++) tmp[i]=n[i];
    if(n[0]=='1'){
        if(tmp[15]=='0'){
            int d=0;
            for(int i=15;i>0;i--){
                if(tmp[i]=='1'){
                    d=1;
                    tmp[i]='0';
                    for(int j=i;j<16;j++) tmp[j]='1';
                    break;
                }
            }
            if(!d) return -65536;
        }
        else tmp[15]='0';
        for(int i=0;i<16;i++) tmp[i]=(tmp[i]=='1'?'0':'1');
    }
    for(int i=15;i>0;i--){
        if(tmp[i]=='1') num+=cur;
        cur*=2;
    }
    return (n[0]=='1'?-num:num);
}

void getBinary(char *from, char *to){
    int idx=15;
    for(int i=15;i>=0;i--){
        if(!from[i]) continue;
        to[idx--]=from[i];
    }
    for(;idx>=0;idx--) to[idx]='0';
}

int main(){
    char input1[MAX]={0,},input2[MAX]={0,},binary1[MAX]={0,},binary2[MAX]={0,};
    char op[2];
    printf("<<<<input>>>>\n");
    gets(input1);
    gets(op);
    gets(input2);
    getBinary(input1,binary1);
    getBinary(input2,binary2);
    int n1=binaryToDecimal(binary1);
    int n2=binaryToDecimal(binary2);
    int result;
    int b=0;
    switch(op[0]){
        case '+': result=n1+n2; break;
        case '-': result=n1-n2; break;
        case '*': result=n1*n2; break;
        case '/': result=n1/n2; break;
        case '%': result=n1%n2; break;
        default: b=1;
    }
    if(b){
        printf("bad operator...\n");
        return 0;
    }
    printf("%s(%d) %c %s(%d) = %d",binary1,n1,op[0],binary2,n2,result);
    return 0;
}