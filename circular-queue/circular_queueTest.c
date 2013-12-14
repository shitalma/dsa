#include "testUtils.h"
#include "circular_queue.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_queue_allocates_memory_for_five_int_elements(){
	int i;
	Queue* queue;
	int test_arr[] = {0,0,0,0,0};
	queue = create(sizeof(int),5);
	i = memcmp(test_arr,queue->elements,5);
	ASSERT(!i);
	ASSERT(queue->elementSize == 4);
	ASSERT(queue->front == -1);
	ASSERT(queue->rear == -1);
	ASSERT(queue->no_of_elements == 5);
}
void test_create_queue_allocates_memory_for_five_float_elements(){
	int i;
	Queue* queue;
	int test_arr[] = {0,0,0,0,0};
	queue = create(sizeof(float),5);
	i=memcmp(test_arr,queue->elements,5);
	ASSERT(!i);
	ASSERT(queue->elementSize == sizeof(float));
	ASSERT(queue->rear == -1);
	ASSERT(queue->front == -1);
	ASSERT(queue->no_of_elements == 5);
}
void test_create_queue_allocates_memory_for_five_char_strings(){
	int i;
	Queue* queue;
	string test_arr[] = {0,0,0};
	queue = create(sizeof(string),3);
	i=memcmp(test_arr,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->elementSize == sizeof(string));
	ASSERT(queue->front == -1);
	ASSERT(queue->rear==-1);
	ASSERT(queue->no_of_elements == 3);
}
void test_create_queue_allocates_memory_for_five_characters(){
	int i;
	Queue* queue;
	char test_arr[] = {0,0,0};
	queue = create(sizeof(char),3);
	i=memcmp(test_arr,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->elementSize == sizeof(char));
	ASSERT(queue->front == -1);
	ASSERT(queue->rear==-1);
	ASSERT(queue->no_of_elements == 3);
}
void test_enqueue_char_element_at_rear_of_queue(){
	Queue* queue;
	char c='A';
	queue = create(sizeof(char),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(*(char*)(queue->elements)=='A');
	ASSERT(queue->rear==0);
	free(queue);
}
void test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle(){
	Queue* queue;
	char c='K';
	queue = create(sizeof(char),6);
	queue->rear = 3;
	ASSERT(enqueue(queue,&c));
	ASSERT(*(char*)(queue->elements+queue->rear*queue->elementSize) == 'K');
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle1(){
	Queue* queue;
	char c='J';
	queue = create(sizeof(char),6);
	queue->rear = 3;
	queue->front = 5;
	ASSERT(enqueue(queue,&c));
	ASSERT(*(char*)(queue->elements+queue->rear*queue->elementSize) == 'J');
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_char_element_return_false_when_queue_is_full(){
	Queue* queue;
	char c='Q';
	queue = create(sizeof(char),6);
	queue->rear = 5;
	queue->front = -1;
	ASSERT(!enqueue(queue,&c));
	ASSERT(queue->rear == 5);
	free(queue);
}
void test_enqueue_int_element_at_rear_of_queue(){
	Queue* queue;
	int c=5;
	queue = create(sizeof(int),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(*(int*)(queue->elements)==5);
	ASSERT(queue->rear==0);
	free(queue);
}
void test_enqueue_float_element_at_rear_of_queue(){
	Queue* queue;
	float c=1.5;
	queue = create(sizeof(float),5);
	queue->rear = 1;
	ASSERT(enqueue(queue,&c));
	ASSERT(queue->rear == 2);
	ASSERT(*(float*)(queue->elements+queue->rear*queue->elementSize)==1.5);
	free(queue);
}
void test_enqueue_string_element_at_rear_of_queue(){
	Queue* queue;
	string c = "hi";
	queue = create(sizeof(string),5);
	ASSERT(enqueue(queue,&c));
	ASSERT(!strcmp("hi", *(string*)queue->elements));
	ASSERT(queue->rear == 0);
	free(queue);
}
void test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle(){
	Queue* queue;
	int c=5;
	queue = create(sizeof(int),6);
	queue->rear = 3;
	ASSERT(enqueue(queue,&c));
	ASSERT(*(int*)(queue->elements+queue->rear*queue->elementSize) == 5);
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle1(){
	Queue* queue;
	int c=10;
	queue = create(sizeof(int),6);
	queue->rear = 3;
	queue->front = 5;
	ASSERT(enqueue(queue,&c));
	ASSERT(*(int*)(queue->elements+queue->rear*queue->elementSize) == 10);
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_int_element_return_false_when_queue_is_full(){
	Queue* queue;
	int c=10;
	queue = create(sizeof(int),6);
	queue->rear = 5;
	queue->front = -1;
	ASSERT(!enqueue(queue,&c));
	ASSERT(queue->rear == 5);
	free(queue);
}
void test_enqueue_int_element_return_false_when_queue_is_full1(){
	Queue* queue;
	int c=10;
	queue = create(sizeof(int),6);
	queue->rear = 4;
	queue->front = 5;
	ASSERT(!enqueue(queue,&c));
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle(){
	Queue* queue;
	float c=5.90f;
	queue = create(sizeof(float),6);
	queue->rear = 3;
	ASSERT(enqueue(queue,&c));
	ASSERT(*(float*)(queue->elements+queue->rear*queue->elementSize) == 5.90f);
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle1(){
	Queue* queue;
	float c=20.20f;
	queue = create(sizeof(float),6);
	queue->rear = 3;
	queue->front = 5;
	ASSERT(enqueue(queue,&c));
	ASSERT(*(float*)(queue->elements+queue->rear*queue->elementSize) == 20.20f);
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_float_element_return_false_when_queue_is_full(){
	Queue* queue;
	float c=10.50;
	queue = create(sizeof(float),6);
	queue->rear = 5;
	queue->front = -1;
	ASSERT(!enqueue(queue,&c));
	ASSERT(queue->rear == 5);
	free(queue);
}
void test_enqueue_float_element_return_false_when_queue_is_full1(){
	Queue* queue;
	float c=10.10;
	queue = create(sizeof(float),6);
	queue->rear = 4;
	queue->front = 5;
	ASSERT(!enqueue(queue,&c));
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle(){
	Queue* queue;
	string c="vidya";
	queue = create(sizeof(string),6);
	queue->rear = 3;
	ASSERT(enqueue(queue,&c));
	ASSERT(!strcmp(*(string*)(queue->elements+queue->rear*queue->elementSize) , "vidya"));
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle1(){
	Queue* queue;
	string c="poonam";
	queue = create(sizeof(string),6);
	queue->rear = 3;
	queue->front = 5;
	ASSERT(enqueue(queue,&c));
	ASSERT(strcpy(*(string*)(queue->elements+queue->rear*queue->elementSize) , "poonam"));
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_enqueue_string_element_return_false_when_queue_is_full(){
	Queue* queue;
	string c="hi";
	queue = create(sizeof(float),6);
	queue->rear = 5;
	queue->front = -1;
	ASSERT(!enqueue(queue,&c));
	ASSERT(queue->rear == 5);
	free(queue);
}
void test_enqueue_string_element_return_false_when_queue_is_full1(){
	Queue* queue;
	string c="hi";
	queue = create(sizeof(string),6);
	queue->rear = 4;
	queue->front = 5;
	ASSERT(!enqueue(queue,&c));
	ASSERT(queue->rear == 4);
	free(queue);
}
void test_dequeue_int_element_at_front_of_queue(){
	void* element;
	Queue* queue;
	int data[]={2,3,4};
	queue = create(sizeof(int),5);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	ASSERT(queue->rear == 2);
	ASSERT(queue->front == -1);
	element = dequeue(queue);
	ASSERT(*(int*)element == 2.0f);
	ASSERT(queue->rear == 2);
	ASSERT(queue->front == 0);
}
void test_dequeue_float_element_at_front_of_queue(){
	void* element;
	Queue* queue;
	float data[]={2.0f,3.0f,4.0f};
	queue = create(sizeof(float),5);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	ASSERT(queue->rear == 2);
	ASSERT(queue->front == -1);
	element = dequeue(queue);
	ASSERT(*(float*)element == 2.0f);
	ASSERT(queue->rear == 2);
	ASSERT(queue->front == 0);
}
void test_dequeue_string_element_at_front_of_queue(){
	void* element;
	Queue* queue;
	string data[]={"sayali","shital","Samiksha"};
	queue = create(sizeof(string),5);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	ASSERT(queue->rear == 2);
	ASSERT(queue->front == -1);
	element = dequeue(queue);
	ASSERT(!strcmp(*(string*)element , "sayali"));
	ASSERT(queue->rear == 2);
	ASSERT(queue->front == 0);
}
void test_enqueue_int_element_at_rear_of_queue_at_first(){
	Queue* queue;
	void* element;
	int value[]={1,2,3,4,5,6,7,8};
	queue = create(sizeof(int),5);
	queue->rear = 4;
	queue->front = 2;
	enqueue(queue,&value[0]);
	ASSERT(queue->rear == 0);
	ASSERT(*(int*)queue->elements == 1);
	free(queue);
}