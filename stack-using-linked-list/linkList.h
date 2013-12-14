typedef struct node{
    void* data;
    struct node *next;
}Node;
typedef struct list{
	Node* head;
	int length;
}slist;

slist* create();
int insert(slist *list,int index,void* data);
void* deleteNode(slist* list,int index);