#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// forward declaration
unsigned long size();
status isEmpty();
status isFull();
void destroy();


int* elementsStack = NULL;
short topOfStack = -1;

void create(){
    destroy();
    elementsStack = (int*)malloc(MAX_SIZE_STACK * sizeof(int));
    topOfStack = -1;
    return;
}

void destroy(){
    if(NULL != elementsStack){
        free(elementsStack);
        elementsStack = NULL;
    }
    return;
}

status push(int val){
    if(STACK_FALSE == isFull()){
        topOfStack++;
        elementsStack[topOfStack] = val;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status pop(int* ptrVal){
    if(STACK_FALSE == isEmpty()){
        *ptrVal = elementsStack[topOfStack];
        topOfStack--;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status peek(int* ptrVal){
     if(STACK_FALSE == isEmpty()){
        *ptrVal = elementsStack[topOfStack];
        //topOfStack--;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

unsigned long size(){
    return topOfStack + 1;
}

status isEmpty(){
    if(-1 == topOfStack)
        return STACK_TRUE;

    return STACK_FALSE;
}

status isFull(){
    if(MAX_SIZE_STACK == topOfStack + 1)
        return STACK_TRUE;

    return STACK_FALSE;
}

void printStack(){
    if(STACK_TRUE == isEmpty())
        return;

    printf("++++++++++++\n");
    for(short i=topOfStack; i > -1; i--){
        printf("Element %d: %d\n", i, elementsStack[i]);
    }
    printf("-----------\n");
}
