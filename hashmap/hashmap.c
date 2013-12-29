#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include "./include/arrayList.h"

HashMap createHash(Hash_map hash, compare arekeyEqueal){
    ArrayList buckets = create_arrayList(10);
    HashMap map;
    int i;
    DoubleList list;
    map.bucket = malloc(sizeof(ArrayList));
    *(ArrayList*)map.bucket = buckets;
    map.areKeyEqueal = arekeyEqueal;
    (*(ArrayList*)map.bucket).length = 10;
    map.hash = hash;
    for(i=0;i<10;i++){
            ((ArrayList*)map.bucket)->base[i] = malloc(sizeof(DoubleList));
            list = create();
            *(DoubleList*)(((ArrayList*)map.bucket)->base[i]) = list;
    }
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
	HashNode *hashNode;
	int bucketNumber = map->hash(key) % 10;
	hashNode = getHashNode(key,value);
	doubleList = (DoubleList*)arrayList_get(map->bucket, bucketNumber);
	insert(doubleList, doubleList->length, hashNode);
	return 1;
}
void* get(HashMap *map, void *key){
    DoubleList* doubleList;
    DoubleList dList;
    HashNode *hash_node;
    int bucketNumber = (map->hash(key) % 10);
	doubleList = (DoubleList*)arrayList_get(map->bucket, bucketNumber);
	printf("%p\n",doubleList );
	hash_node = (HashNode*)getData(dList, &key, map->areKeyEqueal);
	return hash_node->value;
}