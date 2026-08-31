#include<stdio.h>
int linear_search(int a[],int n,int tar){
	if(n==0) return 0;
	else if(a[n-1]==tar)return 1;
	else return linear_search(a,n-1,tar);
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int tar;
	scanf("%d",&tar);
	if(linear_search(a,n,tar)){
		printf("target found\n");
	}
	else{
		printf("target not found\n");
	}
}
