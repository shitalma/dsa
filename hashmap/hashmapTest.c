#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

int areKeyEqueal(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void* key){
	return *(int*)key;
}
void test_add_an_element_to_hashmap(){
	int key1 = 45 , value = 1;
	HashMap hash = createHash(hashFun , areKeyEqueal);
	ASSERT(put(&hash,&key1,&value));
}