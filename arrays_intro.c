#include <stdio.h>

int main(){
    /*Two ways to initialize array*/
    int intArr[10] = {0}; /*initialize all elements to ZERO*/
    double doubleArr[10] = {0}; /*initialize all elements to ZERO*/

    /*initialize array with multiple values*/
    int intArrInitialized[10] = {1,2,3,4,5,6,7,8,9,10}; 

    /*Rewrite values in an array using for loop*/
    for(unsigned short idx = 0; idx < 10; idx++){
        intArr[idx] = 5 * idx;
        doubleArr[idx] = -2.0 * idx;
    }
    
    /*print values in an array using for loop*/
    for(unsigned short idx = 0; idx < 10; idx++){
        printf("intArr[%d] = %d, doubleArr[%d] = %f, intArrInitialized[%d] = %d\n\n",\
        idx, intArr[idx], idx, doubleArr[idx], idx, intArrInitialized[idx]);
    }

    /*print address of elements in array using for loop*/
    for(unsigned short idx = 0; idx < 9; idx++){
        printf("&intArr[%d] = %p, &doubleArr[%d] = %p,\n\
        Bytes between indices for intArr = %u,\n\
        Bytes between indices for doubleArr = %u\n\n",\
        idx, &intArr[idx], idx, &doubleArr[idx],\
        (unsigned int)&intArr[idx + 1] - (unsigned int)&intArr[idx],\
        (unsigned int)&doubleArr[idx + 1] - (unsigned int)&doubleArr[idx]);
    }

    /*Strings in C are created as char array*/
    /*There are two ways to initialze char arrays for processing as strings*/
    char charArr[6] = {'H','e','l','l','o','\0'};
    char string[] = "World"; /**/

    printf("Message: %s, %s\n", charArr, string); 
}
