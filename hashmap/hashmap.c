#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include "./include/arrayList.h"

HashMap createHash(Hash_map hash, compareKeys areKeyEqueal){
	HashMap map;
	ArrayList bukets = create_arrayList(10);
	map.bucket = malloc(sizeof(ArrayList));
	*(ArrayList*)map.bucket = bukets;
	map.areKeyEqueal = areKeyEqueal;
	map.hash = hash; 
	return map;
}
HashNode* getHashNode(void* key , void* value){
	HashNode* hashNode = malloc(sizeof(HashNode));
	hashNode->key = key;
	hashNode->value = value;
	return hashNode;
}
int put(HashMap *map, void *key, void *value){
	DoubleList* doubleList;
	DoubleList dList;
	HashNode *hashNode;
	int bucketNumber = map->hash(key) %10;
	hashNode = getHashNode(key,value);
	doubleList = (DoubleList*)arrayList_get(map->bucket, bucketNumber);
	if(!doubleList){
		dList = create();
		insert(&dList, dList.length, hashNode);
	}
	else insert(&dList, dList.length , hashNode);
	return 1;
}