#include "testUtils.h"
#include <stdbool.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
Stack* stack;

void teardown(){
    free(stack);
}
void test_create_new_integer_stack(){
    stack = create(sizeof(int));
    ASSERT(stack->typeSize == sizeof(int));
    ASSERT(stack->top == NULL);
    ASSERT(stack->elementsPresent == 0);
    free(stack);
};

void test_pushing_an_integer_in_the_stack(){
    int element =10;
    stack = create(sizeof(int));
    push(stack,&element);
    ASSERT(*(int*)((*stack->top).element) == 10);
    ASSERT(stack->elementsPresent == 1);
    ASSERT((*stack->top).previous == NULL);
};
void test_pushing_an_float_in_the_stack(){
    float element =10;
    stack = create(sizeof(float));
    push(stack,&element);
    ASSERT(*(float*)((*stack->top).element) == 10);
    ASSERT(stack->elementsPresent == 1);
    ASSERT((*stack->top).previous == NULL);
};
void test_pushing_an_double_in_the_stack(){
    double element =10;
    stack = create(sizeof(double));
    push(stack,&element);
    ASSERT(*(double*)((*stack->top).element) == 10);
    ASSERT(stack->elementsPresent == 1);
    ASSERT((*stack->top).previous == NULL);
};
void test_pushing_an_character_in_the_stack(){
    char element ='m';
    stack = create(sizeof(char));
    push(stack,&element);
    ASSERT(*(char*)((*stack->top).element) == 'm');
    ASSERT(stack->elementsPresent == 1);
    ASSERT((*stack->top).previous == NULL);
};
void test_pushing_an_string_in_the_stack(){
    String element ="shital";
    stack = create(sizeof(String));
    push(stack,&element);
    ASSERT(!strcmp(*(String*)((*stack->top).element),"shital"));
    ASSERT(stack->elementsPresent == 1);
    ASSERT((*stack->top).previous == NULL);
};
void test_pushing_an_integers_elements_in_the_stack(){
    int element[] ={10,20,30};
    stack = create(sizeof(int));
    push(stack,&element[0]);
    push(stack,&element[1]);
    push(stack,&element[2]);
    ASSERT(*(int*)((*stack->top).element) == 30);
    ASSERT(stack->elementsPresent == 3);
};

void test_pop_integer_element_from_the_stack(){
    data* stack_element;
    int element = 10;
    stack = create(sizeof(int));
    push(stack,&element);
    stack_element = pop(stack);
    ASSERT(*(int*)stack_element->element == element);
};
void test_pop_float_element_from_the_stack(){
    data* stack_element;
    float element = 10.0;
    stack = create(sizeof(float));
    push(stack,&element);
    stack_element = pop(stack);
    ASSERT(*(float*)stack_element->element == element);
};

void test_pop_double_element_from_the_stack(){
    data* stack_element;
    double element = 10.0;
    stack = create(sizeof(double));
    push(stack,&element);
    stack_element = pop(stack);
    ASSERT(*(double*)stack_element->element == element);
};
void test_pop_char_element_from_the_stack(){
    data* stack_element;
    char element = 'a';
    stack = create(sizeof(char));
    push(stack,&element);
    stack_element = pop(stack);
    ASSERT(*(char*)stack_element->element == element);
};
void test_pop_string_element_from_the_stack(){
    data* stack_element;
    String element = "shital";
    stack = create(sizeof(String));
    push(stack,&element);
    stack_element = pop(stack);
    ASSERT(!strcmp(*(String*)stack_element->element,element));
};
void test_pop_can_not_integer_element_from_the_empty_stack(){
    data* stack_element;
    int element[] ={10,20,30};
    stack = create(sizeof(int));
    push(stack,&element[0]);
    push(stack,&element[1]);
    push(stack,&element[2]);
    ASSERT(*(int*)((*stack->top).element) == 30);
    ASSERT(stack->elementsPresent == 3);
    stack_element = pop(stack);
    stack_element = pop(stack);
    stack_element = pop(stack);
    ASSERT(*(int*)stack_element->element == element[0]);
    stack_element = pop(stack);
    ASSERT(NULL == stack_element);
};