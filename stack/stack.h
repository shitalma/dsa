typedef struct
{
    void* element;
    void* previous;
}data;
typedef struct {
    data* top;
    int elementsPresent;
    int typeSize;
}Stack;
typedef char String[256];

Stack* create(int typeSize);
void push(Stack* stack,void* element);
data* pop(Stack* stack);