#include <stdio.h>

int main(){
    /*Two ways to initialize array*/
    int intArr[10] = {0}; /*initialize all elements to ZERO*/
    double doubleArr[10] = {0}; /*initialize all elements to ZERO*/

    /*Rewrite values in an array using for loop*/
    for(unsigned short idx = 0; idx < 10; idx++){
        intArr[idx] = 5 * idx;
        doubleArr[idx] = -2.0 * idx;
    }
    
    /*get the starting address of array*/
    int *ptrArrInt = intArr; 
    double *ptrArrDouble = doubleArr;
 
    /*print values in an array using for loop*/
    for(unsigned short idx = 0; idx < 10; idx++){
        printf("intArr[%d] = %d\n", idx, *(ptrArrInt + idx));
        printf("doubleArr[%d] = %f\n", idx, *(ptrArrDouble + idx));
    }

    /*print values in an array using for loop*/
    for(unsigned short idx = 0; idx < 10; idx++){
        printf("intArr[%d] = %d\n", idx, *ptrArrInt);
        printf("doubleArr[%d] = %f\n", idx, *ptrArrDouble);
        ++ptrArrInt;
        ++ptrArrDouble;
    }
}
