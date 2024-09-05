#include <stdio.h>
int n,tmp;
int a[100];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		a[i]-=tmp;
	}
	scanf("%d",&tmp);
	printf("%d\n",a[tmp-1]);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}
