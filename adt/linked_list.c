#include <stdio.h>
#include <stdlib.h>

#define EMPTYNODE 0

struct nodeQ{
    short data;
    struct nodeQ* next;
};

typedef struct nodeQ nodeQ_t;

typedef enum{
    LIST_FALSE = 0,
    LIST_TRUE = 1,
} status_t;

nodeQ_t* createNode(short val){
    nodeQ_t* ptr = (nodeQ_t*)malloc(sizeof(nodeQ_t));
    ptr->data = val;
    ptr->next = EMPTYNODE; // NULL
    return ptr;
}

status_t appendNode(nodeQ_t* tail, nodeQ_t* newNode){

    if(EMPTYNODE == tail || EMPTYNODE == newNode) return LIST_FALSE;

    tail->next = newNode;
    return LIST_TRUE;
}

status_t prependNode(nodeQ_t* head, nodeQ_t* newNode){

    if(EMPTYNODE == head || EMPTYNODE == newNode) return LIST_FALSE;

    newNode->next = head;
    return LIST_TRUE;
}

void printList(nodeQ_t* head){
    if(EMPTYNODE == head) return;

    nodeQ_t* node = head;
    while(node){
        printf("%d --> ", node->data);
        node = node->next;
    }
    printf("EMPTYNODE\n");
}

void destroyList(nodeQ_t* ptr){
    if(EMPTYNODE == ptr) return;

    while(ptr){
        nodeQ_t* current = ptr;
        printList(current);
        ptr = ptr->next;
        free(current);    
    }

    printf("EMPTYNODE\n");
}

status_t isDataPresent(nodeQ_t* ptr, short data){
    if(EMPTYNODE == ptr) return LIST_FALSE;

    while(ptr){
        if(data == ptr->data) return LIST_TRUE;
        ptr = ptr->next;
    }

    return LIST_FALSE;
}

int main(){
    
    nodeQ_t* head = EMPTYNODE;
    nodeQ_t* tail = EMPTYNODE;
    
    head = createNode(20);
    printf("%p\n", head);

    tail = head;

    for(short i=1; i < 6; i++){
        nodeQ_t* newNode = createNode(20+i);
        if(appendNode(tail, newNode))
            tail = newNode;
    }

    for(short i=1; i < 6; i++){
        nodeQ_t* newNode = createNode(20-i);
        if(prependNode(head, newNode))
            head = newNode;
    }

    #if 0
    printf("%d\t\t%p\t\t%p\n", head->data, head, head->next);
    printf("%d\t\t%p\t\t%p\n", head->next->data, head->next, head->next->next);
    printf("%d\t\t%p\t\t%p\n", head->next->next->data, head->next->next, head->next->next->next);
    printf("%d\t\t%p\t\t%p\n", tail->data, tail, tail->next);
    #endif

    //printList(head);

    printf("dataPresent = %d \n", isDataPresent(head, 225));

    //destroyList(head);
    //head = EMPTYNODE;

    //printf("%d\n", head->data);

    return 0;
}
