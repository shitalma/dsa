#include "testUtils.h"
#include "bst.h"

int compare(void* a , void* b){
	return *(int*)a - *(int*)b;
}

void test_insert_in_binary_tree(){
	BST tree;
	int value[] = {6,7};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTsearch(&tree,&value[0]));
	ASSERT(0 == BSTsearch(&tree,&value[1]));
}
void test_insert_in_binary_tree_value_greater_than_root_should_insert_on_right(){
	BST tree;
	int value[] = {6,7};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTinsert(&tree,&value[1]));
	
	ASSERT(1 == BSTsearch(&tree,&value[0]));
	ASSERT(1 == BSTsearch(&tree,&value[1]));
}
