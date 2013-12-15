#include "testUtils.h"
#include "insertion-sort.h"
#include <stdio.h>

typedef struct {
	int accountNumber;
	int balance;
} Account;

int compareAccountsByAccountNumber(void* first, void* second);
int compareAccountsByBalance(void* first, void* second);

int main() {
	Account accounts[] = {{100, 100}, {12, 10}, {33, 10000}, {40, 3}};
	isort(accounts, 4, sizeof(Account), compareAccountsByAccountNumber);
	printf("Sorted values: %d %d %d %d\n", 
				accounts[0].accountNumber,
				accounts[1].accountNumber,
				accounts[2].accountNumber,
				accounts[3].accountNumber);
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