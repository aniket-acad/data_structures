#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int left_index, int right_index){
    int pivot = arr[right_index];
	int pivot_index = right_index;
	right_index--; /*pivot exists at the right index*/
 
	while(left_index <= right_index){
		if(arr[left_index] < pivot){
			left_index++;
			continue;
		}
		else if(arr[right_index] > pivot){
			right_index--;
			continue;
		}
		else{
			swap(&arr[left_index], &arr[right_index]);
		}
	}

	/*Now the left index point to location where pivot must go*/
	swap(&arr[left_index], &arr[pivot_index]);
	return left_index;
}

void quick_sort_func(int arr[], int left_index, int right_index)
{
	if (left_index < right_index) {
		int partition_index = partition(arr, left_index, right_index);

		/*recursively sort first and second halves*/
		quick_sort_func(arr, left_index, partition_index - 1);
		quick_sort_func(arr, partition_index + 1, right_index);
	}
}

void print_array_func(int arr[], int size){
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[6][8] = { {2, 31, 13, 15, 61, 7, 43, 44},
					{102, 110, 3, -4, 6, 7, -23, 512},
					{12, -11, 103, 54, 16, 37, 23, 55},
					{1, 11, 13, -5, 6, -7, -23, 43},
					{129, -11, -13, 5, -6, 7, 32, 66},
					{-129, -11, -13, -5, -6, -7, -32, -66} };
	
	for(int i=0; i<6; i++){
		int arr_size = sizeof(arr[i]) / sizeof(arr[i][0]);
		printf("\nGiven array is \n");
		print_array_func(arr[i], arr_size);

		quick_sort_func(arr[i], 0, arr_size - 1);

		printf("Sorted array is\n");
		print_array_func(arr[i], arr_size);
	}
	return 0;
}
