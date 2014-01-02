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

	testStarted("test_insert_in_binary_tree");
	setup();
		test_insert_in_binary_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_in_binary_tree_value_greater_than_root_should_insert_on_right");
	setup();
		test_insert_in_binary_tree_value_greater_than_root_should_insert_on_right();
	tearDown();
	testEnded();
	testStarted("test_insert_in_binary_tree_value_lesser_than_root_should_insert_on_left");
	setup();
		test_insert_in_binary_tree_value_lesser_than_root_should_insert_on_left();
	tearDown();
	testEnded();
	testStarted("test_get_children_of_root");
	setup();
		test_get_children_of_root();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
