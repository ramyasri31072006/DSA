#include <stdio.h>

void recursiveInsertionSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    recursiveInsertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main() {
int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++){
  	scanf("%d",&arr[i]);
  }
    recursiveInsertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
