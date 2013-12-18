#include "testUtils.h"
#include "prority_queue.h"
#include "custom-type.h"
#include <string.h>

int compareInt(void* a , void* b){
    return (*(int*)a - *(int*)b);
}
void test_1_enqueues_an_integer_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    void* queue = createQueue();
    int value = 10;
    ASSERT(1 == enqueue(queue, &value,30,compareInt));
    ASSERT(value == *(int*)dequeue(queue));
};

void test_2_enqueues_the_integer_elements_in_queue_and_dequeue_the_first_element_based_on_priority(){
    void* queue = createQueue();
    int value[] = {10,15};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],20,compareInt));
    ASSERT(value[1] == *(int*)dequeue(queue));
};
void test_3_enqueues_an_float_element_in_empty_queue_and_gives_back_that_element_when_dequeued_based_on_priority(){
    void* queue = createQueue();
    float value[] = {10.0,15.0};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],20,compareInt));
    ASSERT(value[1] == *(float*)dequeue(queue));
};
void test_4_enqueues_an_int_element_in_empty_queue_and_gives_back_that_element_when_dequeued_based_on_priority(){
    void* queue = createQueue();
    int value[] = {10,20,30};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],20,compareInt));
    ASSERT(1 == enqueue(queue, &value[2],40,compareInt));
    ASSERT(value[2] == *(int*)dequeue(queue));
};