#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_gives_an_singly_link_list_with_head_NULL");
	setup();
		test_gives_an_singly_link_list_with_head_NULL();
	tearDown();
	testEnded();
	testStarted("test_inserts_an_element_as_the_head_of_linklist_for_integer");
	setup();
		test_inserts_an_element_as_the_head_of_linklist_for_integer();
	tearDown();
	testEnded();
	testStarted("test_inserts_elements_at_the_end_of_linkList_for_integer");
	setup();
		test_inserts_elements_at_the_end_of_linkList_for_integer();
	tearDown();
	testEnded();
	testStarted("test_inserts_elements_at_the_end_of_linkList_for_character");
	setup();
		test_inserts_elements_at_the_end_of_linkList_for_character();
	tearDown();
	testEnded();
	testStarted("test_inserts_elements_at_the_end_of_linkList_for_string");
	setup();
		test_inserts_elements_at_the_end_of_linkList_for_string();
	tearDown();
	testEnded();
	testStarted("test_deletes_last_element_in_the_linkList");
	setup();
		test_deletes_last_element_in_the_linkList();
	tearDown();
	testEnded();
	testStarted("test_deletes_last_element_in_the_linkList_for_character");
	setup();
		test_deletes_last_element_in_the_linkList_for_character();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
