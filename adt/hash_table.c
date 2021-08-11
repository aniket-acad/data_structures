#include <stdio.h>
#include <stdlib.h>

#define SIZE_HTABLE 31

struct keyval_item{
    int key;
    int data; // for sake of simplicity
};

struct keyval_item* dataBucket[SIZE_HTABLE] = {NULL};

int hashFunc(int key){
    return key % SIZE_HTABLE;
}

struct keyval_item* lookup(int key){
    if(key < SIZE_HTABLE)
        return dataBucket[hashFunc(key)];

    return NULL;
}

void delete(int key){
    return;
}

void insert(struct keyval_item* item){
    if(NULL == item) return;
    int idx = hashFunc(item->key);
    dataBucket[idx] = item;
}

void display(){
    for(short i =0; i< SIZE_HTABLE; i++){
        if(NULL != dataBucket[i]){
            printf("key = %d, data = %d\n", dataBucket[i]->key, dataBucket[i]->data);
        }
    }
    printf("\n");
    return;
}

int main(){

    struct keyval_item item1;
    item1.key = 3;
    item1.data = 45;
    insert(&item1);

    struct keyval_item item2;
    item2.key = 5;
    item2.data = 475;
    insert(&item2);

    struct keyval_item* retItem = lookup(5);
    printf("For key = 5, data = %d\n", retItem->data);
    printf("For key = 3, data = %d\n", lookup(3)->data);

    struct keyval_item item3;
    item3.key = 56;
    item3.data = 4765;
    insert(&item3);

    struct keyval_item item4;
    item4.key = 25;
    item4.data = 4754;
    insert(&item4);

    display();



    return 0;
}
