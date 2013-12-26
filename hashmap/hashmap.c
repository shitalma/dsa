#include "hashmap.h"
#include "internalHashMap.h"
#include <stdlib.h>

HashMap createHash(Hash_map hash, compareFunc areKeyEqueal){
	HashMap hashData = {NULL,hash,areKeyEqueal};
	return hashData;
}
int put(HashMap *map, void *key, void *value){
	return 1;
}
void* get(HashMap *map, void *key){
	void* data = (char*)"shital";
	return data;
}