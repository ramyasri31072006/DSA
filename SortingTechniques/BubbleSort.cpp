#include<stdio.h>
void bubble_sort(int a[],int n){
	for(int i=1;i<n;i++){// this loop runs n-1 times to sort array,after competion very loop max element of array will be sorted
		for(int j=0;j<n-i;j++){//it helps to compare elements of unsorted array
			if(a[j]>a[j+1]){//if present element is greater than adjacent element swap them
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubble_sort(a,n);
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
//time complexity--o(n^2)
//space complexity--O(1)
