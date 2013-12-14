#include "stack_using_linked_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int push(slist* stack,void* element){
    int result,index;
    index = stack->length;
    result = insert(stack,index,element);
    return result;
}
void* pop(slist* stack){
    void* result;
    int index = stack->length-1;
    result = deleteNode(stack,index);
    return result;
};