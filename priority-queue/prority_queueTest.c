#include "testUtils.h"
#include "prority_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

list *q;
void teardown(){
    free(q);
}
void test_for_create_a_new_process(){
	list *q;
	list expected = {NULL,0};
    q = create();
    ASSERT(q->front == expected.front);
    ASSERT(q->length == expected.length);
}
void test_for_adding_first_element_in_queue(){
	list *q;
	int value = 10;
   	Queue firstNode = {&value,30,NULL};
	q = create();
	ASSERT(1 == insert(q, &firstNode));
	ASSERT(q->front == &firstNode);
    ASSERT(q->front->next == NULL);
}
void test_for_adding_element_that_have_high_priority_rather_than_first(){
	list *q;
	int value = 10;
	list expected = {NULL,0};
    Queue firstNode = {&value,30,NULL};
    Queue secondNode = {&value,20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode));
    ASSERT(2 == insert(q, &secondNode));
    ASSERT(q->front == &secondNode);
    ASSERT(q->front->next == &firstNode);
}
void test_add_element_with_priority_in_between_priority_queue(){
	list *q;
	int value = 10;
	list expected = {NULL,0};
    Queue *second,*third;
    Queue firstNode = {&value,40,NULL};
    Queue secondNode = {&value,30,NULL};
    Queue thirdNode = {&value,20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode));
    ASSERT(2 == insert(q, &secondNode));
    ASSERT(3 == insert(q, &thirdNode));
    ASSERT(q->front == &thirdNode);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &secondNode);
    ASSERT(third == &firstNode);
    ASSERT(third->next == NULL);
}
void test_remove_element_as_per_priority(){
	list *q;
	int value[] = {10,20,30};
    Queue *second,*third;
    Queue firstNode = {&value[0],40,NULL};
    Queue secondNode = {&value[1],30,NULL};
    Queue thirdNode = {&value[2],20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode));
    ASSERT(2 == insert(q, &secondNode));
    ASSERT(3 == insert(q, &thirdNode));
    ASSERT(q->front == &thirdNode);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &secondNode);
    ASSERT(third == &firstNode);
    ASSERT(third->next == NULL);
    ASSERT(0 == removeElement(q));
    ASSERT(20 == *(int*)q->front->data);
    ASSERT(q->length == 2);
	ASSERT(0 == removeElement(q));
    ASSERT(10 == *(int*)q->front->data);
    ASSERT(q->length == 1);
	ASSERT(0 == removeElement(q));
}
void test_can_not_remove_iF_queue_is_empty(){
	list *q;
	int value[] = {10,20,30};
    Queue *second,*third;
    Queue firstNode = {&value[0],40,NULL};
    Queue secondNode = {&value[1],30,NULL};
    Queue thirdNode = {&value[2],20,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstNode));
    ASSERT(2 == insert(q, &secondNode));
    ASSERT(3 == insert(q, &thirdNode));
    ASSERT(q->front == &thirdNode);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &secondNode);
    ASSERT(third == &firstNode);
    ASSERT(third->next == NULL);
    ASSERT(0 == removeElement(q));
    ASSERT(20 == *(int*)q->front->data);
    ASSERT(q->length == 2);
	ASSERT(0 == removeElement(q));
    ASSERT(10 == *(int*)q->front->data);
    ASSERT(q->length == 1);
	ASSERT(0 == removeElement(q));
	ASSERT(1 == removeElement(q));
}