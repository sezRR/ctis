#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char productName[50];
	double price;
	int discountRate;
} product_t;

int main(void) {
	FILE* amazonFile = fopen("amazon.txt", "r");
	product_t* product;
	int productCount = 0;

	if (amazonFile == NULL)
		printf("File could not be opened!");
	else {
		fscanf(amazonFile, "%d", &productCount);

		product = (product_t*)malloc(productCount * sizeof(product_t));

		for (int i = 0; i < productCount; i++)
			fscanf(amazonFile, "%s %lf %d", (product + i)->productName, &(product + i)->price, &(product + i)->discountRate);

		printf("There are %d products in the market\n\n", productCount);

		printf("PRODUCT NAME\tPRICE\t\tDISCOUNT\tDISC. PRICE\tSAVED AMOUNT\n");
		printf("************\t*********\t********\t***********\t************\n");
		for (int i = 0; i < productCount; i++)
		{
			double discountedPrice = (product + i)->price * ((100 - (product + i)->discountRate) / 100.0);
			printf("%s \t%.2f $ \t %%%d\t\t%1.2f $\t\t%1.2f $\n", (product + i)->productName, (product + i)->price, (product + i)->discountRate, discountedPrice, (product + i)->price - discountedPrice);
		}

		free(product);
		fclose(amazonFile);
	}

	return 0;
}