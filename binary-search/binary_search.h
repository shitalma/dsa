typedef int compareFunction(void* key , void* element);
void* search_generic(void* array,void* key,int length,int elementSize,compareFunction* compare);