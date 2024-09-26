#include <stdio.h>

int n,sign;
double b,c;
int a[100],d[100];
int mini,maxi;

void update(){
	for(int i=0;i<n;i++){
		if(d[i]<d[mini]) mini=i;
		if(d[i]>d[maxi]) maxi=i;
	}
}

void putStuffs(){
	int sign;
	int tmp;
	printf(">입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n\n>");
	scanf("%d",&sign);
	if(sign==1){
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			a[i]+=tmp;
			b+=tmp;
		}
	}
	else{
		int tmp1;
		printf(">상품 ID : ");
		scanf("%d",&tmp);
		printf("\n>입고수량 : ");
		scanf("%d",&tmp1);
		a[--tmp]+=tmp1;
		b+=tmp1;
	}
}

void sellStuffs(){
	printf(">판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n\n");
	int sign,tmp;
	scanf("%d",&sign);
	if(sign==1){
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			a[i]-=tmp;
			c+=tmp;
			d[i]+=tmp;
		}	
	}
	else{
		int tmp1;
		printf(">상품 ID : ");
		scanf("%d",&tmp);
		printf("\n>판매 수량 : ");
		scanf("%d",&tmp1);
		a[--tmp]-=tmp1;
		c+=tmp1;
		d[tmp]+=tmp1;
	}
}

void remainStuffs(){
	printf("재고수량 : ");
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n총 판매량 : %d (판매율 %lf%)\n",(int)c,c/b*100);
	printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n",maxi+1,d[maxi]);
	printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n",mini+1,d[mini]);
	for(int i=0;i<n;i++){
		if(a[i]<3) printf("상품 ID %d : 재고부족(%d)\n",i+1,a[i]);	
	}
}


int main(){
	n=5;
	while(1){
		printf("[쇼핑몰 관리 프로그램]\n>원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n>");
		scanf("%d",&sign);
		if(sign==4) break;
		if(sign==3) remainStuffs();
		if(sign==2) sellStuffs();
		if(sign==1) putStuffs();
		printf("\n\n");
	}
	return 0;
}
