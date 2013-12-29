#include "testUtils.h"
#include "mergeSort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char String[256];
int compareInt (void* a,  void* b){
    return (*(int*)a < *(int*)b);
}
int compareDouble( void* a,  void* b){
    return (*(double*)a < *(double*)b);
}
int compareChar( void* a,  void* b){
    return (*(char*)a < *(char*)b);
}
void test_1_sorting_an_array_of_integers(){
	int i;
    int actual[] = {4,3,1,2};
    msort(&actual,4,sizeof(int),compareInt);
    for(i = 0 ; i < 4 ; i++)
    	ASSERT(actual[i] == i+1);
}