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
int compareFloat( void* a,  void* b){
    return (*(float*)a - *(float*)b);
}
int compareChar( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}
int compareString(void* a,void* b){
    return (strcmp(*(String*)a,*(String*)b));
}

void test_1_sorting_an_array_of_integers(){
	int i ;
    int expected[] = {1,2,3,4};
    int actual[] = {4,3,1,2};
    bsort(actual, 4, sizeof(int), compareInt);
    for(i = 0 ; i < 4 ; i++)
	    printf("%d\n",actual[i]);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}