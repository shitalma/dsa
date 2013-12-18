#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
void test_for_enqueing_integer_element_in_queue(){
	Queue* actual = create(2,sizeof(int));
	int value = 1;
	ASSERT(1 == enqueue(actual,&value));
	free(actual);
}

void test_for_enqueing_float_element_in_queue(){
	Queue* actual = create(2,sizeof(float));
	float value = 89.0;
	ASSERT(1 == enqueue(actual,&value));
	free(actual);
}

void test_for_enqueing_double_element_in_queue(){
	Queue* actual = create(2,sizeof(double));
	double value = 89.0;
	ASSERT(1 == enqueue(actual,&value));
	free(actual);
}

void test_for_enqueing_string_element_in_queue(){
	Queue* actual = create(2,sizeof(String));
	String value = "shital";
	ASSERT(1 == enqueue(actual,&value));
	free(actual);
}

void test_for_enqueing_character_element_in_queue(){
	Queue* actual = create(2,sizeof(char));
	char value = 'A';
	ASSERT(1 == enqueue(actual,&value));
	free(actual);
}

void test_for_dequeueing_integer_element_from_queue(){
	Queue* actual = create(sizeof(int),5);
	void* result;
	int value[] = {3,4};
	ASSERT(1 == enqueue(actual, &value[0]));
	ASSERT(1 == enqueue(actual, &value[1]));
	result = (int*)dequeue(actual);
	ASSERT(*(int*)result == 3);
	free(actual);
}

void test_for_dequeueing_float_element_from_queue(){
	Queue* actual = create(sizeof(float),5);
	float value[] = {3,4};
	void* result;
	ASSERT(1 == enqueue(actual, &value[0]));
	ASSERT(1 == enqueue(actual, &value[1]));
	result = (float*)dequeue(actual);
	ASSERT(*(float*)result == 3);
}