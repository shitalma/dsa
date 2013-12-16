#include "testUtils.h"
#include "stack_without_memecpy.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int areEqual(stack* src,stack* expected){
    int res = (src->elementsSize == expected->elementsSize)
            && (src->size == expected->size)
            && (src->top == expected->top);
            if(!res)
                return res;
            return 0==memcmp(src->elements, expected->elements, src->size*src->elementsSize);
}
void test_for_creating_stack(){
    int expectedArr[2]={0,0};
    stack expected = {expectedArr,-1,4,2};
    stack* src = create(sizeof(int),2);
    ASSERT(areEqual(src, &expected));
}

void test_for_pushing_int_element_in_stack(){
    stack* actual = create(sizeof(int),2);
    int value = 1;
    int res = push(actual,&value);
    int* data = (int*)actual->elements;
    ASSERT(data[0]==1);
    free(actual);
}
void test_for_pushing_float_element_in_stack(){
    stack* actual = create(sizeof(float),2);
    float value = 1.0;
    int res = push(actual,&value);
    float* data = (float*)actual->elements;
    ASSERT(data[0]==1.0);
    free(actual);
}
void test_for_pushing_char_element_in_stack(){
    stack* actual = create(sizeof(char),2);
    char value = 'm';
    int res = push(actual,&value);
    char* data = (char*)actual->elements;
    ASSERT(data[0]=='m');
    free(actual);
}

void test_for_pushing_double_element_in_stack(){
    stack* actual = create(sizeof(double),2);
    double value = 2.000000;
    double res = push(actual,&value);
    double* data = (double*)actual->elements;
    ASSERT(data[0]==2.000000);
    free(actual);
}

void test_for_pushing_String_element_in_stack(){
    stack* actual = create(sizeof(String),2);
    String value = "manali";
    int res = push(actual,&value);
    String* data = (String*)actual->elements;
    ASSERT(0 == strcmp((char*)data,value));
    free(actual);
}

void test_for_poping_int_element_from_stack(){
    stack* actual = create(sizeof(int),5);
    int* data = actual->elements;
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    data[3] = 4;
    data[4] = 5;
    actual->top = 4;
    ASSERT(5 ==*(int*)pop(actual));
}
void test_for_poping_float_element_from_stack(){
    stack* actual = create(sizeof(float),3);
    float* data = actual->elements;
    data[0] = 1.0;
    data[1] = 2.0;
    data[2] = 3.0;
    actual->top = 2;
    ASSERT(3.0 ==*(float*)pop(actual));
}
void test_for_poping_char_element_from_stack(){
    stack* actual = create(sizeof(char),3);
    char* data = actual->elements;
    data[0] = 'm';
    data[1] = 'a';
    data[2] = 'n';
    actual->top = 2;
    ASSERT('n' ==*(char*)pop(actual));
    ASSERT(1==actual->top);
}
void test_for_poping_double_element_from_stack(){
    stack* actual = create(sizeof(double),3);
    double* data = actual->elements;
    data[0] = 1.000000;
    data[1] = 3.000000;
    data[2] = 2.000000;
    actual->top = 2;
    ASSERT(2.000000 ==*(double*)pop(actual));
    ASSERT(1==actual->top);

}
void test_for_poping_string_element_from_stack(){
    stack* actual = create(sizeof(String),3);
    String* data = actual->elements;
    strcpy(data[0],"manali");
    strcpy(data[1],"shweta");
    strcpy(data[2],"kajal");
    actual->top = 2;
    ASSERT(0 == strcmp("kajal",*(String*)pop(actual)));
}
void test_gives_top_int_element_of_stack(){
    stack* actual = create(sizeof(int),3);
    int* data = actual->elements;
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    actual->top = 2;
    ASSERT(3 ==*(int*)top(actual));
}
void test_gives_top_float_element_of_stack(){
    stack* actual = create(sizeof(float),3);
    float* data = actual->elements;
    data[0] = 1.0;
    data[1] = 2.0;
    data[2] = 3.0;
    actual->top = 2;
    ASSERT(3.0 ==*(float*)top(actual));
}
void test_gives_top_double_element_of_stack(){
    stack* actual = create(sizeof(double),3);
    double* data = actual->elements;
    data[0] = 1.000000;
    data[1] = 2.000000;
    data[2] = 3.000000;
    actual->top = 2;
    ASSERT(3.000000 ==*(double*)top(actual));

}

void test_gives_top_char_element_of_stack(){
    stack* actual = create(sizeof(char),3);
    char* data = actual->elements;
    data[0] = 'm';
    data[1] = 'a';
    data[2] = 'n';
    actual->top = 2;
    ASSERT('n' ==*(char*)top(actual));
}
void test_gives_top_string_element_of_stack(){
    stack* actual = create(sizeof(String),3);
    String* data = actual->elements;
    strcpy(data[0],"manali");
    strcpy(data[1],"shweta");
    strcpy(data[2],"kajal");
    actual->top = 2;
    ASSERT(0 == strcmp("kajal",*(String*)top(actual)));
}