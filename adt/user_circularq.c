#include "queue.h"
#include <stdio.h>

int main(){

    create();

    enqueue(30);
    enqueue(31);
    enqueue(32);
    enqueue(33);
    enqueue(34);
    enqueue(40);
    enqueue(41);
    enqueue(42);
    enqueue(43);
    enqueue(44);
    
    print();


    int val;

     for(int i=0; i<5; i++){
        if(QUEUE_TRUE == front(&val))
            printf("front = %d\n", val);

        if(QUEUE_TRUE == back(&val))
            printf("back = %d\n", val);

        if (QUEUE_TRUE == dequeue(&val))
            printf("dequeue = %d\n\n", val);
    }

    //return 0;    
    print();

    printf("\n\n\n\n");

    enqueue(50);
    enqueue(51);
    enqueue(52);
    enqueue(53);
    enqueue(54);

    print();

    for(int i=0; i<5; i++){
        if(QUEUE_TRUE == front(&val))
            printf("front = %d\n", val);

        if(QUEUE_TRUE == back(&val))
            printf("back = %d\n", val);

        if (QUEUE_TRUE == dequeue(&val))
            printf("dequeue = %d\n\n", val);
    }

    print();
    printf("\n\n\n\n");

    enqueue(60);
    enqueue(61);
    enqueue(62);
    enqueue(63);
    enqueue(64);
    print();

    for(int i=0; i<5; i++){
        if(QUEUE_TRUE == front(&val))
            printf("front = %d\n", val);

        if(QUEUE_TRUE == back(&val))
            printf("back = %d\n", val);

        if (QUEUE_TRUE == dequeue(&val))
            printf("dequeue = %d\n\n", val);
    }
       
    return 0;
}