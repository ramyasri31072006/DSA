/*
it  allows elements into buckets based on their nth position
and then reconstruct all the elements to get sorted array*/
#include<stdio.h>
int get_max(int a[],int n){//finds max in array
	int max=a[0];
	for(int i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	return max;
}
void radix_sort(int a[],int n){
	int m=get_max(a,n);
	int bucket[10][n],e=1;//used to check nth position
	while(m){//its runs max digits of max number times
		int count[10]={0};//intilize all colums with 0's
		//segregation
		for(int i=0;i<n;i++){
			int pos=(a[i]/e)%10;//it gives value in nth position
			bucket[pos][count[pos]]=a[i];
			count[pos]++;//increment colums count;
		}
		int k=0;
		//reconstruction
		for(int i=0;i<10;i++){//uses to check all the buckets
			for(int j=0;j<count[i];j++){
				a[k++]=bucket[i][j];
			}
		}
		e*=10;
		m/=10;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	radix_sort(a,n);
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
//time complexity--o(d*(n+k))
//d-max digits in max number
//k-no.of bukets(10)
//space complexity--o(n+k)
