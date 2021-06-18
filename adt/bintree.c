#include <stdio.h>
#include <stdlib.h>

#define EMPTYNODE 0
#define SPACE_GAP_LEVEL 10
#define FALSE 0
#define TRUE 1

struct node {
	short data;
	struct node* left;
	struct node* right;
};

typedef struct node nodeQ_t;

short trackerArr[2048] = {0};
short trackerIdx = 0;

nodeQ_t* createNode(short data)
{
	nodeQ_t* node = (nodeQ_t*)malloc(sizeof(nodeQ_t));
	node->data = data;

	node->left = EMPTYNODE;
	node->right = EMPTYNODE;
	return node;
}

void printTree(nodeQ_t* root, short space)
{
    if (root == NULL)
        return;
  
    space += SPACE_GAP_LEVEL;
  
    printTree(root->right, space);
  
    printf("\n");
    for (int i = SPACE_GAP_LEVEL; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
  
    printTree(root->left, space);
}

short isPresentOnPath(nodeQ_t* node, short val)
{
    if (!node) // EMPTYNODE == node
        return FALSE;
      
    trackerArr[trackerIdx] = node->data;  
    trackerIdx++; // push()
      
    if (node->data == val)    
        return TRUE;
      
    if (isPresentOnPath(node->left, val) ||
        isPresentOnPath(node->right, val))
        return TRUE;
      
    trackerIdx--; // pop()
    return FALSE;            
}
  
void printPath(nodeQ_t* root, short val)
{
    if (isPresentOnPath(root, val))
    {
        for (int i=0; i < trackerIdx; i++){
            printf("%d -> ", trackerArr[i]);
        }
        printf("\n");
    }
      
    else
        printf("Value not present on path\n");
}


void printInorder(nodeQ_t* node){
    if(!node) 
        return;

    printInorder(node->left); // left
    printf("%d -> ", node->data); // root
    printInorder(node->right); // right

}

void printPreorder(nodeQ_t* node){
    if(!node) 
        return;

    printf("%d -> ", node->data); // root
    printPreorder(node->left); // left
    printPreorder(node->right); // right

}

void printPostorder(nodeQ_t* node){
    if(!node) 
        return;

    printPostorder(node->left); // left
    printPostorder(node->right); // right
    printf("%d -> ", node->data); // root

}



int main()
{
	/*create root*/
	struct node* root = createNode(11);

	root->left = createNode(22);
	root->right = createNode(33);
	
	root->left->left = createNode(144);
    root->left->right = createNode(55);

    root->right->left = createNode(66);
    root->right->right = createNode(222);

    root->right->left->left = createNode(88);
    root->right->right->right = createNode(99);

    root->right->left->left = createNode(111);
    root->right->right->right = createNode(77);

    root->left->left->left = createNode(-45);
    root->left->right->right = createNode(-9);

    /*printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->right->data);
    printf("%d\n", root->right->left->data);
    printf("%d\n", root->right->right->data);*/

    printTree(root, 0);

    /*trackerIdx = 0;
    printPath(root, 55);
    trackerIdx = 0;
    printPath(root, 56);
    trackerIdx = 0;
    printPath(root, 77);
    trackerIdx = 0;
    printPath(root, 222);*/

    printf("Inorder: ");
    printInorder(root);
    printf("\n");
    printf("Preorder: ");
    printPreorder(root);
    printf("\n");
    printf("Postorder: ");
    printPostorder(root);
    printf("\n");
	
	return 0;
}
