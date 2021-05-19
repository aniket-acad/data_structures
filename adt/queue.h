/**
 * Purpose: 
 * Author: 
 * */

#define MAX_SIZE_QUEUE 5

/**
 * 
 * */
typedef enum{
    QUEUE_TRUE = 0,
    QUEUE_FALSE = 1
} status;

/**
 * 
 * */
void create();

/**
 * 
 * */
status enqueue(int);

/**
 * 
 * */
status dequeue(int*);

/**
 * 
 * */
status front(int*);

/**
 * 
 * */
status back(int*);

/**
 * 
 * */
status isEmpty();

/**
 * 
 * */
status isFull();

/**
 * 
 * */
unsigned long size();

/**
 * 
 * */
void print();