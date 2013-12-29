#include "./include/iterator.h"
#include "hashMapIterator.h"

#ifndef _hashMap_
#define _hashMap_
typedef int (*compareKeys)(void* firstElement, void* secondElement);
typedef int (*Hash_map)(void *key);

typedef struct {
	void *bucket;
	Hash_map hash;
	compareKeys areKeyEqueal;
} HashMap;

HashMap createHash(Hash_map hash, compareKeys areKeyEqueal);
int put(HashMap* map,void* key, void* value);
void* get(HashMap* map,void* key);
// int remove(HashMap* map , void* kay);
Iterator keys(HashMap* map);
#endif