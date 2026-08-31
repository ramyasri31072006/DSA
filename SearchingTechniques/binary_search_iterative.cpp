#include<stdio.h>
int binary_search(int a[],int n, int tar){
	int lb=0;
	int ub=n-1;
	while(lb<=ub){
		int mid=(lb+ub)/2;
		if(a[mid]==tar){
			return 1;
		}
		else if(tar<a[mid]){
			ub=mid-1;
		}
		else{
			lb=mid+1;
		}
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
	
if(	binary_search(a,n,tar)){
	printf("target found");
}
else printf("target not found");
	
}
