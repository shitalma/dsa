#include "linkList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

slist* create(){
	slist* list;
	list = (slist*)malloc(sizeof(slist));
	list->head = NULL;
	list->length = 0;
	return list;
}
int insertAtFront(Node* newNode,slist* list,int index,Node* head){
	if(index == 0){
		list->head = newNode;
	    return 1;
    }
    return 0;
}
int insertAtEnd(Node* newNode,slist* list,int index,Node* head){
	if(index == list->length){               
        head->next = newNode;
		return 1;
    }
    return 0;
}
void insertAtMiddle(Node* newNode,Node* head){
	newNode->next = head->next;
	head->next = newNode;
}
int insert(slist *list,int index,void* data){
    Node *head,*newNode;
    int i;
    if(index <= -1 || index > list->length)
    	return 0;
    list->length++;
	head = list->head;
    for (i = 0; i < index; ++i){
    	if(head->next != NULL)
    		head = head->next;
    }
    newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
	if(1 == insertAtFront(newNode,list,index,head)) return 1;
	if(1 == insertAtEnd(newNode,list,index,head)) return 1;
	insertAtMiddle(newNode, head);
    return 1;
}
void* deleteNode(slist* list,int index){
    int i;
    void* data;
    Node *head, *deletedNode;
    head = list->head;
    for(i = 0;i < index; i++)
        head = head->next;
    data = head->data;
    list->length--;
    return data;
};