/**
 * Purpose: 
 * Author: 
 * */

#define MAX_SIZE_STACK 50

/**
 * 
 * */
typedef enum{
    STACK_TRUE = 0,
    STACK_FALSE = 1
} status;

/**
 * This function will create and initiliaze the stack ADT in memory
 * */
void create();

/**
 * 
 * */
void destroy();

/**
 * 
 * */
status push(int);

/**
 * 
 * */
status pop(int*);

/**
 * 
 * */
status peek(int*);

