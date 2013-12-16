#include "testUtils.h"
#include "os_schedular.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

scheduler *q;
void teardown(){
    free(q);
}
int compareInt(void* a , void* b){
    return (*(int*)a - *(int*)b);
}
void test_for_create_a_new_process(){
	scheduler expected = {NULL,0};
    q = create();
    ASSERT(q->front == expected.front);
    ASSERT(q->length == expected.length);
}
void test_for_adding_front_process(){
	scheduler expected = {NULL,0};
    condition status = {0,1,0};
    pro firstProcess = {"firstProcess",3000,status,7,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess,compareInt));
    ASSERT(q->front == &firstProcess);
    ASSERT(q->front->next == NULL);
}
void test_for_adding_process_that_have_high_priority_rather_than_first(){
	scheduler expected = {NULL,0};
    condition status = {0,1,0};
    pro firstProcess = {"firstProcess",3000,status,7,NULL};
    pro secondProcess = {"secondProcess",900,status,1,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess,compareInt));
    ASSERT(2 == insert(q, &secondProcess,compareInt));
    ASSERT(q->front == &secondProcess);
    ASSERT(q->front->next == &firstProcess);
}
void test_add_process_with_priority_in_between_process_queue(){
	scheduler expected = {NULL,0};
    condition status = {0,1,0};
    pro *second,*third;
    pro firstProcess = {"First Process",3000,status,7,NULL};
    pro secondProcess = {"Second Process",900,status,1,NULL};
    pro thirdProcess = {"Third Process",400,status,2,NULL};
    q = create();
    ASSERT(1 == insert(q, &firstProcess,compareInt));
    ASSERT(2 == insert(q, &secondProcess,compareInt));
    ASSERT(3 == insert(q, &thirdProcess,compareInt));
    ASSERT(q->front == &secondProcess);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &thirdProcess);
    ASSERT(third == &firstProcess);
    ASSERT(third->next == NULL);
}
void test_add_process_with_very_low_priority(){
    condition statusp1 = {0,1,0};
    pro *second,*third,*fourth,*fifth;
    pro p1 = {"p1",1000,statusp1,5,NULL};
    pro p2 = {"p2",500,statusp1,1,NULL};
    pro p3 = {"p3",400,statusp1,3,NULL};
    pro p4 = {"p4",400,statusp1,2,NULL};
    pro p5 = {"p5",400,statusp1,8,NULL};
    q = create();
    ASSERT(1 == insert(q, &p1,compareInt));
    ASSERT(2 == insert(q, &p2,compareInt));
    ASSERT(3 == insert(q, &p3,compareInt));
    ASSERT(4 == insert(q, &p4,compareInt));
    ASSERT(5 == insert(q, &p5,compareInt));
    second = q->front->next;
    third = second->next;
    fourth = third->next;
    fifth = fourth->next;
    ASSERT(fifth == &p5);
    ASSERT(NULL == fifth->next);
}
void test_remove_first_and_only_process(){
    condition statusp1 = {0,1,0};
    pro p1 = {"p1",0,statusp1,5,NULL};
    q = create();
    insert(q, &p1,compareInt);
    ASSERT(0 == removeProcess(q));
    ASSERT(NULL == q->front);
}
void test_remove_processes_in_middle(){
    condition statusp1 = {0,1,0};
    pro p1 = {"p1",1000,statusp1,1,NULL};
    pro p2 = {"p2",0,statusp1,5,NULL};
    pro p3 = {"p3",1000,statusp1,7,NULL};
    q = create();
    insert(q, &p1,compareInt);
    insert(q, &p2,compareInt);
    insert(q, &p3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front->next == &p3);
}
void test_remove_last_process(){
    condition statusp1 = {0,1,0};
    pro p1 = {"p1",1000,statusp1,1,NULL};
    pro p2 = {"p2",10,statusp1,5,NULL};
    pro p3 = {"p3",0,statusp1,7,NULL};
    q = create();
    insert(q, &p1,compareInt);
    insert(q, &p2,compareInt);
    insert(q, &p3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front->next->next == NULL);
}
void test_remove_first_in_many(){
    condition statusp1 = {0,1,0};
    pro p1 = {"p1",0,statusp1,1,NULL};
    pro p2 = {"p2",10,statusp1,5,NULL};
    pro p3 = {"p3",65,statusp1,7,NULL};
    q = create();
    insert(q, &p1,compareInt);
    insert(q, &p2,compareInt);
    insert(q, &p3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front == &p2);
}