#include "testUtils.h"
#include "bst.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compare(void* a , void* b){
	return *(int*)a - *(int*)b;
}

void test_insert_in_binary_tree(){
	BST tree;
	int value = 6;
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value));
	ASSERT(1 == BSTsearch(&tree,&value));
}
