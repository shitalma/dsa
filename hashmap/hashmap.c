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
HashMap HashMap_createMap(hash hashFunc, compare compareKey){
	HashMap map;
	int i;
	ArrayList buckets = ArrayList_create(10);
	map.buckets = malloc(sizeof(ArrayList));
	*(ArrayList*)map.buckets = buckets;
	map.cmp = compareKey;
	map.hashFunc = hashFunc;
	for(i = 0;i < 10;i++)
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
int HashMap_put(HashMap *map, void *key, void *value){
	DoubleList *list;
	HashNode *hash_node;
	int bucketNumber;
	bucketNumber = (map->hashFunc(key)) % 10;
	hash_node = HashMap_createHashNode(key, value);
	list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
	if(HashMap_get(map, key))
		HashMap_remove(map, key);
	dList_insert(list, list->length, hash_node);
	return 1;
}
void* HashMap_get(HashMap *map, void *key){
    node* Node;
    HashNode* data;
    int i;
    int bucketNumber = map->hashFunc(key) % 10; 
    DoubleList *list = (DoubleList*)ArrayList_get(map->buckets, bucketNumber);
    if(0 == list->length) return NULL;
    Node = (node*)list->head;
    for(i=0;i<list->length;i++){
            data = (HashNode*)Node->data;
        if (!map->cmp(key ,data->key)) return data->value;
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
void HashMap_keys(HashMap *map){
	Iterator Arrayiterator = ArrayList_getIterator(map->buckets);
	Iterator listIterator;
	int i = 0;
	void* data[100];
	HashNode hash_node;
	while(Arrayiterator.hasNext(&Arrayiterator)){
		listIterator = dList_getIterator(Arrayiterator.next(&Arrayiterator));
		while(listIterator.hasNext(&listIterator)){
			hash_node = (*(HashNode*)listIterator.next(&listIterator));
			data[i] = hash_node.key;
			i++;
		}
	}
	for(i = 0 ; i < 5 ; i++)
		printf("%d\n",*(int*)data[i]);
}
