typedef int (*compare)(void* first, void* second);
void bsort(void** base, int numberOfElements, int elementSize,
			compare comp); 