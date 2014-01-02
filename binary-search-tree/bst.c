#include "bst.h"
#include "privateBST.h"
#include <stdlib.h>

BST BSTcreate(compareFunc comp){
	BST tree = {comp , NULL};
	return tree;
}

int BSTinsert(BST *tree, void *value){
	return 1;
}
int BSTsearch(BST *tree, void *value){
	return 1;
}