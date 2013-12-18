typedef struct{
    void *elements;
    int top;
    int elementsSize;
    int length;
}Stack;
Stack* create(int elementsSize,int size);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);