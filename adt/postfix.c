#include "stack.h"
#include <stdio.h>
#include <ctype.h>

int char2int(char c){
    return c - '0';
}

int evaluate(char expr[], short sz){
    short stage = -1;
    for(short i=0; i < sz; i++){
        if(isdigit(expr[i])){
            if (STACK_FALSE == push(char2int(expr[i])))
                printf("Could not push %c\n", expr[i]);
            
            printf("Stage %d:\n", ++stage);
            printStack();
        }
        else{
            int left;
            int right;
            pop(&right);
            pop(&left);

            printf("Stage %d:\n", ++stage);
            printStack();

            switch(expr[i]){
                case '+': 
                    push(left + right); 
                    break;
                case '-': 
                    push(left - right); 
                    break;
                case '*': 
                    push(left * right); 
                    break;
                case '/': 
                    push(left/right); 
                    break;
            }            
        }
    }

    int ret;

    printf("Stage %d:\n", ++stage);
    printStack();
    
    pop(&ret);
    return ret;
}

int main(){

    
    // Infix: 4 + 6 + 7 + 9 - 2
    // Postfix: 46+7+9+2-
    char expr0[] = {'4', '6', '+', '7', '+', '9', '+', '2', '-'};

    // Infix: 2 + 3 * 4 + 7
    // Postfix: 234*+7+
    char expr1[] = {'2', '3', '4', '*', '+', '7', '+'};
    
    // Infix: 9/3 + 8/2
    // Postfix: 93/82/+
    char expr2[] = {'9', '3', '/', '8', '2', '/', '+'};

    // Infix: (5 + 6) * 2 - 3
    // Postfix: 56+2*3-
    char expr3[] = {'5', '6', '+', '2', '*', '3', '-'};

    // Infix: (2 - 4 + 5) * (6 / 3 + 1)
    // Postfix: 254+-631+/*
    char expr4[] = {'2', '4', '-' , '5', '+', '6', '3', '/' ,'1', '+', '*'};

    create();
    printf("4 + 6 + 7 + 9 - 2 = %d\n", evaluate(expr0, sizeof(expr0)/sizeof(char)));
    
    create();
    printf(" 2 + 3 * 4 + 7 = %d\n", evaluate(expr1, sizeof(expr1)/sizeof(char)));
    
    create();
    printf("9/3 + 8/2 = %d\n", evaluate(expr2, sizeof(expr2)/sizeof(char)));
    
    create();
    printf("(5 + 6) * 2 - 3 = %d\n", evaluate(expr3, sizeof(expr3)/sizeof(char)));

    create();
    printf("(2 - 4 + 5) * (6 / 3 + 1) = %d\n", evaluate(expr4, sizeof(expr4)/sizeof(char)));
    
    return 0;
}
