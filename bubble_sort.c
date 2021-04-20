// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){	
	    for (int j = 0; j < n-i-1; j++){
		    if (arr[j] > arr[j+1]){
			    swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
	int arr[] = {3,32,35,7,1,79,53,89,634,789,6};
    int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
	return 0;
}
