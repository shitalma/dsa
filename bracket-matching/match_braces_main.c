#include "match_braces.c"
#include <stdio.h>
int main(int argc, char  *argv[]){
    char* input = argv[1];
    if(breakMatch(input))
    	printf("All braces are matched");
    else
    	printf("Braces are not matched");
    return 0;
}