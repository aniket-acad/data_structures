#include <stdio.h>
#include <limits.h>

int linearSearch(int arr[], int sz, int key){
    int index = -1;
    for(int idx = 0; idx < sz; idx++){
        if (key == arr[idx]){
            index = idx;
            break;
        }
    }
    return index;
}

int binarySearch(int arr[], int sz, int key){
    int index = -1;
    int left = 0, right = sz - 1, mid = 0;
    while(left <= right){
        mid = (left + right)/2;
        if (key == arr[mid]){
            index = mid;
            break;
        }
        if(arr[mid] < key){
            left = mid+1;
        }
        else{
            /*if(arr[mid] > key){}*/
            right = mid-1;
        }
    }
    return index;
}

int getLargest(int arr[], int sz){
    int retVal = INT_MIN;
    for(int idx = 0; idx < sz; idx++){
        int val = arr[idx];
        if (retVal < val){
            retVal = val;
        }
    }
    return retVal;
}

int main(){
    int arr[] = {3,32,35,7,1,79,53,89,634,789,6};
    printf("linearSearch index = %d\n", linearSearch(arr, sizeof(arr)/sizeof(arr[0]), 35));
    printf("linearSearch index = %d\n", linearSearch(arr, sizeof(arr)/sizeof(arr[0]), 350));
    printf("largest value = %d\n", getLargest(arr, sizeof(arr)/sizeof(arr[0])));
    int arrSorted[] = {2,3,4,5,6,7,8,9,12,34,56,78,99};
    printf("binarySearch index = %d\n", binarySearch(arrSorted, sizeof(arrSorted)/sizeof(arrSorted[0]), 99));
    printf("binarySearch index = %d\n", binarySearch(arrSorted, sizeof(arrSorted)/sizeof(arrSorted[0]), 234));
    return 0;
}
