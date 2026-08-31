/* it works on divide and conquer technique
it chose a pivot element and divide into subarrays until the sub array reaches to single element */
#include<stdio.h>
void quick_sort(int a[],int lb,int ub){
	int pivot,start,end;
	if(lb<ub){
	
		pivot=lb;//asume  pivot element is at lower boundary
		start=lb;
		end=ub;
		if(start<end){
			while(a[start]<=a[pivot]){//if the element in start is <=pivot increment start
				start++;
			}
			while(a[end]>a[pivot]){//if the element in end greater than pivot decrement end
				end--;
			}
			if(start<end){//if start is < end  then swap end and start
				int temp=a[start];
				a[start]=a[end];
				a[end]=temp;
			}
		}
		int temp=a[pivot];//finally swap pivot with end to get it's atual position
		a[pivot]=a[end];
		a[end]=temp;
	//do the same process recursivly in remaing 2 parts
	quick_sort(a,lb,end-1);
	quick_sort(a,end+1,ub);
}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	
}
//time complexity--o(n^2),avg(0(nlogn))
//space complexity--o(n)
