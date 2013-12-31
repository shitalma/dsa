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
Intern kavita = {12345,"Kajal"};
Intern samiksha = {13345,"Kajal"};
Intern sayali = {15349,"Sayali"};
Intern tanbir = {15348,"Tanbir"};
void test_add_an_element_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(0 == strcmp(shital.value,(char*)HashMap_get(&map, &shital.key)));
	disposeHashMap(&map);
}
void test_add_multiple_elements_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(HashMap_put(&map, &manali.key, &manali.value));
	ASSERT(HashMap_put(&map, &kajal.key, &kajal.value));
	ASSERT(0 == strcmp(shital.value,(char*)HashMap_get(&map, &shital.key)));
	ASSERT(0 == strcmp(manali.value,(char*)HashMap_get(&map, &manali.key)));
	ASSERT(0 == strcmp(kajal.value,(char*)HashMap_get(&map, &kajal.key)));
	disposeHashMap(&map);
}
void test_get_not_found_data_in_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(NULL == HashMap_get(&map, &manali.key));
		disposeHashMap(&map);
}
void test_remove_data_from_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(1 == HashMap_remove(&map, &shital.key));
	ASSERT(NULL == HashMap_get(&map, &shital.key));
	disposeHashMap(&map);
}
void test_remove_data_from_hashmap_when_data_not_present(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.key, &shital.value));
	ASSERT(0 == HashMap_remove(&map, &manali.key));
	disposeHashMap(&map);
}
void test_keys_of_hashmap_gives_all_keys_in_map(){
	Iterator it;
    HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
    ASSERT(HashMap_put(&map,&manali.key , &manali.value));
    ASSERT(HashMap_put(&map,&shital.key , &shital.value));
    ASSERT(HashMap_put(&map,&kajal.key , &kajal.value));
    ASSERT(HashMap_put(&map,&sayali.key , &sayali.value));
    ASSERT(HashMap_put(&map,&tanbir , &tanbir.value));
	it = HashMap_keys(&map);
    ASSERT(15441 == *(int*)it.next(&it));
    ASSERT(15445 == *(int*)it.next(&it));
    ASSERT(15345 == *(int*)it.next(&it));
    ASSERT(15348 == *(int*)it.next(&it));
    ASSERT(15349 == *(int*)it.next(&it));
	disposeHashMap(&map);
}
void test_rehash_elements_to_hashmap(){
    void* data;
    Iterator it;
    int key1 = 2, data1 = 1;
    int key2 = 3, data2 = 2;
    int key3 = 4, data3 = 3;
    int key4 = 5, data4 = 4;
    int key5 = 14, data5 = 5;
    int key6 = 24, data6 = 6;
    int key7 = 6, data7 = 7;
    HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
    ASSERT(HashMap_put(&map,&key1 , &data1));
    ASSERT(HashMap_put(&map,&key2 , &data2));
    ASSERT(HashMap_put(&map,&key3 , &data3));
    ASSERT(HashMap_put(&map,&key4 , &data4));
    ASSERT(HashMap_put(&map,&key5 , &data5));
    ASSERT(HashMap_put(&map,&key6 , &data6));
    ASSERT(HashMap_put(&map,&key7 , &data7));
    it = HashMap_keys(&map);
    
    ASSERT(2 == *(int*)it.next(&it));
    ASSERT(3 == *(int*)it.next(&it));
    ASSERT(4 == *(int*)it.next(&it));
    ASSERT(24 == *(int*)it.next(&it));
    ASSERT(5 == *(int*)it.next(&it));
    ASSERT(6 == *(int*)it.next(&it));
    ASSERT(14 == *(int*)it.next(&it));

}