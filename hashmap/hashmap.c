#include "hashmap.h"
#include "include/dList.h"
#include "include/ArrayList.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>

void createListForEachBucket(void *bucket){
	DoubleList list;
	list  = dList_create();
	*(DoubleList*)bucket = list;
}

HashMap HashMap_createMap(hash hashFunc, compare compareKey,int capacity){
	int i;
	HashMap map;
	ArrayList buckets = ArrayList_create(capacity);
	map.buckets = malloc(sizeof(ArrayList));
	*(ArrayList*)map.buckets = buckets;
	map.cmp = compareKey;
	map.capacity = capacity;
	map.hashFunc = hashFunc;
	for(i = 0;i < map.capacity;i++)
		ArrayList_add(map.buckets, malloc(sizeof(DoubleList)));
	ArrayList_iterate(*(ArrayList*)map.buckets, createListForEachBucket);
	return map;
}

HashNode* HashMap_createHashNode(void *key, void *value){
	HashNode *hash_node = malloc(sizeof(HashNode));
	hash_node->key = key;
	hash_node->value = value;
	return hash_node;
}
void rehash(HashMap* map){
    void *key,*value;
    int i,resizeLength = map->capacity * 2;
    Iterator Keys = HashMap_keys(map);
    for(i = map->capacity;i < resizeLength;i++){
        ArrayList_add(map->buckets, malloc(sizeof(DoubleList)));
        ArrayList_iterate(*(ArrayList*)map->buckets, createListForEachBucket);
    }
    map->capacity = resizeLength;    
    while(Keys.hasNext(&Keys)){
        key = Keys.next(&Keys);
        value = HashMap_get(map, key);
        HashMap_remove(map , key);
        HashMap_put(map, key, value);
    }
}
int HashMap_put(HashMap *map, void *key, void *value){
	DoubleList *list;
	HashNode *hash_node;
	int bucketNumber;
	bucketNumber = (map->hashFunc(key)) % map->capacity;
	hash_node = HashMap_createHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	if(HashMap_get(map, key))
		HashMap_remove(map, key);
	if(list->length >=2)
		rehash(map);
	dList_insert(list, list->length, hash_node);
	return 1;
}

void* HashMap_get(HashMap *map, void *key){
    node* Node;
    HashNode* data;
    int i;
    int bucketNumber = map->hashFunc(key) % map->capacity; 
    DoubleList *list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
    if(0 == list->length) return NULL;
    Node = (node*)list->head;
    for( i = 0 ; i < list->length ; i++){
            data = (HashNode*)Node->data;
        if (0 == map->cmp(key ,data->key)) return data->value;
        Node = Node->next;
    }
    return NULL;
}
int HashMap_remove(HashMap* map, void* key){
	int bucketNumber,index = 0;
	DoubleList* list;
	HashNode* hash_node;
	Iterator it;
	bucketNumber = (map->hashFunc(key)) %10;
	list = (DoubleList*)ArrayList_get(map->buckets,bucketNumber);
	it = dList_getIterator(list);
	while(it.hasNext(&it)){
		hash_node = it.next(&it);
		if(0 == map->cmp(hash_node->key,key))
			break;
		index++;
	}
	if(index == list->length) return 0;
	return dList_delete(list,index);
}
Iterator HashMap_keys(HashMap *map){
    Iterator it1;
    Iterator it2;
    Iterator result;
    HashNode *data;
    DoubleList list = dList_create();
    it1 = ArrayList_getIterator(map->buckets);
    while(it1.hasNext(&it1)){
        it2 = dList_getIterator(it1.next(&it1));
        while(it2.hasNext(&it2)){
           data = it2.next(&it2);
           dList_insert(&list, list.length, data->key);
        }
    }
    result = dList_getIterator(&list);
    return result;
}
void disposeHashMap(HashMap *map){
    int i;
    DoubleList* listOfHashObjects;
    Iterator it;
    for(i = 0 ; i < map->capacity ; i++){
        listOfHashObjects = (DoubleList*)ArrayList_get(map->buckets,i);
        dList_dispose(*listOfHashObjects);
    };
    free(map->buckets);
};