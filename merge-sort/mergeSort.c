#include "mergeSort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(void** base,void** left,void** right,int leftlength,int rightlength,
	compare comp){
	int i = 0 , j = 0 , k = 0;
	for(;i < leftlength && j < rightlength;k++){
		if(comp(left[i],right[i])){
			base[k] = left[i];
			i++;
		}
		else{
			base[k] = right[j];
			j++;
		}
	}
	for(;j < rightlength; j++,k++)
		base[k] = right[j];
	for(;i < leftlength;i++,k++)
		base[k] = left[i];
}

void msort(void** base, int numberOfElements,int elementSize,compare comp) {
    int mid = numberOfElements / 2,leftlength = mid,
    	rightlength = numberOfElements - mid,i;
    void** left = calloc(mid,elementSize);
    void** right = calloc((numberOfElements-mid),elementSize);
    if(numberOfElements < 2) return;

    for (i = 0; i < leftlength ; i++)  left[i] = base[i];
    for (i = mid; i < numberOfElements ; i++)  right[i-mid] = base[i];
    	
    msort(left , leftlength , elementSize , comp);
    msort(right, rightlength, elementSize, comp);
    merge(base,left,right,leftlength,rightlength,comp);
    free(left);
    free(right);
}