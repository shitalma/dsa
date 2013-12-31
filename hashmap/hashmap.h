#include "./include/iterator.h"

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*compare)(void* firstElement, void* secondElement);
typedef int (*hash)(void *key);
#endif	
#ifndef _HASHMAP_
#define _HASHMAP_
typedef struct {
	void *buckets;
	int capacity;
	hash hashFunc;
	compare cmp;
} HashMap;

HashMap HashMap_createMap(hash hashFunc, compare compareKey,int capacity);
int HashMap_put(HashMap* map, void* key, void* value);
void* HashMap_get(HashMap* map, void* key);
int HashMap_remove(HashMap* map, void* key);
Iterator HashMap_keys(HashMap* map);
void rehash(HashMap* map);
void disposeHashMap(HashMap* map);
#endif