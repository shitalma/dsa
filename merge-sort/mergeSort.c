#include "mergeSort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int merge(void** base , void** left , void** right , int leftlength , int rightlength,
		int elementsize , compare comp){
	int i = 0 , j = 0 , k = 0;
	while(i < leftlength && j < rightlength){
		if(comp(left[i],right[i])){
			base[k] = left[i];
			i++;
		}
		else{
			base[k] = right[j];
			j++;
		}
		k++;
	}
	while(j < rightlength){
		base[k] = right[j];
		j++;
		k++;
	}
	while(i < leftlength){
		base[k] = left[i];
		i++;
		k++;
	}
	return 1;
}
void msort(void** base, int numberOfElements,int elementSize,compare comp) {
    int mid = numberOfElements / 2,leftlength,rightlength;
    int i,j;
    void** left = calloc(mid,elementSize);
    void** right = calloc((numberOfElements-mid),elementSize);
    if(numberOfElements < 2) return;
    leftlength = mid;
    rightlength = numberOfElements - mid;
    for (i = 0; i < leftlength ; i++)
    	left[i] = base[i];
    for (i = mid; i < numberOfElements ; i++)
    	right[i-mid] = base[i];
    msort(left , leftlength , elementSize , comp);
    msort(right, rightlength, elementSize, comp);
    merge(base,left,right,leftlength,rightlength,elementSize,comp);
    free(left);
    free(right);
}