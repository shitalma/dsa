#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Stack* create(int typeSize){
    Stack* stack = calloc(1,sizeof(Stack));
    stack->top = NULL;
    stack->typeSize = typeSize;
    stack->elementsPresent = 0;
    return stack;
};
void push(Stack* stack,void* element){
    data* stack_element = calloc(1,sizeof(data));
    int *elementToBePushed = (int*)calloc(1,stack->typeSize);
    stack_element->element = element;
    if(stack->top == NULL){
        stack_element->previous = NULL;
        stack->top = stack_element;
    }
    else {
        stack_element->previous = stack->top;
        stack->top = stack_element;
    }
    stack->elementsPresent++;
};

data* pop(Stack* stack){
    data *stack_element,* poppedElement;
    if(stack->top == NULL) return NULL;
    stack_element = calloc(1,sizeof(data));
    poppedElement = stack->top;
    stack_element->element = calloc(1,stack->typeSize);
    stack_element->element = stack->top->element;
    stack->top = (*stack->top).previous;
    poppedElement->previous = NULL;
    return stack_element;
};