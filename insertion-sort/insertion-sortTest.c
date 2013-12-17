#include "testUtils.h"
#include "insertion-sort.h"
#include <stdio.h>
#include <memory.h>
typedef char String[256];
typedef struct {
        int accountNumber;
        int balance;
} Account;
int areAccountsEqual(Account* expected,Account* actual){
    int result = expected->accountNumber == actual->accountNumber && 
                                        expected->balance == actual->balance;
    return result;
}
int compareAccountsByAccountNumber(void* first, void* second) {
        Account* firstAccount = (Account*)first;
        Account* secondAccount = (Account*)second;
        return firstAccount->accountNumber - secondAccount->accountNumber;
}
int compareAccountsByBalance(void* first, void* second) {
        Account* firstAccount = (Account*)first;
        Account* secondAccount = (Account*)second;
        return firstAccount->balance - secondAccount->balance;
}
int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}
int compareFloat( void* a,  void* b){
    return (*(float*)a - *(float*)b);
}
int compareChar( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}
int compareString(void* a,void* b){
    return (strcmp(*(String*)a,*(String*)b));
}
void test_1_sorting_an_array_of_integers(){
    int expected[] = {1,2,3,4};
    int actual[] = {4,3,1,2};
    isort(actual, 4, sizeof(int), compareInt);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_2_sorting_an_array_of_double(){
    double expected[] = {1.000000,2.000000,3.000000,4.000000};
    double actual[] = {4.000000,3.000000,1.000000,2.000000};
    isort(actual, 4, sizeof(double), compareDouble);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_3_sorting_an_array_of_float(){
    float expected[] = {1.0,2.0,3.0,4.0};
    float actual[] = {4.0,3.0,1.0,2.0};
    isort(actual, 4, sizeof(float), compareFloat);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_4_sorting_an_array_of_character(){
    char expected[] = {'a','b','c','d'};
    char actual[] = {'d','c','b','a'};
    isort(actual, 4, sizeof(char), compareChar);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_5_sorting_an_array_of_string(){
    String expected[] = {"a","b","c","d"};
    String actual[] = {"d","b","c","a"};
    isort(actual, 4, sizeof(String), compareString);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}