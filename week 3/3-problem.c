#include <stdio.h>
int n;
double b,c;
int a[100],d[100];
int mini,maxi;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b+=a[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&d[i]);
		if(d[i]<d[mini]) mini=i;
		if(d[i]>d[maxi]) maxi=i;
		a[i]-=d[i];
		c+=d[i];
	}
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n총 판매량 : %d (판매율 %lf%)\n",(int)c,c/b*100);
	printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n",maxi+1,d[maxi]);
	printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n",mini+1,d[mini]);
	for(int i=0;i<n;i++){
		if(a[i]<3) printf("상품 ID %d : 재고부족(%d)\n",i+1,a[i]);	
	}
	return 0;
}
