#ifndef BinarySearchTree
#define BinarySearchTree

#ifndef COMPARE
#define COMPARE
	typedef int (*compareFunc) (void *a , void *b);
#endif

typedef struct {
	void *leftData;
	void *rightData;
} Children;

typedef struct {
	compareFunc comp;
	void *root;
} BST;

BST BSTcreate(compareFunc comp);
int BSTinsert(BST* tree , void *value);
int BSTsearch(BST* tree, void *value);
int BSTremove(BST* tree, void *value);
Children getChildren(BST* tree, void *parent);
void dispose();
#endif