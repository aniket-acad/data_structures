#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void destroy();

int* elementsQueue = NULL;
short frontIdx = -1;
short backIdx = -1;

void create(){
    destroy();
    elementsQueue = (int*)malloc(MAX_SIZE_QUEUE * sizeof(int));
    frontIdx = -1;
    backIdx = -1;
    return;
}

void destroy(){
    if(NULL != elementsQueue){
        free(elementsQueue);
        elementsQueue = NULL;
    }
    return;
}

status enqueue(int val){
    
    if(QUEUE_FALSE == isFull()){

        if (- 1 == frontIdx) 
            frontIdx = 0;
            
        backIdx = (backIdx + 1) % MAX_SIZE_QUEUE;
        elementsQueue[backIdx] = val;
        
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status dequeue(int* ptrVal){
    
    if(QUEUE_FALSE == isEmpty()){

        *ptrVal = elementsQueue[frontIdx];
        if (frontIdx == backIdx) {
            frontIdx = -1;
            backIdx = -1;
        } 
        else {
            frontIdx = (frontIdx + 1) % MAX_SIZE_QUEUE;
        }
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status front(int* ptrVal){
     if(QUEUE_FALSE == isEmpty()){
        *ptrVal = elementsQueue[frontIdx % MAX_SIZE_QUEUE];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status back(int* ptrVal){
     if(QUEUE_FALSE == isEmpty()){
        *ptrVal = elementsQueue[backIdx % MAX_SIZE_QUEUE];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

unsigned long size(){
    return (unsigned long)(abs(backIdx - frontIdx) + 1);
}

status isEmpty(){
    //printf("frontIdx = %d\tbackIdx = %d\n", frontIdx, backIdx);
    status s;
    s = (-1 == frontIdx) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

status isFull(){
    status s;
    s = ((backIdx + 1 == frontIdx) || (0 == frontIdx && MAX_SIZE_QUEUE - 1 == backIdx)) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

void print(){
    for(int i=0; i<MAX_SIZE_QUEUE; i++){
        printf("%d, ", elementsQueue[i]);
    }
    printf("\n");
}
