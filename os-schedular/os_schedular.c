#include "os_schedular.h"
#include <stdlib.h>

scheduler* create(){
    scheduler *queue = calloc(sizeof(scheduler),1);
    return queue;
}
int insertAtBegining(scheduler *queue, pro *process){
    if(queue->front == NULL)
        process->next = NULL;
    else process->next = queue->front;
    queue->front = process;
    queue->length++;
    return queue->length;        
}
int insert(scheduler *queue, pro *process,compFunc* compare){
    pro *previous,*next,*temp;
    int i = 0;
    temp = queue->front;
    if(queue->length == 0 || (compare(&process->priority,&temp->priority) < 0))                
        return insertAtBegining(queue, process);
    for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(process->priority < next->priority){
            previous->next = process;
            process->next = next;
            return ++queue->length;
        }
    };
    temp->next = process;
    process->next = NULL;
    return ++queue->length;
}
int removeProcess(scheduler *queue){
    pro *temp,*previous,*next;
    int i = 0;
    temp = queue->front;
    if(queue->length == 1){
        if(temp->processTime == 0)
            queue->front = NULL;
        return --queue->length;
    }
    if(temp->processTime == 0)
        queue->front = temp->next;
    for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(next->processTime == 0){
            previous->next = next->next;
            return --queue->length;
        }
    }
    if(NULL == temp->next){
        previous->next = NULL;
        return --queue->length;
    };
    return 0;
}