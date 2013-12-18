#include "stack_using_linked_list.h"

int push(List* stack,void* element){
    return insert(stack,stack->length,element);
}
void* pop(List* stack){
    return deleteNode(stack,(stack->length-1));
};