#include "testUtils.h"
#include "binary_search.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// --------------------------- Compare Functions ------------------------------------

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble (void* a, void* b){
    return (*(double*)a - *(double*)b);
}
int compareString(void *a, void *b){ 
 	return (strcmp((char *)a,(char *)b));
}
int compareChar(void* a, void* b){
	return (*(char*)a - *(char*)b);
}

// ------------------------- Search For Integer -------------------------------------

void test_1_search_element_from_the_collection_of_integers(){
    int elements[5] = {7,8,9,10,11};
    int key = 8;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(8 == *result);
    ASSERT(&elements[1] == result);
};
void test_2_search_element_from_the_collection_of_integers_which_not_found(){
    int elements[5] = {4,6,7,8,2};
    int key = 9;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT((int*)result == NULL);
};
void test_3_search_1st_element_from_the_collection_of_integers(){
    int elements[5] = {4,6};
    int key = 4;
    int* result = search_generic(elements,&key, 2, sizeof(int), compareInt);
    ASSERT(4 == *result);
    ASSERT(&elements[0] == result);
};
void test_4_search_middle_element_from_the_collection_of_integers(){
    int elements[5] = {4,6,7,8,2};
    int key = 7;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(7 == *result);
    ASSERT(&elements[2] == result);
};
void test_5_search_last_element_from_the_collection_of_integers(){
    int elements[] = {4,6,7,8,9};
    int key = 9;
    int* result = search_generic(elements,&key, 5, sizeof(int), compareInt);
    ASSERT(9 == *result);
    ASSERT(&elements[4] == result);
};

// ------------------------- Search For Float -------------------------------------

void test_6_search_element_from_the_collection_of_floats(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 6.4f;
    float* result = search_generic(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(6.4f == *result);
    ASSERT(&elements[1] == result);
};
void test_7_search_element_from_the_collection_of_floats_which_is_not_found(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 4.6f;
    float* result = search_generic(elements,&key, 5, sizeof(float), compareInt);
    ASSERT(NULL == (float*)result);
};
void test_8_search_element_from_the_collection_of_doubles(){
    double elements[5] = {1.0,2.0,3.0,4.0,5.0};
    double key = 3.0;
    double* result = search_generic(elements,&key, 5, sizeof(double), compareDouble);
    ASSERT(3.0 == *result);
    ASSERT(&elements[2] == result);
};

// ------------------------- Search For String -------------------------------------

void test_9_search_element_from_the_collection_of_Strings(){
    String elements[3] = {"shital","snehal","komal"};
    String key = "shital";
    String* result = search_generic(elements,&key, 3, sizeof(String), compareString);
    ASSERT(!(strcmp("shital",*result)));
    ASSERT(&elements[0] == result);
};
void test_10_search_element_from_the_collection_of_Strings_which_is_not_found(){
    String elements[3] = {"shital","snehal","komal"};
    String key = "sham";
    String* result = search_generic(elements,&key, 3, sizeof(String), compareString);
    ASSERT(NULL == (String*)result);
};

// ---------------------- Search For Character --------------------------------------

void test_11_search_element_from_the_collection_of_characters(){
    char elements[3] = {'m','a','n'};
    char key = 'a';
    char* result = search_generic(elements,&key, 3, sizeof(char), compareChar);
    ASSERT('a' == *result);
    ASSERT(&elements[1] == result);
};
void test_12_search_element_from_the_collection_of_characters_which_is_not_found(){
    char elements[3] = {'m','a','n'};
    char key = 'k';
    char* result = search_generic(elements,&key, 3, sizeof(char), compareChar);
    ASSERT(NULL == (char*)result);
};

void test_13_search_first_element_from_the_collection_for_characters_if_elements_are_same(){
    char elements[2] = {'m','m'};
    char key = 'm';
    char* result = search_generic(elements,&key, 2, sizeof(char), compareChar);
    ASSERT('m' == *result);
    ASSERT(&elements[0] == result);
};
void test_14_search_last_element_from_the_collection_for_characters_if_elements_are_same_with_diff_characters(){
    char elements[3] = {'m','m','a'};
    char key = 'm';
    char* result = search_generic(elements,&key, 3, sizeof(char), compareChar);
    ASSERT('m' == *result);
    ASSERT(&elements[1] == result);
};