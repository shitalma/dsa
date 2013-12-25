#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

const int INSERT_SUCCESSFUL = 1;
int compareInts(void *a,void *b){
    return *(int*)a - *(int*)b;
}
void test_insert_root_node(){
    Tree tree = createTree(compareInts);
    int data = 2;
    int result = insertToTree(&tree, NULL, &data);
    ASSERT(INSERT_SUCCESSFUL == result);
}
void test_insert_node_under_root_node(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    insertToTree(&tree, NULL, &data[0]);
    insertToTree(&tree, &data[0], &data[1]);
    insertToTree(&tree, &data[0], &data[2]);
    result = getChildren(&tree, &data);
    ASSERT(5 == *(int*)result.next(&result));
    ASSERT(3 == *(int*)result.next(&result));
}
void test_insert_under_child_node(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    insertToTree(&tree, NULL, &data[0]);
    insertToTree(&tree, &data[0], &data[1]);
    insertToTree(&tree, &data[1], &data[2]);
    result = getChildren(&tree, &data[1]);
    ASSERT(5 == *(int*)result.next(&result));
}
void test_for_search_an_element_into_the_tree(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    int searchElement = 3;
    insertToTree(&tree, NULL, &data[0]);
    insertToTree(&tree, &data[0], &data[1]);
    insertToTree(&tree, &data[1], &data[2]);
    result = getChildren(&tree, &data[1]);
    ASSERT(5 == *(int*)result.next(&result));
    ASSERT(search(&tree,&searchElement));
}
void test_for_not_search_an_element_into_the_tree(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    int searchElement = 9;
    insertToTree(&tree, NULL, &data[0]);
    insertToTree(&tree, &data[0], &data[1]);
    insertToTree(&tree, &data[1], &data[2]);
    result = getChildren(&tree, &data[1]);
    ASSERT(5 == *(int*)result.next(&result));
    ASSERT(!search(&tree,&searchElement));
}
void test_for_delete_an_element_from_tree(){
    Tree tree = createTree(compareInts);
    int data[] = {2,3,5};
    Iterator result;
    insertToTree(&tree, NULL, &data[0]);
    insertToTree(&tree, &data[0], &data[1]);
    insertToTree(&tree, &data[1], &data[2]);
    result = getChildren(&tree, &data[0]);
    ASSERT(3 == *(int*)result.next(&result));
    ASSERT(deleteChildren(&tree,&data[1]));
    result = getChildren(&tree, &data[0]);
    printf("%d\n",*(int*)result.next(&result) );
    ASSERT(3 == *(int*)result.next(&result));
}