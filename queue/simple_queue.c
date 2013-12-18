#include "simple_queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Queue* create(int elementSize, int no_of_elements){
        Queue* queue = calloc(1,sizeof(Queue));
        queue->rear=-1;
        queue->elements= calloc(no_of_elements,elementSize);
        queue->no_of_elements=no_of_elements;
        queue->elementSize=elementSize;
        return queue;
}
bool isFull(Queue* queue){
        return (queue->rear+1) == queue->no_of_elements ;
}
bool isEmpty(Queue* queue){
        return (queue->rear) == -1;
}
bool enqueue(Queue* queue,void* element){
        if(isFull(queue)) return false;
        queue->rear++;
        memmove((queue->elements+(queue->elementSize*queue->rear)) , element,queue->elementSize);
        return true;
}
void* dequeue(Queue* queue){
        void* element = malloc(queue->elementSize);
        if(isEmpty(queue)) return false;
        memmove(element, queue->elements, queue->elementSize);
        memmove(queue->elements, queue->elements+queue->elementSize, queue->elementSize * queue->rear);
        queue->rear--;
        return element;
}