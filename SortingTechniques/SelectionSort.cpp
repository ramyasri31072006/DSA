/*it is an comparison based algorithm
asume frist element in array as smallest element
search for smallest element in the array and swap with it after complection every loop smallest element of a array get sorted 
*/

#include<stdio.h>
void selection_sort(int a[],int n){
	int min;
	for(int i=0;i<n;i++){
		min=i;//asume frist element as min
		for(int j=i+1;j<n;j++){//used for comparing elements in array
			if(a[min]>a[j]){//finds small num in array
				min=j;
			}
			int temp=a[i];//swap small num with assuming element
			a[i]=a[min];
			a[min]=temp;
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
	selection_sort(a,n);
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
//time complexity--o(n^2)
//space complexity--O(1)
