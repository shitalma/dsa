#include "testUtils.h"
#include "stack_without_memecpy.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef char String[50];

Stack* actual;
void tearDown(){
    free(actual);
}
void test_for_pushing_integer_element_in_stack(){
    int value = 1,res;
    actual = create(sizeof(int),2);
    res = push(actual,&value);
    ASSERT(res == 1);
}
void test_for_pushing_float_element_in_stack(){
    int res;
    float value = 1.0;
    actual = create(sizeof(float),2);
    res = push(actual,&value);
    ASSERT(res == 1);
}
void test_for_pushing_char_element_in_stack(){
    char value = 'm';
    int res;
    actual = create(sizeof(char),2);
    res = push(actual,&value);
    ASSERT(res == 1);        
}
void test_for_pushing_double_element_in_stack(){
    double value = 2.000000;
    int res;
    actual = create(sizeof(double),2);
    res = push(actual,&value);
    ASSERT(res == 1);
}
void test_for_pushing_String_element_in_stack(){
    String value = "manali";
    int res;
    actual = create(sizeof(String),2);
    res = push(actual,&value);
    ASSERT(res == 1);
}
void test_for_poping_int_element_from_stack(){
    int values[] = {1,2,3,4,5};
    actual = create(sizeof(int),5);
    push(actual,&values[0]);
    push(actual,&values[1]);
    push(actual,&values[2]);
    push(actual,&values[3]);
    push(actual,&values[4]);
    ASSERT(5 ==*(int*)pop(actual));
}
void test_for_poping_float_element_from_stack(){
    float values[] = {1.0,2.0,3.0};
    actual = create(sizeof(float),3);
    push(actual,&values[0]);
    push(actual,&values[1]);
    push(actual,&values[2]);
    ASSERT(3.0 ==*(float*)pop(actual));
}
void test_for_poping_char_element_from_stack(){
    char values[] = {'m','a','n'};
    actual = create(sizeof(char),3);
    push(actual,&values[0]);
    push(actual,&values[1]);
    push(actual,&values[2]);
    ASSERT('n' ==*(char*)pop(actual));
}
void test_for_poping_string_element_from_stack(){
    String values[] = {"manali","shital","kavita"};
    actual = create(sizeof(String),3);
    push(actual,&values[0]);
    push(actual,&values[1]);
    push(actual,&values[2]);
    ASSERT(!strcmp("kavita",*(String*)pop(actual)));
}
void test_for_poping_double_element_from_stack(){
    double values[] = {2.0,3.0,4.0};
    actual = create(sizeof(double),3);
    push(actual,&values[0]);
    push(actual,&values[1]);
    push(actual,&values[2]);
    ASSERT(4.0 ==*(double*)pop(actual));
    ASSERT(3.0 ==*(double*)pop(actual));
    push(actual,&values[0]);
    ASSERT(2.0 ==*(double*)pop(actual));
}
void test_gives_top_int_element_of_stack(){
    int values[] = {1,2,3};
    actual = create(sizeof(int),3);
    push(actual,&values[0]);
    push(actual,&values[1]);
    push(actual,&values[2]);
    ASSERT(3 ==*(int*)top(actual));
}