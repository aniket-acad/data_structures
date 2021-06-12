#include <stdio.h>
#include <stdlib.h>

#define EMPTYNODE 0
#define TRUE 1
#define FALSE 0

struct node{
    short data; // 16
    struct node* left; // 64
    struct node* right; // 64
};

typedef struct node nodeQ_t;

nodeQ_t* createNode(short val){
   nodeQ_t* newNode = (nodeQ_t*) malloc(sizeof(nodeQ_t));
   newNode->data = val;
   newNode->left = EMPTYNODE;
   newNode->right = EMPTYNODE;
   return newNode;
}


int main(){

    nodeQ_t* root = createNode(11);

    root->left = createNode(22);
    root->right = createNode(33);

    root->left->left = createNode(44);
    root->left->right = createNode(55); 

    root->right->left = createNode(66);
    root->right->right = createNode(77); 

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->right->data);




    return 0;
}