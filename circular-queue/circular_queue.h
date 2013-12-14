#include <stdbool.h>

typedef char string[50];
typedef struct{
	void* elements;
	int elementSize;
	int front;
	int rear;
	int no_of_elements;
}Queue;

Queue* create(int elementSize, int no_of_elements);
bool enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);
bool isFull(Queue* queue);
bool isEmpty(Queue* queue);

