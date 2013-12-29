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
void test_sorting_five_integers_elements(){
    int length = 5;
    int elementsToSort[] = {5,4,3,2,1},sortedElements[] = {1,2,3,4,5},i;
    void* base[5] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3],&elementsToSort[4]};
    msort(base,5,sizeof(int),compareInt);
    for(i=0;i<length;i++)
        ASSERT(sortedElements[i] == *(char*)base[i]);
};