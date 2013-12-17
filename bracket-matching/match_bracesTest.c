#include "testUtils.h"
#include <string.h>
#include <stdio.h>
#include "match_braces.h"
#include "stack.h"

void test_bracket_match(){
	String actual;
	strcpy(actual,"{[()]}");
	ASSERT(1==doBracketsMatch(actual));
}

void test_2_bracket_match(){
	String actual;
	strcpy(actual,"{[(()]}");
	ASSERT(0==doBracketsMatch(actual));
}

void test_3_bracket_match(){
	String actual;
	strcpy(actual,")");
	ASSERT(0==doBracketsMatch(actual));
}
void test_4_bracket_match(){
	String actual;
	strcpy(actual,"){{{[]]");
	ASSERT(0==doBracketsMatch(actual));
}
void test_5_bracket_match(){
	String actual;
	strcpy(actual,"{[(shital)]}");
	ASSERT(1 == doBracketsMatch(actual));
}
void test_6_bracket_match(){
	String actual;
	strcpy(actual,"{[(shital)mane])}");
	ASSERT(0==doBracketsMatch(actual));
}
