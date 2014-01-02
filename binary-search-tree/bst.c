#include "bst.h"
#include "privateBST.h"
#include <stdlib.h>

BSTNode* getParent(BSTNode *node,void *value,compareFunc fun){
	
	if(fun(node->data,value) < 0){
		if(NULL == node->left)
			return node;
		else return getParent(node->left, value, fun);
	}
	if(fun(node->data,value) > 0){
		return getParent(node->right, value, fun);
	}
	return NULL;
}

BST BSTcreate(compareFunc comp){
	BST tree = {comp , NULL};
	return tree;
}
BSTNode* createBSTNode(void *data){
	BSTNode *node = malloc(sizeof(BSTNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
} 
int BSTinsert(BST *tree, void *value){
	BSTNode *nodeToInsert,*node;
	if(NULL == tree->root){
		// nodeToInsert = 
		tree->root = createBSTNode(value);
		return 1;
	}
	node = getParent(tree->root,value,tree->comp);
	tree->root = nodeToInsert;
	return 1;
}
int BSTsearch(BST *tree, void *value){
	BSTNode *parentNode = getParent(tree->root,value,tree->comp);
	if(NULL == parentNode) return 1;
	return 0;
}