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

nodeQ_t* getParentNodeBST(nodeQ_t* node, short val){

    while(EMPTYNODE != node){
        if ((val > node->data) && (node->right != EMPTYNODE))     
            node = node->right;
        else if ((val > node->data) && (node->right == EMPTYNODE))
            return node;
        else if ((val < node->data) && (node->left != EMPTYNODE))    
            node = node->left;
        else if ((val < node->data) && (node->left == EMPTYNODE))
            return node;
        else
            return EMPTYNODE;
    }

    return EMPTYNODE;
}


void insertNodeInBST(nodeQ_t* root, nodeQ_t* newNode){

    if(EMPTYNODE == root || EMPTYNODE == newNode)
        return;

    nodeQ_t* parent = getParentNodeBST(root, newNode->data);
    if(EMPTYNODE == parent)
        return;

    if(newNode->data > parent->data)
        parent->right = newNode;
    if(newNode->data < parent->data)
        parent->left = newNode;
}


nodeQ_t* minNode(nodeQ_t* node){
    if(EMPTYNODE == node)
        return EMPTYNODE;

    nodeQ_t* temp = node;
    while(EMPTYNODE != temp->left){
        temp = temp->left;
    }

    return temp;
}



nodeQ_t* deleteNode(nodeQ_t* root, int key)
{
    if (root == EMPTYNODE)
        return root;
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    else {
        // key == root->data is TRUE
        // node with only one child or no child
        if (root->left == EMPTYNODE) {
            nodeQ_t* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == EMPTYNODE) {
            nodeQ_t* temp = root->left;
            free(root);
            return temp;
        }
 
        // both children for the node are present
        nodeQ_t* mNode = minNode(root->right);

        if(EMPTYNODE != mNode)
        {
            root->data = mNode->data;
            root->right = deleteNode(root->right, mNode->data);
        }
    }
    return root;
}

int main()
{
	/*create root*/
	/*struct node* root = createNode(11);

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
    root->left->right->right = createNode(-9);*/

    /*printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->right->data);
    printf("%d\n", root->right->left->data);
    printf("%d\n", root->right->right->data);*/

    //printTree(root, 0);

    /*trackerIdx = 0;
    printPath(root, 55);
    trackerIdx = 0;
    printPath(root, 56);
    trackerIdx = 0;
    printPath(root, 77);
    trackerIdx = 0;
    printPath(root, 222);*/

    /*
    printf("Inorder: ");
    printInorder(root);
    printf("\n");
    printf("Preorder: ");
    printPreorder(root);
    printf("\n");
    printf("Postorder: ");
    printPostorder(root);
    printf("\n");
    */

   nodeQ_t* root = createNode(100);
   insertNodeInBST(root, createNode(100));
   insertNodeInBST(root, createNode(104));
   insertNodeInBST(root, createNode(56));
   insertNodeInBST(root, createNode(23));
   insertNodeInBST(root, createNode(23));
   insertNodeInBST(root, createNode(200));
   insertNodeInBST(root, createNode(292));
   insertNodeInBST(root, createNode(912));
   insertNodeInBST(root, createNode(5));
   insertNodeInBST(root, createNode(17));
   insertNodeInBST(root, createNode(211));
   insertNodeInBST(root, createNode(211));
   insertNodeInBST(root, createNode(101));
   insertNodeInBST(root, createNode(-95));

   printTree(root, 0);

   nodeQ_t *mNode = minNode(root);
   printf("min node = %d\n", mNode->data);

   root = deleteNode(root, 1000);
   printTree(root, 0);


   /*nodeQ_t* rootDegn = createNode(100);
   insertNodeInBST(rootDegn, createNode(101));
   insertNodeInBST(rootDegn, createNode(102));
   insertNodeInBST(rootDegn, createNode(105));
   insertNodeInBST(rootDegn, createNode(123));
   insertNodeInBST(rootDegn, createNode(134));
   insertNodeInBST(rootDegn, createNode(200));

   printTree(rootDegn, 0);
    */
	
	return 0;
}
