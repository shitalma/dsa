#include "match_braces.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
int isMatch(stack* Stack,char input){
    char res = (*(char*)top(Stack));
    if((res=='(' && input==')') 
        || (res=='[' && input==']') 
        || (res=='{' && input=='}'))
        return 1;
    return 0;       
}
int doBracketsMatch(String str){
    stack* Stack;
    int counter;
    Stack = create(sizeof(char),strlen(str));
    for(counter = 0;counter<strlen(str);counter++){
        if(str[counter]=='(' || str[counter]=='[' || str[counter]=='{')
            push(Stack,&str[counter]);
        if(str[counter]==')' || str[counter]==']' || str[counter]=='}'){
            if(!isMatch(Stack,str[counter]))
                return 0;
            pop(Stack);
        }
    }
    return 1;
}
