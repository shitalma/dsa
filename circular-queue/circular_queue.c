#include "circular_queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Queue* create(int elementSize, int length){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->front = -1;
	queue->rear = -1;
	queue->elements= calloc(length,elementSize);
	queue->length=length;
	queue->elementSize=elementSize;
	return queue;
}
int isFull(Queue* queue){ 
	if(queue->front == -1 && queue->rear == queue->length-1) return 1;
	if(queue->rear == queue->length-1 && queue->front > 0) queue->rear=-1;
	return (queue->front == queue->rear+1);
}
int isEmpty(Queue* queue){
	if(queue->front ==-1 && queue->rear == -1) return 1;
	return (queue->front == queue->rear);
}
int enqueue(Queue* queue,void* element){
	if(isFull(queue)) return 0;
	queue->rear++;
	memcpy((queue->elements+(queue->elementSize*queue->rear)) , element,queue->elementSize);
	return 1;
}
void* dequeue(Queue* queue){
	void* element = malloc(queue->elementSize);
	if(isEmpty(queue)) return NULL;
	queue->front++;
	memcpy(element, queue->elements+(queue->elementSize*queue->front), queue->elementSize);
	return element;
}