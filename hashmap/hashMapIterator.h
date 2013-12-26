typedef struct {
	void* nodes;
} HashMapIterator;
void* next(HashMapIterator* it);
int hasNext(HashMapIterator* it);