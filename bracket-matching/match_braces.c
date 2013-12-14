# include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "match_braces.h"
#include "../stack/stack.h"
bool compare(char value,stack* stack){
    void* current = peek(stack);
    if(NULL == current || (value != *(char*)current)) return false;
    pop(stack);
    return true;
}
bool breakMatch(String str){
    stack* stack;
    const char* input = str;
    int i,limit;
    char value;
    stack = create(500,sizeof(char));
    for(i=0;i< strlen(input);i++){
        if(input[i]=='{'|| input[i]=='[' || input[i]=='(')
                push(stack,(void*)&input[i]);
        if(input[i]=='}')
            if(!compare('{',stack))return false;
        if(input[i] == ']')
            if(!compare('[',stack))return false;
        if(input[i] == ')')
            if(!compare('(',stack))return false;
    }
    if(stack->top != 0)
        return false;
    return true;
}