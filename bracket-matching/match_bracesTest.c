#include "testUtils.h"
#include <string.h>
#include <stdio.h>
#include "match_braces.h"
#include "stack.h"

void test_bracket_match(){
	String actual = "{[()]}";
	ASSERT(1 == doBracketsMatch(actual));
}

void test_2_bracket_match(){
	String actual = "{[(()]}";
	ASSERT(0 == doBracketsMatch(actual));
}

void test_3_bracket_match(){
	String actual = ")";
	ASSERT(0 == doBracketsMatch(actual));
}
void test_4_bracket_match(){
	String actual = "){{{[]]";
	ASSERT(0 == doBracketsMatch(actual));
}
void test_5_bracket_match(){
	String actual = "{[(shital)]}";
	ASSERT(1 == doBracketsMatch(actual));
}
void test_6_bracket_match(){
	String actual = "{[(shital)])}";
	ASSERT(0 == doBracketsMatch(actual));
}
void test_7_bracket_match(){
	String actual = "";
	ASSERT(1 == doBracketsMatch(actual));
}
void test_8_bracket_match(){
	String actual = ")(";
	ASSERT(0 == doBracketsMatch(actual));
}
void test_9_bracket_match(){
	String actual = "{}()[]";
	ASSERT(1 == doBracketsMatch(actual));
}
void test_10_bracket_match(){
	String actual = "{()}[]";
	ASSERT(1 == doBracketsMatch(actual));
}
