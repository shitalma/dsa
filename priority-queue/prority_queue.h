typedef char string[256];
typedef struct queue{
    void* data;
    int priority;
    struct queue *next;
}Queue;
typedef struct{
    Queue *front;
    int length;
}list;
list* create();
typedef int compFunc(void* , void*);
int insert(list *queue,Queue *q,compFunc* compare);
int removeElement(list* queue);