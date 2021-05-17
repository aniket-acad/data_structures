#include "stack.h"
#include <stdio.h>
#include <ctype.h>

int char2int(char c){
		return c - '0';
}



void evaluate(char ch, unsigned short which){
		short stage = -1;

		if(isdigit(ch)){
				if (STACK_FALSE == push(char2int(ch)))
						printf("Could not push %c\n", ch);

				//printf("Stage %d:\n", ++stage);
				//printStack();
		}
		else{
				int left;
				int right;
				if(0 == which){
					pop(&right);
					pop(&left);
				}
				else{
					pop(&left);
					pop(&right);
				}

				//printf("Stage %d:\n", ++stage);
				//printStack();

				switch(ch){
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

int evaluatePrefix(char expr[], short sz){

		for(short i=sz-1; i > -1; i--)
				evaluate(expr[i], 1);

		int ret;

		//printf("Final stage:\n");
		//printStack();

		pop(&ret);
		return ret;

}

int evaluatePostfix(char expr[], short sz){

		for(short i=0; i < sz; i++)
				evaluate(expr[i], 0);

		int ret;

		//printf("Final stage:\n");
		//printStack();

		pop(&ret);
		return ret;
}

int main(){

		// Infix: 4 + 6 + 7 + 9 - 2
		// Postfix: 46+7+9+2-
		char expr0_postfix[] = {'4', '6', '+', '7', '+', '9', '+', '2', '-'};
		// Prefix: +4 + 6 + 7 - 9  2
		char expr0_prefix[] = {'+', '4', '+', '6', '+', '7', '-', '9', '2'};

		// Infix: 2 + 3 * 4 + 7
		// Postfix: 234*+7+
		char expr1_postfix[] = {'2', '3', '4', '*', '+', '7', '+'};
		// Prefix: +2+*347
		char expr1_prefix[] = {'+', '2', '+', '*', '3', '4', '7'};

		// Infix: 9/3 + 8/2
		// Postfix: 93/82/+
		char expr2_postfix[] = {'9', '3', '/', '8', '2', '/', '+'};
		// Prefix: +/93/82
		char expr2_prefix[] = {'+', '/', '9', '3', '/', '8', '2'};


		// Infix: (5 + 6) * 2 - 3
		// Postfix: 56+2*3-
		char expr3_postfix[] = {'5', '6', '+', '2', '*', '3', '-'};
		// Prefix: -*+5623
		char expr3_prefix[] = {'-', '*', '+', '5', '6', '2', '3'};

		// Infix: (2 - 4 + 5) * (6 / 3 + 1)
		// Postfix: 254+-631+/*
		char expr4_postfix[] = {'2', '4', '-' , '5', '+', '6', '3', '/' ,'1', '+', '*'};
		// Prefix: *+-245+/631
		char expr4_prefix[] = {'*', '+', '-' , '2', '4', '5', '+', '/' ,'6', '3', '1'};

		create();
		printf("4 + 6 + 7 + 9 - 2 = %d\n", evaluatePostfix(expr0_postfix, sizeof(expr0_postfix)/sizeof(char)));

		create();
		printf("4 + 6 + 7 + 9 - 2 = %d\n", evaluatePrefix(expr0_prefix, sizeof(expr0_prefix)/sizeof(char)));

		//////////
		create();
		printf(" 2 + 3 * 4 + 7 = %d\n", evaluatePostfix(expr1_postfix, sizeof(expr1_postfix)/sizeof(char)));

		create();
		printf(" 2 + 3 * 4 + 7 = %d\n", evaluatePrefix(expr1_prefix, sizeof(expr1_prefix)/sizeof(char)));

		//////////
		create();
		printf("9/3 + 8/2 = %d\n", evaluatePostfix(expr2_postfix, sizeof(expr2_postfix)/sizeof(char)));

		create();
		printf("9/3 + 8/2 = %d\n", evaluatePrefix(expr2_prefix, sizeof(expr2_prefix)/sizeof(char)));

		//////////
		create();
		printf("(5 + 6) * 2 - 3 = %d\n", evaluatePostfix(expr3_postfix, sizeof(expr3_postfix)/sizeof(char)));

		create();
		printf("(5 + 6) * 2 - 3 = %d\n", evaluatePrefix(expr3_prefix, sizeof(expr3_prefix)/sizeof(char)));

		//////////
		create();
		printf("(2 - 4 + 5) * (6 / 3 + 1) = %d\n", evaluatePostfix(expr4_postfix, sizeof(expr4_postfix)/sizeof(char)));

		create();
		printf("(2 - 4 + 5) * (6 / 3 + 1) = %d\n", evaluatePrefix(expr4_prefix, sizeof(expr4_prefix)/sizeof(char)));

		return 0;
}
