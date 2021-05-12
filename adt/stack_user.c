#include "stack.h"
#include <stdio.h>

int main(){

    create();

    push(45);
    push(55);
    push(65);
    push(75);
    push(85);
    push(95);

    int val = 0;

    if(STACK_TRUE == pop(&val)){
        printf("%d\n", val);
    }

    if(STACK_TRUE == pop(&val)){
        printf("%d\n", val);
    }

    if(STACK_TRUE == peek(&val)){
        printf("%d\n", val);
    }

    if(STACK_TRUE == peek(&val)){
        printf("%d\n", val);
    }

    if(STACK_TRUE == pop(&val)){
        printf("%d\n", val);
    }

     if(STACK_TRUE == peek(&val)){
        printf("%d\n", val);
    }

    destroy();

    return 0;
}
