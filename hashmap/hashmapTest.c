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
	int rollNo;
	char name[50];
}student;

student manali = {15441,"Manali"};
student shital = {15445,"Shital"};
student kajal = {15345,"Kajal"};
student kavita = {12345,"Kajal"};
student samiksha = {13345,"Kajal"};
student sayali = {15349,"Sayali"};
student tanbir = {15348,"Tanbir"};

void test_add_an_element_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.rollNo, &shital.name));
	ASSERT(0 == strcmp(shital.name,(char*)HashMap_get(&map, &shital.rollNo)));
	disposeHashMap(&map);
}
void test_add_multiple_elements_to_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.rollNo, &shital.name));
	ASSERT(HashMap_put(&map, &manali.rollNo, &manali.name));
	ASSERT(HashMap_put(&map, &kajal.rollNo, &kajal.name));
	ASSERT(0 == strcmp(shital.name,(char*)HashMap_get(&map, &shital.rollNo)));
	ASSERT(0 == strcmp(manali.name,(char*)HashMap_get(&map, &manali.rollNo)));
	ASSERT(0 == strcmp(kajal.name,(char*)HashMap_get(&map, &kajal.rollNo)));
	disposeHashMap(&map);
}
void test_get_not_found_data_in_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.rollNo, &shital.name));
	ASSERT(NULL == HashMap_get(&map, &manali.rollNo));
		disposeHashMap(&map);
}
void test_remove_data_from_hashmap(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.rollNo, &shital.name));
	ASSERT(1 == HashMap_remove(&map, &shital.rollNo));
	ASSERT(NULL == HashMap_get(&map, &shital.rollNo));
	disposeHashMap(&map);
}
void test_remove_data_from_hashmap_when_data_not_present(){
	HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
	ASSERT(HashMap_put(&map, &shital.rollNo, &shital.name));
	ASSERT(0 == HashMap_remove(&map, &manali.rollNo));
	disposeHashMap(&map);
}
void test_rollNos_of_hashmap_gives_all_rollNos_in_map(){
	Iterator it;
    HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
    ASSERT(HashMap_put(&map,&manali.rollNo , &manali.name));
    ASSERT(HashMap_put(&map,&shital.rollNo , &shital.name));
    ASSERT(HashMap_put(&map,&kajal.rollNo , &kajal.name));
    ASSERT(HashMap_put(&map,&sayali.rollNo , &sayali.name));
    ASSERT(HashMap_put(&map,&tanbir , &tanbir.name));
	it = HashMap_keys(&map);
    ASSERT(15441 == *(int*)it.next(&it));
    ASSERT(15445 == *(int*)it.next(&it));
    ASSERT(15345 == *(int*)it.next(&it));
    ASSERT(15348 == *(int*)it.next(&it));
    ASSERT(15349 == *(int*)it.next(&it));
	disposeHashMap(&map);
}
void test_rehash_elements_to_hashmap(){
    Iterator it;
    int rollNo1 = 2, data1 = 1;
    int rollNo2 = 3, data2 = 2;
    int rollNo3 = 4, data3 = 3;
    int rollNo4 = 5, data4 = 4;
    int rollNo5 = 14, data5 = 5;
    int rollNo6 = 24, data6 = 6;
    int rollNo7 = 6, data7 = 7;
    HashMap map = HashMap_createMap(hashFun, areKeyEqual,10);
    ASSERT(HashMap_put(&map,&rollNo1 , &data1));
    ASSERT(HashMap_put(&map,&rollNo2 , &data2));
    ASSERT(HashMap_put(&map,&rollNo3 , &data3));
    ASSERT(HashMap_put(&map,&rollNo4 , &data4));
    ASSERT(HashMap_put(&map,&rollNo5 , &data5));
    ASSERT(HashMap_put(&map,&rollNo6 , &data6));
    ASSERT(HashMap_put(&map,&rollNo7 , &data7));
    it = HashMap_keys(&map);
    ASSERT(2 == *(int*)it.next(&it));
    ASSERT(3 == *(int*)it.next(&it));
    ASSERT(4 == *(int*)it.next(&it));
    ASSERT(24 == *(int*)it.next(&it));
    ASSERT(5 == *(int*)it.next(&it));
    ASSERT(6 == *(int*)it.next(&it));
    ASSERT(14 == *(int*)it.next(&it));
	disposeHashMap(&map);
}