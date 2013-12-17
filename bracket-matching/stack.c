#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


stack* create(int elementsSize,int size){
	stack* Stack;
	Stack = malloc(sizeof(stack)*1);
	Stack->elementsSize =elementsSize;
	Stack->size = size;
	Stack->top = -1;
	Stack->elements = calloc(Stack->size,Stack->elementsSize);
	return Stack;
}
int isFull(stack *s){
	if((s->top+1) >= s->size)
		return 1;
	return 0;
}

int push(stack* Stack,void* elementToPush){
	void* address;
	if(isFull(Stack))
		return 0;

	address = Stack->elements+(++(Stack->top)*Stack->elementsSize);
	memcpy(address,elementToPush, Stack->elementsSize);
	return 1;
}
int isEmpty(stack* Stack){
	if(Stack->top == -1)
		return 1;
	return 0;
}

void* pop(stack* Stack){
	if(isEmpty(Stack))
		return 0;
	return Stack->elements + ((Stack->top--)*Stack->elementsSize);
}
void* top(stack* Stack){
void* data = Stack->elements;
	return Stack->elements + ((Stack->top)*Stack->elementsSize);}

