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
int insert(list *queue,Queue *q);	
int removeElement(list* queue);