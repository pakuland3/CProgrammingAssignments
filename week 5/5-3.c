#include <stdio.h>

char input[200];
int ch;
int i;
int lower_case_cnt[26];
int upper_case_cnt[26];
int number_cnt[10];

int main(){
    freopen("input.txt","r",stdin);
    while((ch=getchar())!=EOF){
        input[i++]=ch;
    }
    i=-1;
    while(input[++i]!='\0'){
        if('a'<=input[i] && input[i]<='z') lower_case_cnt[input[i]-'a']++;
        if('A'<=input[i] && input[i]<='Z') upper_case_cnt[input[i]-'A']++;
        if('0'<=input[i] && input[i]<='9') number_cnt[input[i]-'0']++;
    }
    printf("입력 문자열 : %s\n",input);
    for(i=0;i<26;i++) printf("%c 출현 횟수 : %d\n",i+'a',lower_case_cnt[i]);
    for(i=0;i<26;i++) printf("%c 출현 횟수 : %d\n",i+'A',upper_case_cnt[i]);
    for(i=0;i<10;i++) printf("%c 출현 횟수 : %d\n",i+'0',number_cnt[i]);
    return 0;
}