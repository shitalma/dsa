#include "testUtils.h"
#include "bubble_sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char String[256];
int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}
int compareChar( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}
int compareString(void* a,void* b){
    return (strcmp(*(String*)a,*(String*)b));
}

void test_1_sorting_an_array_of_integers(){
    int expected[] = {1,2,3,4};
    int actual[] = {4,3,1,2};
    bsort(actual, 4, sizeof(int), compareInt);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_2_sorting_an_array_of_floats(){
    int expected[] = {1,2,3,4};
    int actual[] = {4,3,1,2};
    bsort(actual, 4, sizeof(float), compareInt);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_3_sorting_an_array_of_strings(){
    String expected[] = {"kavita","manali","pallavi","shital"};
    String actual[] = {"shital","manali","kavita","pallavi"};
    bsort(actual, 4, sizeof(String), compareString);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_4_sorting_an_array_of_characters(){
    char expected[] = {'k','m','p','s'};
    char actual[] = {'s','m','k','p'};
    bsort(actual, 4, sizeof(char), compareChar);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_5_sorting_an_array_of_doubles(){
    double expected[] = {6.000000,7.000000,8.000000,9.000000};
    double actual[] = {8.000000,9.000000,7.000000,6.000000};
    bsort(actual, 4, sizeof(double), compareDouble);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}