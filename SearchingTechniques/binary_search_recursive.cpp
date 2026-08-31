#include<stdio.h>
int binary_search(int a[],int lb,int ub,int tar){
	if(lb<=ub){
	int mid=(lb+ub)/2;
	if(a[mid]==tar)return 1;
	if(tar<a[mid]) return binary_search(a,lb,mid-1,tar);
	else return binary_search(a,mid+1,ub,tar);
}
	return 0;
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
	
if(	binary_search(a,0,n-1,tar)){
	printf("target found");
}
else printf("target not found");
	
}
