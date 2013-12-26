#include "./include/iterator.h"
#include "hashMapIterator.h"

#ifndef _hashMap_
#define _hashMap_
typedef int (*compareFunc)(void* firstElement, void* secondElement);
typedef int (*Hash_map)(void *key);

typedef struct {
	void *bucket;
	Hash_map hash;
	compareFunc areKeyEqueal;
} HashMap;

HashMap createHash(Hash_map hash, compareFunc areKeyEqueal);
int put(HashMap* map,void* key, void* value);
void* get(HashMap* map,void* key);
int remove(HashMap* map , void* kay);
Iterator keys(HashMap* map);
#endif