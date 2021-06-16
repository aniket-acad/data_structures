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

typedef struct node node_t;

short trackerArr[2048] = {0};
short trackerIdx = 0;

node_t* createNode(short data)
{
	node_t* node = (node_t*)malloc(sizeof(node_t));
	node->data = data;

	node->left = EMPTYNODE;
	node->right = EMPTYNODE;
	return node;
}

void printTree(node_t* root, short space)
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

short isPresentOnPath(node_t* root, short val)
{
    if (!root)
        return FALSE;
      
    trackerArr[trackerIdx] = root->data;  
    trackerIdx++;  
      
    if (root->data == val)    
        return TRUE;
      
    if (isPresentOnPath(root->left, val) ||
        isPresentOnPath(root->right, val))
        return TRUE;
      
    trackerIdx--; 
    return FALSE;            
}
  
void printPath(node_t* root, short val)
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

struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}


int main()
{
	/*create root*/
	struct node* root = createNode(11);

	root->left = createNode(22);
	root->right = createNode(33);
	
	root->left->left = createNode(44);
    root->left->right = createNode(55);

    root->right->left = createNode(66);
    root->right->right = createNode(77);

    root->right->left->left = createNode(88);
    root->right->right->right = createNode(99);

    root->right->left->left = createNode(111);
    root->right->right->right = createNode(222);

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->right->data);
    printf("%d\n", root->right->left->data);
    printf("%d\n", root->right->right->data);

    printTree(root, 0);

    trackerIdx = 0;
    printPath(root, 55);
    trackerIdx = 0;
    printPath(root, 56);
    trackerIdx = 0;
    printPath(root, 77);
    trackerIdx = 0;
    printPath(root, 222);

	
	return 0;
}
