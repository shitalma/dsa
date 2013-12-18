#include <stdlib.h>
typedef int compFunc(void* , void*);
void* createQueue();
int enqueue(void* queue,void* data, size_t priority,compFunc* compare);
void* dequeue(void* queue);