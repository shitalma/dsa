#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqual(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int hashFun(void *key){
	return *(int*)key;
};
typedef struct{
	int key;
	char value[50];
} Intern;
Intern manali = {15441,"Manali"};
Intern shital = {15442,"Shital"};
Intern kajal = {15345,"Kajal"};

void test_add_an_element_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(0 == strcmp(shital.value,(char*)HashMap_get(&map, &shital.key)));
}
void test_add_multiple_elements_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(HashMap_put(&map, &manali.key, &manali.value));
	ASSERT(HashMap_put(&map, &kajal.key, &kajal.value));
	ASSERT(0 == strcmp(shital.value,(char*)HashMap_get(&map, &shital.key)));
	ASSERT(0 == strcmp(manali.value,(char*)HashMap_get(&map, &manali.key)));
	ASSERT(0 == strcmp(kajal.value,(char*)HashMap_get(&map, &kajal.key)));
}
