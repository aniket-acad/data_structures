#include <stdio.h>
  
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void selectionSort(int arr[], int n){
    int minIdx = 0;
    for (int i = 0; i < n-1; i++){
        minIdx = i;
        for (int j = i+1; j < n; j++){
          if (arr[j] < arr[minIdx]){
            minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
}

int main()
{
    int arr[] = {3,32,35,7,1,79,53,89,634,789,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
