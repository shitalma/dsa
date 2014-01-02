#include "bst.h"
#include "privateBST.h"
#include <stdlib.h>
#include <stdio.h>

BSTNode* getParent(BSTNode *node,void *value,compareFunc fun){
	if(fun(value,node->data) == 0)
		return NULL;
	if(fun(value,node->data) < 0){
		if(NULL == node->left)
			return node;
		return getParent(node->left, value, fun);
	}
	if(NULL == node->right)
		return node;	
 	return getParent(node->right, value, fun);
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
		return 1;
	}
	return 0;
}
int BSTsearch(BST *tree, void *value){
	BSTNode *parentNode,*rootNode;
	rootNode = tree->root;
	if(NULL == rootNode) return 0;
	if(NULL == getParent(rootNode, value, tree->comp))
		return 1;
	return 0;
}
Children getChildren(BST *tree, void *parent){
	Children children = {NULL,NULL}; 
	BSTNode *parentNode,*leftNode,*rightNode;
	parentNode = tree->root;

	if(NULL == parentNode)
		return children;
	if(tree->comp(parent,parentNode->data) == 0){
		leftNode = parentNode->left;
		rightNode = parentNode->right;
		children.leftData = leftNode->data;
		children.rightData = rightNode->data;
	}
	return children;
}

void dispose(BST *tree){

}