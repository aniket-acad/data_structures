#include <stdio.h>
/*Author: Aniket Pingley*/

int main(){
    int a = 111;

    int* ptr = NULL; /* initialize a ptr to NULL */
    ptr = &a; /* variable ptr now contains address of a */
    printf("Value of ptr = %p.\n", ptr);
    ptr++; /*increment the value of pointer.*/
    printf("Value of ptr after increment = %p.\n", ptr);
    ptr--;
    printf("Value of ptr after decrement = %p.\n", ptr);
    
    int *ptr2 = ptr;
    ptr2++;
    int diffVal = ptr2 - ptr; 
    /*This operation above show the size of integer in bytes*/
    /*However we are operating on two hexadecimal numbers. To get the correct value in
    bytes, first the hexadecimal value must be typecast/converted to integer format. */
    diffVal = (unsigned long int)ptr2- (unsigned long int)ptr;
    printf("Size of integer in bytes = %d.\n", diffVal); 

    int *ptr3 = ptr + 2; 
    /*ptr + 2 will add twice the number of bytes as per 
    the byte-size of int data type i.e. 4 bytes*/  
    diffVal = (unsigned long int)ptr3- (unsigned long int)ptr;
    printf("Size of integer in bytes = %d.\n", diffVal); 

    /*Pointer can be used to manipulate the value of variable it points*/
    ++*ptr; /*++ptr is different from ++*pt*/
    printf("New value of 'a' pointed by 'ptr' = %d.\n", *ptr);

    return 0;
}
