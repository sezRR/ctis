#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LENGTH 20

#include <stdio.h>

int menu()
{
	int userChoice;

	printf("MENU\n");
	printf("1. List Stock Info\n");
	printf("2. Buy a product\n");
	printf("3. Exit\n");

	do
	{
		printf("Enter choice: ");
		scanf("%d", &userChoice);
	} while (userChoice < 1 || userChoice > 3);

	return userChoice;
}

int readFile(FILE* file, int arr[][MAX_ARR_LENGTH])
{
	int row = 0;
	while (fscanf(file, "%d %d %d", &arr[row][0], &arr[row][1], &arr[row][2]) != EOF)
		row++;

	return row;
}

void listStockInfo(int arr[][MAX_ARR_LENGTH], int maxRow, int maxColumn)
{
	printf("\n%3c ID Price Stock\n", ' ');
	printf("------ ----- -----\n");
	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxColumn; j++)
			printf("%6d", arr[i][j]);

		printf("\n");
	}

	printf("\n");
}

int searchProd(int arr[][MAX_ARR_LENGTH], int productId, int maxRow)
{
	for (int i = 0; i < maxRow; i++)
	{
		if (arr[i][0] == productId)
			return i;
	}

	return -1;
}

void buyProd(int arr[][MAX_ARR_LENGTH], FILE* file, int* sumOfPayment, int quantity, int productIdIndex)
{
	arr[productIdIndex][2] = arr[productIdIndex][2] - quantity;

	int payment = quantity * arr[productIdIndex][1];
	fprintf(file, "%6d", arr[productIdIndex][0]);					 // ID
	fprintf(file, "%6d", arr[productIdIndex][1]);					 // PRICE
	fprintf(file, "%9d", quantity);									 // QUANTITY
	fprintf(file, "%8d", payment);									 // PAYMENT
	fprintf(file, "\n");

	*sumOfPayment += payment;
}

int main(void)
{
	FILE* companiesFile = fopen("company.txt", "r");
	FILE* shoppingFile = fopen("shopping.txt", "w");

	if (companiesFile == NULL)
		printf("Companies file could not be opened!");
	else if (shoppingFile == NULL)
		printf("Shopping file could not be opened!");
	else 
	{
		int companies[MAX_ARR_LENGTH][MAX_ARR_LENGTH];
		int lengthOfRow = readFile(companiesFile, companies);
		fclose(companiesFile);

		// INIT SHOPPING FILE HEADERs
		fprintf(shoppingFile, "ID     PRICE QUANTITY PAYMENT\n");
		fprintf(shoppingFile, "------ ----- -------- -------\n");

		int userChoice, sumOfPayment = 0;
		do
		{
			switch (userChoice = menu())
			{
			case 1:
				listStockInfo(companies, lengthOfRow, 3);
				break;
			case 2:
				printf("\nEnter the product id: ");

				int productId, searchResultProductIdIndex;
				do
				{
					scanf("%d", &productId);
					
					searchResultProductIdIndex = searchProd(companies, productId, lengthOfRow);
					if (searchResultProductIdIndex == -1)
					{
						printf("\nWrong product number\n");
						printf("Re-Enter the product id: ");
					}
				} while (searchResultProductIdIndex == -1);

				int quantityOfProduct = companies[searchResultProductIdIndex][2];

				if (quantityOfProduct == 0)
					printf("SORRY! The product is out of stock\n\n");
				else 
				{
					int quantityToBuy;
					printf("Enter the quantity: ");
					do
					{
						scanf("%d", &quantityToBuy);

						if (quantityOfProduct < quantityToBuy)
							printf("\nThere are %d products in the stock\n", quantityOfProduct);
						else if (quantityToBuy <= 0)
						{
							printf("\nYou cannot enter 0 or negative value to buy!\n");
						}
						else
							break;

						printf("Re-Enter the product id: ");
					} while (quantityToBuy <= 0 || quantityOfProduct < quantityToBuy);

					buyProd(companies, shoppingFile, &sumOfPayment, quantityToBuy, searchResultProductIdIndex);
					printf("\n");
				}
			}
		} while (userChoice != 3);

		fprintf(shoppingFile, "\nTotal payment of the customet is: %d TL", sumOfPayment);
		fclose(shoppingFile);

		listStockInfo(companies, lengthOfRow, 3);
	}

	return 0;
}