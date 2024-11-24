#define _CRT_SECURE_NO_WARNINGS

#define DOLLAR_SYMBOL "D"
#define EURO_SYMBOL "E"

#include <stdio.h>
#include <string.h>

typedef struct {
	char country[5];
	double dolarUnit;
	double euroUnit;
} curr_t;

char toUpper(char* c) {
	if (c[0] >= 'a' && c[0] <= 'z')
		return c[0] - ('a' - 'A');
}

double calcPrice(curr_t* currencies, int arrSize, char* countryAbbr, int moneyAmount, char* currencyChar) {
	curr_t curr = {"", 0, 0};
	for (int i = 0; i < arrSize; i++)
		if (strcmp(currencies[i].country, countryAbbr) == 0)
			curr = currencies[i];

	// NOT FOUND
	if (curr.dolarUnit == 0)
		return -1;

	switch (currencyChar[0])
	{
	case 'D':
		strcpy(currencyChar, "dollar");
		return moneyAmount * curr.dolarUnit;
	case 'E':
		strcpy(currencyChar, "euro");
		return moneyAmount * curr.euroUnit;
	default:
		return -1;
	}
}

int main(void) {
	FILE* binFile = fopen("currency.bin", "rb");
	if (binFile == NULL)
		printf("File could not be opened!");
	else {
		curr_t currencies[50];
		int i = 0;

		while (!feof(binFile))
			fread(&currencies[i++], sizeof(curr_t), 1, binFile);

		char countryAbbr[50] = "", currencyChar[50] = "";
		int moneyAmount;

		printf("Enter Country Abbreviation: ");
		scanf("%s", countryAbbr);

		printf("Enter money amount: ");
		scanf("%d", &moneyAmount);

		printf("Dollar / Euro (D:E): ");
		scanf("%s", &currencyChar);

		currencyChar[0] = toUpper(currencyChar);

		if (strcmp(currencyChar, "D") != 0 && strcmp(currencyChar, "E") != 0)
			printf("Invalid Currency!");

		double res = calcPrice(currencies, i, countryAbbr, moneyAmount, currencyChar);

		if (res == -1)
			printf("NO PAYMENT");
		else
			printf("You have %.2f %s", res, currencyChar);

		fclose(binFile);
	}

	return 0;
}