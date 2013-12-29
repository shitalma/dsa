#include "testUtils.h"
#include "hashmap.h"	
#include <string.h>
#include <stdio.h>

int areKeyEqueal(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2; 
}
int hashFun(void* key){
	return *(int*)key;
}
void test_add_an_element_to_hashmap(){
	int key1 = 45 , value1 = 1;
	int key2 = 46 , value2 = 2;
	int key3 = 46 , value3 = 2;
	HashMap hash = createHash(hashFun , areKeyEqueal);
	ASSERT(put(&hash,&key1,&value1));
	ASSERT(put(&hash,&key2,&value2));
	ASSERT(put(&hash,&key3,&value3));
}
void test_get_an_element_from_hashmap(){
	int key1 = 45 , value1 = 1;
	void* result;
	HashMap hash = createHash(hashFun , areKeyEqueal);
	ASSERT(put(&hash,&key1,&value1));
	result = get(&hash,&key1);
	printf("%d\n",*(int*)result);
	// ASSERT(get(&hash,&key1));
}