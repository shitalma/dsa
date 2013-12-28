#include "iterator.h"
typedef struct {
    void** base;
    int capacity;
    int length;
} ArrayList;

ArrayList create_arrayList(int capacity);
// typedef int (*compare)(void* element1,void *element2);

int arrayList_insert(ArrayList *list, int index, void* data);

int arrayList_remove(ArrayList *list,int index);

int arrayList_add(ArrayList *list,void *data);

void* arrayList_get(ArrayList *list, int index);

// int arrayList_search(ArrayList *list, void *searchElement,compare cmpFun);

Iterator arrayList_getIterator(ArrayList* list);

void arrayList_dispose(ArrayList *list);