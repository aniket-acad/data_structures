#include <stdio.h>
#include <stdlib.h>

/**
Merges two subarrays of arr[].
First subarray is arr[left_index..middle_index] 
Second subarray is arr[middle_index+1..right_index]
**/
void merge(int arr[], int left_index, int middle_index, int right_index)
{
	int sz_left_arr = middle_index - left_index + 1;
	int sz_right_arr = right_index - middle_index;

	/* create temporary arrays */
	int left_arr[sz_left_arr], right_arr[sz_right_arr];

	/* Copy data to left_arr[] and right_arr[] */
	for (int i = 0; i < sz_left_arr; i++)
		left_arr[i] = arr[left_index + i];

	for (int j = 0; j < sz_right_arr; j++)
		right_arr[j] = arr[middle_index + 1 + j];

	int i, j, k;
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; /* starting index of left_arr */
	j = 0; /* starting index of right_arr */
	k = left_index; /* starting index of merged subarray */
	while (i < sz_left_arr && j < sz_right_arr) {
		if (left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i];
			i++;
		}
		else {
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of left_arr[], if there
	are any */
	while (i < sz_left_arr) {
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of right_arr[], if there
	are any */
	while (j < sz_right_arr) {
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}

void merge_sort_func(int arr[], int left_index, int right_index)
{
	if (left_index < right_index) {
		int middle_index = (left_index + right_index) / 2;

		/*recursively sort first and second halves*/
		merge_sort_func(arr, left_index, middle_index);
		merge_sort_func(arr, middle_index + 1, right_index);

		merge(arr, left_index, middle_index, right_index);
	}
}

void print_array_func(int arr[], int size){
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[5][8] = { {2, 31, 13, 15, 61, 7, 43, 44},
					{102, 110, 3, -4, 6, 7, -23, 512},
					{12, -11, 103, 54, 16, 37, 23, 55},
					{1, 11, 13, -5, 6, -7, -23, 43},
					{129, -11, -13, 5, -6, 7, 32, 66} };
	
	for(int i=0; i<5; i++){
		int arr_size = sizeof(arr[i]) / sizeof(arr[i][0]);
		printf("\nGiven array is \n");
		print_array_func(arr[i], arr_size);

		merge_sort_func(arr[i], 0, arr_size - 1);

		printf("Sorted array is\n");
		print_array_func(arr[i], arr_size);
	}
	return 0;
}
