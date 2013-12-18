#include "stack_without_memecpy.h"
#include <string.h>
#include <stdlib.h>
Stack* create(int elementsSize,int length){
    Stack* stack;
    stack = malloc(sizeof(Stack)*1);
    stack->elementsSize =elementsSize;
    stack->length = length;
    stack->top = -1;
    stack->elements = calloc(stack->length,stack->elementsSize);
    return stack;
}
int isFull(Stack *s){
    return (s->top+1) >= s->length;
}
void copy(char* dest,char* src,int typeSize){
    int i;
    for(i = 0;i<typeSize;i++)
        dest[i] = src[i];
}
int push(Stack* stack,void* elementToPush){
    void* address;
    if(isFull(stack))
        return 0;
    address = stack->elements+(++(stack->top)*stack->elementsSize);
    copy(address,elementToPush, stack->elementsSize);
    return 1;
}
int isEmpty(Stack* stack){
    return stack->top == -1;
}
void* pop(Stack* stack){
    int* a;
    if(isEmpty(stack))
        return 0;
    a = stack->elements + ((stack->top--)*stack->elementsSize);
    return a;
}
void* top(Stack* stack){
    void* data = stack->elements;
    return stack->elements + ((stack->top)*stack->elementsSize);
}