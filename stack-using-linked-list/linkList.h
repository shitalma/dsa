typedef struct node{
    void* data;
    struct node *next;
}Node;
typedef struct list{
	Node* head;
	int length;
}List;

List* create();
int insert(List *list,int index,void* data);
void* deleteNode(List* list,int index);