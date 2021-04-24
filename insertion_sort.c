#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n){
	int key = 0;
    int j = 0;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main(){
	int arr[] = {3,32,35,7,1,79,53,89,634,789,6};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

	return 0;
}
