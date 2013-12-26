#include "bubble_sort.h"
#include <stdlib.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
void bsort(void* base, int numberOfElements, int elementSize,
			compare comp) {
    int i, j;
    void* temp = calloc(1, elementSize);
    void* elementToCompare;
    void* nextElement;
    int comparisonResult;
    for (i = 0; i < numberOfElements; i++) {
    	elementToCompare = base + i * elementSize;
        for (j = i+1; j < numberOfElements; j++) {
    		nextElement = base + (j) * elementSize;
    		comparisonResult = comp(elementToCompare,nextElement);
            if (comparisonResult > 0){
            	memcpy(temp , nextElement , elementSize);
            	memcpy(nextElement, elementToCompare, elementSize);
            	memcpy(elementToCompare, temp, elementSize);
            }

       	}
	}
}