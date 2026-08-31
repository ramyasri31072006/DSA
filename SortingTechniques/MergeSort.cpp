/*It works on divide and conquer techique
the was divided into list of sublists until the sublist has single element
we compare sorted arrays and merge them into other array 
finally copy the merged array which is sorted into given array */
#include<stdio.h>
void merge(int a[],int lb,int mid,int ub){
	int i,j,k;
	i=lb;
	j=mid+1;
	k=0;
	int b[ub-lb+1];
	while(i<=mid&&j<=ub){
		if(a[i]<=a[j]){//if element in 1st array is small the put that element frist
			b[k++]=a[i++];
		}
		else{//if not put 2nd array element
			b[k++]=a[j++];
		}
	}
	while(i<=mid){// if all the elements 2nd array was completed then put remainng values of i into the  remaining idxies
		b[k++]=a[i++];
	}
	while(j<=ub){//if all the elements 1st array was completed then put remainng values of j into the  remaining idxies
		b[k++]=a[j++];
	}
	for(int l=lb,m=0;l<=ub;l++,m++){
		a[l]=b[m];//copy the elements in original array
	}
}
void merge_sort(int a[],int lb,int ub){
	if(lb<ub){//check wheather sublist has single elementor not if not enter into loop
		int mid=(lb+ub)/2;//find's the to divide into 2 sublists
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);//merges the divided  sorted arrays
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
