#include "testUtils.h"
#include "simple_queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// ----------------------- CREATE ----------------------------------
Queue* intQueue;
Queue* floatQueue;
Queue* doubleQueue;
Queue* charQueue;
Queue* stringQueue;

void setup(){
        intQueue = create(sizeof(int),5);
        floatQueue = create(sizeof(float),5);
        doubleQueue = create(sizeof(double),5);
        charQueue = create(sizeof(char),5);
        stringQueue = create(sizeof(string),5);
}
void tearDown(){
        free(intQueue);
        free(floatQueue);
        free(doubleQueue);
        free(charQueue);
        free(stringQueue);

}
void test_1_create_queue_allocates_memory_for_five_char_elements(){
        int i;
        int test_arr[] = {0,0,0,0,0};
        i = memcmp(test_arr,charQueue->elements,5);
        ASSERT(!i);
        ASSERT(charQueue->elementSize == sizeof(char));
        ASSERT(charQueue->rear == -1);
        ASSERT(charQueue->no_of_elements == 5);
}
void test_2_create_queue_allocates_memory_for_five_int_elements(){
        int i;
        int test_arr[] = {0,0,0,0,0};
        i=memcmp(test_arr,intQueue->elements,5);
        ASSERT(!i);
        ASSERT(intQueue->elementSize == 4);
        ASSERT(intQueue->rear == -1);
        ASSERT(intQueue->no_of_elements == 5);
}
void test_3_create_queue_allocates_memory_for_five_float_elements(){
        int i;
        int test_arr[] = {0,0,0,0,0};
        i=memcmp(test_arr,floatQueue->elements,5);
        ASSERT(!i);
        ASSERT(floatQueue->elementSize==sizeof(float));
        ASSERT(floatQueue->rear==-1);
        ASSERT(floatQueue->no_of_elements==5);
}
void test_4_create_queue_allocates_memory_for_five_char_strings(){
        int i;
        string test_arr[] = {0,0,0,0,0};
        i=memcmp(test_arr,stringQueue->elements,5);
        ASSERT(!i);
        ASSERT(stringQueue->elementSize==sizeof(string));
        ASSERT(stringQueue->rear==-1);
        ASSERT(stringQueue->no_of_elements == 5);
}

// ---------------------------- ENQUE ---------------------------------

void test_5_enqueue_char_element_at_rear_of_queue(){
        int c='a';
        ASSERT(enqueue(charQueue,&c));
        ASSERT(*(char*)(charQueue->elements) == 'a');
        ASSERT(charQueue->rear == 0);
        ASSERT(charQueue->no_of_elements==5);
}
void test_6_enqueue_int_element_at_rear_of_queue(){
        int c=5;
        ASSERT(enqueue(intQueue,&c));
        ASSERT(*(int*)(intQueue->elements)==5);
        ASSERT(intQueue->rear==0);
        ASSERT(intQueue->no_of_elements==5);
}
void test_7_enqueue_float_element_at_rear_of_queue(){
        float c=1.5;
        floatQueue->rear = 1;
        ASSERT(enqueue(floatQueue,&c));
        ASSERT(floatQueue->rear == 2);
        ASSERT(floatQueue->no_of_elements == 5);
        ASSERT(*(float*)(floatQueue->elements+
                floatQueue->rear*floatQueue->elementSize) == 1.5);
}
void test_8_enqueue_string_element_at_rear_of_queue(){
        string c = "hi";
        ASSERT(enqueue(stringQueue,&c));
        ASSERT(!strcmp("hi", *(string*)stringQueue->elements));
        ASSERT(stringQueue->rear == 0);
        ASSERT(stringQueue->no_of_elements == 5);
}

// ----------------------- DEQUEUE -------------------------------

void test_9_dequeue_char_element_at_rear_of_queue(){
        int i;
        char* element;
        char test_arr1[] = {'b','c','d','d',0};
        char test_arr[]={'a','b','c','d',0};
        enqueue(charQueue, &test_arr[0]);
        enqueue(charQueue, &test_arr[1]);
        enqueue(charQueue, &test_arr[2]);
        enqueue(charQueue, &test_arr[3]);
        element = dequeue(charQueue);
        i=memcmp(test_arr1,charQueue->elements,5*sizeof(char));
        ASSERT(!i);
        ASSERT(*element == 'a');
        ASSERT(charQueue->elementSize==sizeof(char));
        ASSERT(charQueue->rear==2);
}
void test_10_dequeue_int_element_at_rear_of_queue(){
        int i , element;
        int test_arr[]={1,2,3,4,0};
        int test_arr1[] = {2,3,4,4,0};
        enqueue(intQueue, &test_arr[0]);
        enqueue(intQueue, &test_arr[1]);
        enqueue(intQueue, &test_arr[2]);
        enqueue(intQueue, &test_arr[3]);
        element = (int)dequeue(intQueue);
        ASSERT(!memcmp(test_arr1,intQueue->elements,5));
        ASSERT(*(int*)element == 1);
        ASSERT(intQueue->elementSize==4);
        ASSERT(intQueue->rear==2);
}
void test_11_dequeue_float_element_at_rear_of_queue(){
        int i;
        void* element;
        float test_arr[]={1.0,2.0,3.0,4.0,0};
        float test_arr1[]={2.0,3.0,4.0,4.0,0};
        enqueue(floatQueue, &test_arr[0]);
        enqueue(floatQueue, &test_arr[1]);
        enqueue(floatQueue, &test_arr[2]);
        enqueue(floatQueue, &test_arr[3]);
        element = dequeue(floatQueue);
        ASSERT(!memcmp(test_arr1,floatQueue->elements,5));
        ASSERT(*(float*)element == 1.0);
        ASSERT(floatQueue->rear==2);
}
void test_12_dequeue_string_element_at_start_of_queue(){
        void* element;
        int i;
        string data[] = {"hi","hw","r","u"};
        enqueue(stringQueue,&data[0]);
        enqueue(stringQueue,&data[1]);
        enqueue(stringQueue,&data[2]);
        enqueue(stringQueue,&data[3]);
        element = dequeue(stringQueue);
        ASSERT(!strcmp("hw",stringQueue->elements));
        ASSERT(!strcmp("hi",*(string*)element));
        ASSERT(stringQueue->rear == 2);
};
void test_13_isFull_return_true_if_queue_is_full(){
        int data[]={1,2,3,4,0};
        enqueue(intQueue,&data[0]);
        enqueue(intQueue,&data[1]);
        enqueue(intQueue,&data[2]);
        enqueue(intQueue,&data[3]);
        enqueue(intQueue,&data[4]);
        ASSERT(true == isFull(intQueue));
}
void test_14_isFull_return_false_if_queue_is_not_full(){
        int data[]={1,2,3,0,0};
        enqueue(floatQueue,&data[0]);
        enqueue(floatQueue,&data[1]);
        enqueue(floatQueue,&data[2]);
        enqueue(floatQueue,&data[3]);
        ASSERT(false == isFull(floatQueue));
}
void test_15_isEmpty_return_true_if_queue_is_empty(){
        intQueue->rear=-1;
        ASSERT(true == isEmpty(intQueue));
}
void test_16_isEmpty_return_false_if_queue_is_not_empty(){
        int test_arr[]={1,2,3,0,0};
        enqueue(intQueue, &test_arr[0]);
        enqueue(intQueue, &test_arr[1]);
        enqueue(intQueue, &test_arr[2]);
        ASSERT(false == isEmpty(intQueue));
}