#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LEN 30

#include <stdio.h>

int dispMenu() {
	int choice;

	printf("%15cMENU\n", ' ');
	printf("-------------------------------------\n");
	printf("1- List the accounts with zero balances\n");
	printf("2- Display the account which has the maximum balance\n");
	printf("3- Exit\n");

	do
	{
		printf("Enter your request: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 3);

	return choice;
}

int readFile(FILE* file, int c_ids[], double c_balances[]) {
	int lenArr = 0;

	while (fscanf(file, "%d %lf", &c_ids[lenArr], &c_balances[lenArr]) != EOF)
		lenArr++;

	return lenArr;
}

void displayZeroBalances(int c_ids[], double c_balances[], int lenArr) {
	printf("\nAccounts with zero balances:\n");
	for (int i = 0; i < lenArr; i++)
		if (c_balances[i] == 0)
			printf("%d\n", c_ids[i]);
}

int findMaxBalance(double c_balances[], int arrLen) {
	int maxBalanceIndex = 0;

	for (int i = 1; i < arrLen; i++)
		if (c_balances[maxBalanceIndex] < c_balances[i])
			maxBalanceIndex = i;

	return maxBalanceIndex;
}

int main(void) {
	FILE* customersFile = fopen("customers.txt", "r");
	int c_ids[MAX_ARR_LEN], menu_choice, customer_count;
	double c_balances[MAX_ARR_LEN];

	if (customersFile == NULL)
		printf("File could not be read!");
	else {
		while (true)
		{
			menu_choice = dispMenu();

			if (menu_choice == 3)
				break;

			customer_count = readFile(customersFile, c_ids, c_balances);

			switch (menu_choice)
			{
			case 1:
				displayZeroBalances(c_ids, c_balances, customer_count);
				break;
			case 2:
				int indexOfMaxBalance = findMaxBalance(c_balances, customer_count);
				printf("\nAccount Info which has the maximum balance:\n");
				printf("%d\t%.2f\n\n", c_ids[indexOfMaxBalance], c_balances[indexOfMaxBalance]);
			}
		}
	}

	return 0;
}