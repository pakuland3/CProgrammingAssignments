#include <stdio.h>
#define SIZE 6

FILE *fp;

typedef struct{
    int id;
    int price;
    char name[SIZE];
    int inputs;
    int sells;
} INFO;

INFO stuff[SIZE];

double totalinputs=0,totalsells=0;
int mini=-1,maxi=-1;

void update(){
	for(int i=1;i<SIZE;i++){
	    if(stuff[i].id==-1) continue;
		if(mini==-1) mini=i;
		else if(stuff[mini].sells>stuff[i].sells) mini=i;
		if(maxi==-1) maxi=i;
		else if(stuff[maxi].sells<stuff[i].sells) maxi=i;
	}
}

void putStuffs(){
	int id;
	printf("상품ID : ");
	scanf("%d",&id);
	stuff[id].id=id;
	putchar('\n');
    printf("상품명 : ");
    scanf("%s",stuff[id].name);
    putchar('\n');
    printf("입고량 : ");
    scanf("%d",&stuff[id].inputs);
    totalinputs+=stuff[id].inputs;
    putchar('\n');
    printf("판매가격 : ");
    scanf("%d",&stuff[id].price);
    putchar('\n');
	update();
}

void sellStuffs(){
    int id;
	printf("상품 ID : ");
	scanf("%d",&id);
	putchar('\n');
	if(stuff[id].id==-1){
	    printf("해당 ID를 가진 상품이 존재하지 않습니다.\n");
	    return;
	}
	int tmp;
	printf("판매량 : ");
	scanf("%d",&tmp);
	stuff[id].inputs-=tmp;
	stuff[id].sells+=tmp;
	totalsells+=tmp;
	update();
}

// file the information

void printInfo(){
	printf("\n파일에 기록하고 싶으시다면 1, 바로 출력하고 싶으면 2번을 입력하세요.\n");
	int sign;
	scanf("%d",&sign);
	if(sign==2){
	    for(int i=1;i<SIZE;i++){
	        if(stuff[i].id==-1) continue;
	        printf("상품 ID : %d\n",i);
	        printf("상품명 : %s\n",stuff[i].name);
	        printf("상품 가격 : %d\n",stuff[i].price);
	        printf("입고량 : %d\n",stuff[i].inputs);
	        printf("판매량 : %d\n",stuff[i].sells);
	        printf("총 판매 금액 : %d\n",stuff[i].price*stuff[i].sells);
	    }
	}
	else{
	    for(int i=1;i<SIZE;i++){
	        if(stuff[i].id==-1) continue;
	        fprintf(fp,"상품 ID : %d\n",i);
	        fprintf(fp,"상품명 : %s\n",stuff[i].name);
	        fprintf(fp,"상품 가격 : %d\n",stuff[i].price);
	        fprintf(fp,"입고량 : %d\n",stuff[i].inputs);
	        fprintf(fp,"판매량 : %d\n",stuff[i].sells);
	        fprintf(fp,"총 판매 금액 : %d\n",stuff[i].price*stuff[i].sells);
	    }
	}
}

// file the information

void remainStuffs(){
	printf("\n파일에 기록하고 싶으시다면 1, 바로 출력하고 싶으면 2번을 입력하세요.\n");
	int sign;
	scanf("%d",&sign);
	if(sign==2){
		printf("재고수량 : ");
		for(int i=1;i<SIZE;i++){
		    if(stuff[i].id==-1){
		        printf("-1 ");
		        continue;
		    }
		    printf("%d ",stuff[i].inputs);
		}
		printf("\n총 판매량 : %d (판매율 %lf%)\n",(int)totalsells,totalsells/totalinputs*100);
		printf("가장 많이 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n",maxi,stuff[maxi].name,stuff[maxi].sells);
		printf("가장 적게 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n",mini,stuff[mini].name,stuff[mini].sells);
		for(int i=1;i<SIZE;i++){
			if(stuff[i].id!=-1 && stuff[i].inputs<3) printf("상품 ID %d, 상품명 : %s 재고부족(%d)\n",i,stuff[i].name,stuff[i].inputs);
		}
	}
	else{
		fprintf(fp,"재고수량 : ");
		for(int i=1;i<SIZE;i++){
		    if(stuff[i].id==-1){
		        fprintf(fp,"-1 ");
		        continue;
		    }
		    fprintf(fp,"%d ",stuff[i].inputs);
		}
		fprintf(fp,"\n총 판매량 : %d (판매율 %lf%)\n",(int)totalsells,totalsells/totalinputs*100);
		fprintf(fp,"가장 많이 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n",maxi,stuff[maxi].name,stuff[maxi].sells);
		fprintf(fp,"가장 적게 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n",mini,stuff[mini].name,stuff[mini].sells);
		for(int i=1;i<SIZE;i++){
			if(stuff[i].id!=-1 && stuff[i].inputs<3) fprintf(fp,"상품 ID %d, 상품명 : %s 재고부족(%d)\n",i,stuff[i].name,stuff[i].inputs);
		}
	}
}

int main(){
	if((fp=fopen("current_stock.txt","w"))==NULL){
		printf("error");
		return 0;
	}
    for(int i=1;i<SIZE;i++){
        stuff[i].id=-1;
        stuff[i].sells=0;
    }
	int sign;
	while(1){
		printf("[쇼핑몰 관리 프로그램]\n>원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별 현황, 4. 전체 현황 5. 종료)\n>");
		scanf("%d",&sign);
		if(sign==5) break;
		if(sign==4) remainStuffs();
		if(sign==3) printInfo();
		if(sign==2) sellStuffs();
		if(sign==1) putStuffs();
		printf("\n\n");
	}
	fclose(fp);
	return 0;
}
