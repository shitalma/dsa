#ifndef BSTree
#define BSTree

#ifndef COMPARE
#define COMPARE
	typedef int (*compareFunc) (void *a , void *b);
#endif
	
typedef struct {
	compareFunc comp;
	void *root;
} BST;

BST BSTcreate(compareFunc comp);
int BSTinsert(BST* tree , void *value);
int BSTsearch(BST* tree, void *value);
void dispose();
#endif