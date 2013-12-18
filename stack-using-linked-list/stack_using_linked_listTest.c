#include "testUtils.h"
#include <stdlib.h>
#include "stack_using_linked_list.h"

typedef char String[256];
List* list;

void tearDown(){
    free(list);
}
// ------------------ CREATE ---------------------
void test_inserts_an_element_as_the_head_of_linklist_for_integer(){
    int num = 10;
    list = create();
    ASSERT(!(!push(list,&num)));
}
void test_inserts_elements_at_the_end_of_linkList_for_integer(){
    int value[] = {10,12};
    list = create();
    ASSERT(!(!push(list,&value)));
    ASSERT(!(!push(list,&value)));
}
void test_inserts_elements_at_the_end_of_linkList_for_character(){
    char value[] = {'a','b'};
    list = create();
    ASSERT(!(!push(list,&value)));
    ASSERT(!(!push(list,&value)));
}
void test_inserts_elements_at_the_end_of_linkList_for_string(){
    String value[] = {"shital","komal"};
    list = create();
    ASSERT(!(!push(list,&value)));
    ASSERT(!(!push(list,&value)));
}
void test_deletes_last_element_in_the_linkList(){
    int nums[] = {10,15,16,17};
    void* result;
    list = create();
    ASSERT(!(!push(list,&nums[0])));
    ASSERT(!(!push(list,&nums[1])));
    ASSERT(!(!push(list,&nums[2])));
    result = pop(list);
    ASSERT(*(int*)result == 16);
    result = pop(list);
    ASSERT(*(int*)result == 15);
    result = pop(list);
    ASSERT(*(int*)result == 10);
}
void test_deletes_last_element_in_the_linkList_for_character(){
    char nums[] = {'a','b','c','d'};
    void* result;
    list = create();
    ASSERT(!(!push(list,&nums[0])));
    ASSERT(!(!push(list,&nums[1])));
    ASSERT(!(!push(list,&nums[2])));
    result = pop(list);
    ASSERT(*(char*)result == 'c');
    result = pop(list);
    ASSERT(*(char*)result == 'b');
    result = pop(list);
    ASSERT(*(char*)result == 'a');
}