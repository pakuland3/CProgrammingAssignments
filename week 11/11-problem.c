#include <stdio.h>
#include <stdlib.h>
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

void printInfo(){
    for(int i=1;i<SIZE;i++){
        if(stuff[i].id==-1) continue;
        printf("\n상품 ID : %d\n",i);
        printf("상품명 : %s\n",stuff[i].name);
        printf("상품 가격 : %d\n",stuff[i].price);
        printf("입고량 : %d\n",stuff[i].inputs);
        printf("판매량 : %d\n",stuff[i].sells);
        printf("총 판매 금액 : %d\n",stuff[i].price*stuff[i].sells);
    }
}

void remainStuffs(){
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

void saveFile(){
	if((fp=fopen("current_stock.bin","wb"))==NULL){
		printf("error");
		exit(-1);
	}
	fwrite(stuff,sizeof(INFO),SIZE,fp);
	fclose(fp);
}

void loadFile(){
	if((fp=fopen("current_stock.bin","rb"))==NULL){
		printf("error");
		exit(-1);
	}
	fread(stuff,sizeof(INFO),SIZE,fp);
	fclose(fp);
}

int main(){
    for(int i=1;i<SIZE;i++){
        stuff[i].id=-1;
        stuff[i].sells=0;
    }
	int sign;
	while(1){
		printf("[쇼핑몰 관리 프로그램]\n>원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별 현황, 4. 전체 현황,\n5. 상품정보 저장 6. 상품정보 가져오기 7. 종료)\n>");
		scanf("%d",&sign);
		if(sign==7) break;
		if(sign==6) loadFile();
		if(sign==5) saveFile();
		if(sign==4) remainStuffs();
		if(sign==3) printInfo();
		if(sign==2) sellStuffs();
		if(sign==1) putStuffs();
		printf("\n\n");
	}
	return 0;
}