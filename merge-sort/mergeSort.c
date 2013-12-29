#include "mergeSort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int merge(void* destination , void* left , void* right , int leftlength , int rightlength,
		int elementsize , compare comp){
	int i = 0 , j = 0 , k = 0;
	while(i < leftlength && j < rightlength){
		if(comp(left + (i * elementsize),right + (i * elementsize))){
			memmove(destination + (k *elementsize),left + (i * elementsize), elementsize);
			i++;
		}
		else{
			memmove(destination + (k * elementsize),right + (j *elementsize),elementsize);
			j++;
		}
		k++;
	}
	while(j < rightlength){
		memmove(destination + k * elementsize,right + j * elementsize, elementsize);
		j++;
		k++;
	}
	while(i < leftlength){
		memmove(destination + k * elementsize,left + i * elementsize, elementsize);
		i++;
		k++;
	}
	return 1;
}
void msort(void* base, int numberOfElements,int elementSize,compare comp) {
    int mid = numberOfElements / 2,leftlength,rightlength;
    int i,j;
    void* left = calloc(mid,elementSize);
    void* right = calloc((numberOfElements-mid),elementSize);
    if(numberOfElements < 2) return;
    leftlength = mid;
    rightlength = numberOfElements - mid;
    for (i = 0; i < leftlength ; i++)
    	memmove(left + i * elementSize,base + i * elementSize, elementSize);
    for (i = mid; i < numberOfElements ; i++)
    	memmove(right + (i-mid) * elementSize,base + i * elementSize, elementSize);
    msort(left , leftlength , elementSize , comp);
    msort(right, rightlength, elementSize, comp);
    merge(base,left,right,leftlength,rightlength,elementSize,comp);
    free(left);
    free(right);
}