typedef int (*compare)(void* first, void* second);
void isort(void* base, int numberOfElements, int elementSize,
			compare comp); 