#include<stdio.h>
void insertion_sort(int a[],int n){
	for(int i=1;i<n;i++){//this loop works for unsorted part of array
		int temp=a[i];//pick the frist element of unsorted array
		int j=i-1;//end idx of sorted array
		while(j>=0&&a[j]>temp){//it helps to insert the unsorted element in it's position
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n);
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
//time complexity--o(n^2)
//space complexity--o(1)
