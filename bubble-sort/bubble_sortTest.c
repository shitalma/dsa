#include "testUtils.h"
#include "bubble_sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

void test_sorting_five_integers_elements(){
    int length = 5;
    int elementsToSort[] = {5,4,3,2,1},sortedElements[] = {1,2,3,4,5},i;
    void* base[5] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3],&elementsToSort[4]};
    bsort(base,5,sizeof(int),compareInt);
    for(i=0;i<length;i++)
        ASSERT(sortedElements[i] == *(char*)base[i]);
};
void test_sorting_float_elements(){
    float elementToSort[] = {10.5f,1.5f,2.5f,7.5f},sortedElements[] = {1.5f,2.5f,7.5f,10.5f};
    int i;
    void *base[4] = {&elementToSort[0],&elementToSort[1],&elementToSort[2],&elementToSort[3]};
    bsort(base,4,sizeof(float),compareInt);
    for(i=0;i<4;i++)
            ASSERT(sortedElements[i] == *(float*)base[i]);
};

void test_sorting_double_elements(){
    double elementsToSort[] = {10.5,1.5,2.5,7.5},sortedElements[] = {1.5,2.5,7.5,10.5};
    int i;
    void *base[4] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3]};
    bsort(base,4,sizeof(double),compareDouble);
    for(i=0;i<4;i++)
        ASSERT(sortedElements[i] == *(double*)base[i]);        
};
void test_sorting_character_elements(){
    char elementsToSort[] = {'d','c','b','a'};
    char sortedElements[] = {'a','b','c','d'};
    int i;
    void *base[4] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3]};
    bsort(base,4,sizeof(char),compareChar);
    for(i=0;i<4;i++)
        ASSERT(sortedElements[i] == *(char*)base[i]);        
}
void test_sorting_string_elements(){
    String elementsToSort[] = {"shital","pooja","manali","kavita"};
    String sortedElements[] = {"kavita","manali","pooja","shital"};
    int i;
    void *base[4] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2],&elementsToSort[3]};
    bsort(base,4,sizeof(String),compareString);
    for(i=0;i<4;i++)
        ASSERT(0 == strcmp(sortedElements[i] , *(String*)base[i]));        
}