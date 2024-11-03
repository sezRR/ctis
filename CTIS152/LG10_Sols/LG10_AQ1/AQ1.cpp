#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[75];
	char shoppingDate[50];
	char store[50];
} customer_t;

int main(void) {
	FILE* file = fopen("customers.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		customer_t customers[50]{};
		int countCustomer = 0;
		while (fscanf(file, "%[^-]--%[^-]--%[^\n]\n",
			customers[countCustomer].name,
			customers[countCustomer].shoppingDate,
			customers[countCustomer].store) != EOF)
			countCustomer++;

		printf("AWARD WINNING CUSTOMERS\n");
		printf("----------------------------------------\n");
		for (int i = 0; i < countCustomer; i++)
		{
			char tempDate[100] = "", tempName[100] = "";
			strncpy(tempDate, customers[i].shoppingDate, 5);

			int firstSpace = -1;
			for (int j = 0; j < strlen(customers[i].name); j++)
				if (customers[i].name[j] == ' ')
				{
					firstSpace = j;
					break;
				}

			strncpy(tempName, customers[i].name, 1);
			strcat(tempName, ".");
			strncat(tempName, customers[i].name + firstSpace + 1, strlen(customers[i].name) - firstSpace - 1);
			printf("%-5s %-15s %-12s\n", tempDate, tempName, customers[i].store);
		}

		fclose(file);
	}

	return 0;
}