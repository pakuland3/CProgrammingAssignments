#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int number[6];
    int NO;
    int bonus;
}LOTTO;

LOTTO createAuto(int NO){
    LOTTO l;
    l.NO=NO;
    int vis[46]={0,};
    for(int i=0;i<6;i++){
        while(1){
            l.number[i]=rand()%45+1;
            if(vis[l.number[i]]) continue;
            vis[l.number[i]]=1;
            break;
        }
    }
    return l;
}

LOTTO createManual(int NO){
    LOTTO l;
    l.NO=NO;
    int vis[46]={0,};
    for(int i=0;i<6;i++){
        while(1){
            printf("input number #%d : ",i+1);
            scanf("%d",&l.number[i]);
            if(vis[l.number[i]]){
                printf("로또 번호가 중복되었습니다.\n다시 입력해주세요.\n");
                continue;
            }
            vis[l.number[i]]=1;
            break;
        }
    }
    return l;
}

void printLotto(LOTTO l){
    printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n",
    l.NO,l.number[0],l.number[1],l.number[2],l.number[3],l.number[4],l.number[5]);
    printf("BONUS : %d\n",l.bonus);
}

int main(){
    srand(time(NULL));
    LOTTO l;
    // l=createManual(20240834);
    l=createAuto(20240834);
    printLotto(l);
    return 0;
}