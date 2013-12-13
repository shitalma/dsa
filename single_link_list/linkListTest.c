#include "linkList.h"
#include "testUtils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

slist* list;

void tearDown(){
        free(list);
}
void display(Node *q){
	if(q==NULL) printf("not data available\n");;
     while(q!=NULL){ 
     printf("\n%d",*(int*)q->data);
     q=q->next;
    }
}
void test_gives_an_singly_link_list_with_head_NULL(){
    list = create();
    ASSERT(NULL == list->head);
    ASSERT(0 == list->length);
}

void test_inserts_an_element_as_the_head_of_linklist_for_integer(){
    int num = 10;
    list = create();
    insert(list, 0,&num);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
}
void test_inserts_elements_at_the_end_of_linkList_for_integer(){
    int value;
    Node *result1,*result2;
    list = create();
    value = 10;
    insert(list,0,&value);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
    
    value = 12;
    insert(list,1,&value);
    result1 = list->head->next;
    ASSERT(12 == *(int*)result1->data);
    ASSERT(NULL == result1->next);
    ASSERT(2 == list->length);
    
    value = 14;
    insert(list,2,&value);
    result2 = result1->next;
    ASSERT(14 == *(int*)result2->data);
    ASSERT(NULL == result2->next);
    ASSERT(3 == list->length);
}

void test_adds_element_in_middle_of_linkList_integer(){
    Node *second,*third,*fourth;
    int* nums = malloc(sizeof(int)*4);
    nums[0] = 12;nums[1] = 14;nums[2] = 15;nums[3] = 20;
    list = create();
    insert(list, 0, nums+0);
    ASSERT(1 == list->length);
	insert(list,1,nums+2);
    ASSERT(2 == list->length);
    insert(list,2,nums+3);
    ASSERT(3 == list->length);
    insert(list,1,nums+1);
    ASSERT(4 == list->length);
    second = list->head->next;
    third = second->next;
	fourth = third->next;
    ASSERT(12 == *(int*)list->head->data);
    ASSERT(15 == *(int*)second->data);
    ASSERT(14 == *(int*)third->data);
    ASSERT(20 == *(int*)fourth->data);    
}

void test_inserts_multiple_element_as_the_head_of_linklist_for_integer(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;nums[1] = 15;nums[2] = 16;
    insert(list, 0, nums);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(1 == list->length);
    insert(list,0,nums+1);
    ASSERT(15 == *(int*)list->head->data);
    insert(list,0,nums+2);
    ASSERT(16 == *(int*)list->head->data);
    ASSERT(3 == list->length);
}

void test_inserts_the_doubles_in_the_linklist(){
    double* nums = malloc(sizeof(double)*3);
    list = create();
    nums[0] = 1.0;nums[1] = 2.0; nums[2] = 3.0;
    insert(list, 0,&nums[0]);
    ASSERT(1.0 == *(double*)list->head->data);
    ASSERT(1 == list->length);
    insert(list,1,&nums[1]);
    ASSERT(2.0 == *(double*)list->head->next->data);
    ASSERT(2 == list->length);
    insert(list,1,&nums[2]);
    ASSERT(3 == list->length);
}
void test_inserts_the_chars_in_the_linklist(){
    char* chars = malloc(sizeof(char)*3);
    list = create();
    chars[0] = 'a';chars[1] = 'n'; chars[2] = 'm';
    insert(list, 0, &chars[0]);
    ASSERT('a' == *(char*)list->head->data);
    ASSERT(1 == list->length);
    insert(list, 1, &chars[1]);
    ASSERT('n' == *(char*)list->head->next->data);
    ASSERT(2 == list->length);
    insert(list, 1, &chars[2]);
    ASSERT('n' == *(char*)list->head->next->data);
    ASSERT(3 == list->length);
}
typedef char String_256[256];
typedef struct
{
        int accNo;
        int balance;
}Account;

int areAccountsEqual(Account expected,Account actual){
        return expected.accNo == actual.accNo && expected.balance == actual.balance;
}

void test_inserts_the_strings_in_the_linklist(){
    String_256* names = malloc(sizeof(String_256)*3);
    list = create();
    strcpy(names[0], "shital");
    strcpy(names[1], "Sayali");
    strcpy(names[2], "Shweta");
    insert(list, 0, &names[0]);
    ASSERT(0 == strcmp("shital",(char*)list->head->data));
    ASSERT(1 == list->length);
    insert(list, 1, &names[1]);
    ASSERT(0 == strcmp("Sayali",(char*)list->head->next->data));
    ASSERT(2 == list->length);
    insert(list, 1, &names[2]);
    ASSERT(0 == strcmp("Sayali",(char*)list->head->next->data));
    ASSERT(3 == list->length);
}

void test_inserts_the_structures_in_the_linklist(){
    Account* accounts = malloc(sizeof(Account)*3);
    list = create();
    accounts[0].accNo = 100;accounts[0].balance = 1000;
    accounts[1].accNo = 101;accounts[1].balance = 2000;
    accounts[2].accNo = 102;accounts[2].balance = 4000;
    insert(list,  0,&accounts[0]);
    ASSERT(areAccountsEqual(accounts[0], *(Account*)list->head->data));
    ASSERT(1 == list->length);
    insert(list, 1, &accounts[1]);
    ASSERT(areAccountsEqual(accounts[1], *(Account*)list->head->next->data));
    ASSERT(2 == list->length);
    insert(list, 1, &accounts[2]);
    ASSERT(areAccountsEqual(accounts[1], *(Account*)list->head->next->data));
    ASSERT(3 == list->length);
}

void test_deletes_first_element_in_list_with_one_element(){
    int* nums = malloc(sizeof(int));
    *nums = 5;
        list = create();
    insert(list, 0, nums);
    ASSERT(deleteNode(list, 0));
   ASSERT(0 == list->length);
    ASSERT(NULL == list->head);
}
void test_deletes_first_element_in_list_when_more_than_one_elements(){
    int* nums = malloc(sizeof(int)*3);
        list = create();
        nums[0] = 10;nums[1] = 15;nums[2] = 16;
    insert(list, 0,&nums[0]);
    insert(list, 1,&nums[1]);
    insert(list, 2,&nums[2]);
    ASSERT(3 == list->length);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(deleteNode(list, 0));
    ASSERT(2 == list->length);
    ASSERT(15 == *(int*)list->head->data);
}
void test_deletes_last_element_in_the_linkList(){
    int* nums = malloc(sizeof(int)*3);
        list = create();
        nums[0] = 10;nums[1] = 15;nums[2] = 16;
    insert(list, 0,&nums[0]);
    insert(list, 1,&nums[1]);
    insert(list, 2,&nums[2]);
    ASSERT(deleteNode(list, 2));
    ASSERT(2 == list->length);
    ASSERT(NULL == list->head->next);
}
void test_deletes_element_in_between(){
    int* nums = malloc(sizeof(int)*3);
        list = create();
        nums[0] = 10;nums[1] = 15;nums[2] = 16;
    insert(list, 0,&nums[0]);
    insert(list, 1,&nums[1]);
    insert(list, 2,&nums[2]);
    ASSERT(deleteNode(list, 1));
    ASSERT(2 == list->length);
    ASSERT(16 == *(int*)list->head->data);
}