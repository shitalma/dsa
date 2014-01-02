#include "bst.h"
#include "privateBST.h"
#include <stdlib.h>
#include <stdio.h>

BSTNode* getParent(BSTNode *node,void *value,compareFunc fun){
	if(fun(value,node->data) == 0)
		return NULL;
	if(NULL == node->left && NULL == node->right)
		return node;
	if(fun(value,node->data) < 0)
		return getParent(node->left, value, fun);
	else return getParent(node->right, value, fun);
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
		tree->root = createBSTNode(value);
		return 1;
	}
	node = getParent(tree->root,value,tree->comp);
	if(node){
		if(tree->comp(value,node->data) > 0)
			node->right = createBSTNode(value);
		else node->left = createBSTNode(value);
	}
	else return 0;
	return 1;
}
int BSTsearch(BST *tree, void *value){
	BSTNode *parentNode,*rootNode;
	rootNode = tree->root;
	if(NULL == rootNode) return 0;
	if(NULL == getParent(rootNode, value, tree->comp))
		return 1;
	return 0;
}