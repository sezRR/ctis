#define _CRT_SECURE_NO_WARNINGS
#define ANNUAL_SALES_LOSS .04
#define ANNUAL_PROFIT .1

#include <stdio.h>

int main(void)
{
	// Declare variables
	int numberOfYears;
	double salesOfFirm, profitOfFirm, totalSales = 0, totalProfit = 0;

	// Get inputs
	printf("Enter the sales of the firm: ");
	scanf("%lf", &salesOfFirm);

	profitOfFirm = salesOfFirm;

	printf("Enter the number of years:");
	scanf("%d", &numberOfYears);

	printf("\nYEAR%9cSALES%15cPROFIT", ' ', ' ');
	printf("\n-----------------------------------------");
	for (int i = 1; i <= numberOfYears; i++)
	{
		printf("\n%3d", i);
		printf("%7c", ' ');

		salesOfFirm = salesOfFirm - salesOfFirm * ANNUAL_SALES_LOSS;
		profitOfFirm = salesOfFirm * ANNUAL_PROFIT;

		totalSales += salesOfFirm;
		totalProfit += profitOfFirm;

		printf("%.2f", salesOfFirm);
		printf("%12c", ' ');

		printf("%.2f", profitOfFirm);
	}
	printf("\n-----------------------------------------");
	printf("\nTOTAL");
	printf("%3c", ' ');
	printf("%9.2f", totalSales);
	printf("%12c", ' ');
	printf("%9.2f", totalProfit);

	return 0;
}