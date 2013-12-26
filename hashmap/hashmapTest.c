#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqueal(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void* key){
	return *(int*)key;
}

typedef struct {
	int key;
	char* data[30];
} Intern;

Intern shital = {15442 , "Shital"};
Intern snehal = {15443 , "Snehal"};
Intern komal = {15444 , "Komal"};

void test_add_an_element_to_hashmap(){
	HashMap hash = createHash(hashFun , areKeyEqueal);
	ASSERT(put(&hash,&shital.key,&shital.data));
	ASSERT(strcmp(get(&hash,&shital.key),"Shital"));
}