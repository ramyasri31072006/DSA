#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int tar,f=0;
	scanf("%d",&tar);
	for(int i=0;i<n;i++){
		if(a[i]==tar){
			printf("target found\n");
			f=1;
			break;
		}
	}
	if(f==0){
		printf("target not found");
	}
}
