#include "testUtils.h"
#include "circular_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char string[50];
Queue* queue;
void teardown(){
	free(queue);
}
void test_enqueue_char_element_in_the_queue(){
	char c[] = {'K','L','M','N','O'};
	queue = create(sizeof(char),6);
	ASSERT(enqueue(queue,&c[0]));
	ASSERT(enqueue(queue,&c[1]));
	ASSERT(enqueue(queue,&c[2]));
	ASSERT(enqueue(queue,&c[3]));
	ASSERT(enqueue(queue,&c[4]));
}
void test_enqueue_char_element_return_false_when_queue_is_full(){
	char c[]= {'Q','P'};
	queue = create(sizeof(char),2);
	ASSERT(enqueue(queue,&c[0]));
	ASSERT(enqueue(queue,&c[1]));
	ASSERT(!enqueue(queue,&c[0]));
}
void test_enqueue_float_element_at_rear_of_queue(){
	float c[]= {1.0,2.0};
	queue = create(sizeof(float),2);
	ASSERT(enqueue(queue,&c[0]));
	ASSERT(enqueue(queue,&c[1]));
}
void test_enqueue_string_element_at_rear_of_queue(){
	string c = "hi";
	queue = create(sizeof(string),5);
	ASSERT(enqueue(queue,&c));
}
void test_enqueue_string_element_return_false_when_queue_is_full(){
	string c[] = {"hi","bye"};
	queue = create(sizeof(float),2);
	ASSERT(enqueue(queue,&c[0]));
	ASSERT(enqueue(queue,&c[1]));
	ASSERT(!enqueue(queue,&c[0]));
}
void test_dequeue_int_element_at_front_of_queue(){
	int data[]={2,3,4};
	void* element;
	queue = create(sizeof(int),5);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	element = dequeue(queue);
	ASSERT(*(int*)element == 2);
}
void test_dequeue_float_element_at_front_of_queue(){
	void* element;
	float data[]={2.0f,3.0f,4.0f};
	queue = create(sizeof(float),5);
	enqueue(queue,&data[0]);
	enqueue(queue,&data[1]);
	enqueue(queue,&data[2]);
	element = dequeue(queue);
	ASSERT(*(float*)element == 2.0f);
}
void test_dequeue_string_element_at_front_of_queue(){
	void* element;
	string data[]={"sayali","shital","Samiksha"};
	queue = create(sizeof(string),5);
	ASSERT(enqueue(queue,&data[0]));
	ASSERT(enqueue(queue,&data[1]));
	ASSERT(enqueue(queue,&data[2]));
	element = dequeue(queue);
	ASSERT(!strcmp(*(string*)element , "sayali"));
}
void test_dequeue_int_element_at_rear_of_queue_at_first(){
	void* element;
	int value[]={1,2,3,4,5,6,7,8};
	queue = create(sizeof(int),5);
	ASSERT(enqueue(queue,&value[0]));
	ASSERT(enqueue(queue,&value[1]));
	ASSERT(enqueue(queue,&value[2]));
	ASSERT(enqueue(queue,&value[3]));
	ASSERT(enqueue(queue,&value[4]));
	element = dequeue(queue);
	element = dequeue(queue);
	ASSERT(*(int*)element == 2);
	ASSERT(enqueue(queue,&value[5]));
	element = dequeue(queue);
	ASSERT(*(int*)element == 3);
	ASSERT(enqueue(queue,&value[6]));
	element = dequeue(queue);
	ASSERT(*(int*)element == 4);
	ASSERT(enqueue(queue,&value[7]));
	element = dequeue(queue);
	ASSERT(*(int*)element == 5);
}
void test_dequeue_int_element_will_return_if_circular_queue_is_actually_full(){
	void* element;
	int value[]={1,2,3,4,5,6,7,8};
	queue = create(sizeof(int),5);
	ASSERT(enqueue(queue,&value[0]));
	ASSERT(enqueue(queue,&value[1]));
	ASSERT(enqueue(queue,&value[2]));
	ASSERT(enqueue(queue,&value[3]));
	ASSERT(enqueue(queue,&value[4]));
	element = dequeue(queue);
	element = dequeue(queue);
	ASSERT(enqueue(queue,&value[6]));
	ASSERT(false == enqueue(queue,&value[7]));
}