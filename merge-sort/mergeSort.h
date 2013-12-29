typedef int (*compare)(void* first, void* second);
void msort(void** base, int numberOfElements, int elementSize,
			compare comp); 