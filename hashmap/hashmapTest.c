#include "testUtils.h"
#include "hashmap.h"
#include <string.h>
#include <stdlib.h>

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
Intern shital = {15445,"Shital"};
Intern kajal = {15345,"Kajal"};
Intern sayali = {15349,"Sayali"};
Intern tanbir = {15348,"Tanbir"};
void test_add_an_element_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(0 == strcmp(shital.value,(char*)HashMap_get(&map, &shital.key)));
	disposeHashMap(&map);
}
void test_add_multiple_elements_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(HashMap_put(&map, &manali.key, &manali.value));
	ASSERT(HashMap_put(&map, &kajal.key, &kajal.value));
	ASSERT(0 == strcmp(shital.value,(char*)HashMap_get(&map, &shital.key)));
	ASSERT(0 == strcmp(manali.value,(char*)HashMap_get(&map, &manali.key)));
	ASSERT(0 == strcmp(kajal.value,(char*)HashMap_get(&map, &kajal.key)));
	disposeHashMap(&map);
}
void test_get_not_found_data_in_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(NULL == HashMap_get(&map, &manali.key));
	disposeHashMap(&map);
}
void test_remove_data_from_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(1 == HashMap_remove(&map, &shital.key));
	ASSERT(NULL == HashMap_get(&map, &shital.key));
	disposeHashMap(&map);
}
void test_remove_data_from_hashmap_when_data_not_present(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(0 == HashMap_remove(&map, &manali.key));
	disposeHashMap(&map);
}
void test_keys_of_hashmap_gives_all_keys_in_map(){
    void* data;
	Iterator it;
    HashMap map = HashMap_createMap(hashFun, areKeyEqual);
    ASSERT(HashMap_put(&map,&manali.key , &manali.value));
    // ASSERT(HashMap_put(&map,&key2 , &data2));
    // ASSERT(HashMap_put(&map,&key3 , &data3));
    // ASSERT(HashMap_put(&map,&key4 , &data4));
    // ASSERT(HashMap_put(&map,&key5 , &data5));
	HashMap_keys(&map);
    ASSERT(15441 == *(int*)it.next(&it));
    // ASSERT(1235 == *(int*)it.next(&it));
    // ASSERT(1243 == *(int*)it.next(&it));
    // ASSERT(1266 == *(int*)it.next(&it));
    // ASSERT(1278 == *(int*)it.next(&it));
	disposeHashMap(&map);
}