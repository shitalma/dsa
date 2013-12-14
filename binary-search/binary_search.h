#include <stdbool.h>
typedef char String[50];
typedef int compareFunction(void* , void*);
void* search_generic(void* array,void* key,int length,int elementSize,compareFunction* compare);
