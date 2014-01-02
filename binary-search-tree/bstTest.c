#include "testUtils.h"
#include "bst.h"
#include <stdio.h>
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
	int value[] = {6,7,3};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTinsert(&tree,&value[1]));
	
	ASSERT(1 == BSTsearch(&tree,&value[0]));
	ASSERT(1 == BSTsearch(&tree,&value[1]));
	ASSERT(0 == BSTsearch(&tree,&value[2]));
}
void test_insert_in_binary_tree_value_lesser_than_root_should_insert_on_left(){
	BST tree;
	int value[] = {6,5,8};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTinsert(&tree,&value[1]));
	
	ASSERT(1 == BSTsearch(&tree,&value[0]));
	ASSERT(1 == BSTsearch(&tree,&value[1]));
	ASSERT(0 == BSTsearch(&tree,&value[2]));
}
void test_insert_at_diffrent_levels_of_binary_tree(){
	BST tree;
	int value[] = {6,5,8,4};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTinsert(&tree,&value[1]));
	ASSERT(1 == BSTinsert(&tree,&value[3]));

	ASSERT(1 == BSTsearch(&tree,&value[0]));
	ASSERT(1 == BSTsearch(&tree,&value[1]));
	ASSERT(1 == BSTsearch(&tree,&value[3]));
	ASSERT(0 == BSTsearch(&tree,&value[2]));
}
void test_get_children_of_root(){
	BST tree;
	int value[] = {4,3,8};
	Children root_s_children;
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTinsert(&tree,&value[1]));
	ASSERT(1 == BSTinsert(&tree,&value[2]));
	root_s_children = getChildren(&tree,&value[0]);
	ASSERT(value[1] == *(int*)root_s_children.leftData);
	ASSERT(value[2] == *(int*)root_s_children.rightData);
}
void test_remove_an_element_from_root(){
	BST tree;
	int value[] = {4,3,8};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTremove(&tree,&value[0]));
	ASSERT(0 == BSTsearch(&tree,&value[0]));
}
void test_remove_an_element_from_second_level_left_element(){
	BST tree;
	int value[] = {4,3,8};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTinsert(&tree,&value[1]));
	ASSERT(1 == BSTremove(&tree,&value[1]));
	ASSERT(0 == BSTsearch(&tree,&value[1]));
}
void test_remove_an_element_from_second_level_right_element(){
	BST tree;
	int value[] = {4,3,8};
	tree = BSTcreate(compare);
	ASSERT(1 == BSTinsert(&tree,&value[0]));
	ASSERT(1 == BSTinsert(&tree,&value[2]));
	ASSERT(1 == BSTremove(&tree,&value[2]));
	ASSERT(0 == BSTsearch(&tree,&value[2]));
}