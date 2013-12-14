#include "testUtils.h"
#include <stdio.h>
#include "match_braces.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_returns_false_if_string_not_matches(){
	String str = "([]";
	ASSERT(breakMatch(str) == false);
}

void test_2_returns_false_if_string_not_matches_if_have_1_closing_brace_extra(){
	String str = "[]]";
	ASSERT(breakMatch(str) == false);
}
void test_3_returns_false_if_string_not_matches_if_have_1_closing_brace_extra(){
	String str = "[]})";
	ASSERT(breakMatch(str) == false);
}

void test_4_returns_true_if_string_matches(){
	String str = "([])";
	ASSERT(breakMatch(str) == true);
}
void test_5_returns_true_if_string_matches(){
	String str = "{([])}";
	ASSERT(breakMatch(str) == true);
}