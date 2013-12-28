#include "bubble_sort.h"
#include <stdlib.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
void swap(void** base, int j){
    void* temp;
    temp = base[j];
    base[j] = base[j+1];
    base[j+1] = temp;
}

void bsort(void** base, int numberOfElements, int elementSize, compare comp) {
    int i, j;
    int comparisonResult;
    for (i = 1 ; i < numberOfElements; i++) {
        for (j = 0 ; j < numberOfElements-i ; j++) {
    		if(0 < comp(base[j],base[j+1])) swap(base,j);
       	}
	}
}