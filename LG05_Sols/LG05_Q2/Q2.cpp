#define _CRT_SECURE_NO_WARNINGS
#define BASE_PAYMENT 100.00
#define DISTRUBITION_CHARGE_PERCENTAGE .35
#define ADDITIONAL_KWH_PERCENTAGE .45

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	int electricityUsageInKwh;
	double electricityCharge = 0, distributionCost, totalBill;

	// Get input from the user
	printf("Enter the electricity usage (in kWh): ");
	scanf("%d", &electricityUsageInKwh);

	// Make calculations
	if (electricityUsageInKwh > 1500)
		electricityCharge = BASE_PAYMENT + ADDITIONAL_KWH_PERCENTAGE * (electricityUsageInKwh - 1500);
	else if (electricityUsageInKwh > 0 && electricityUsageInKwh <= 1500)
		electricityCharge = BASE_PAYMENT;

	distributionCost = electricityCharge * DISTRUBITION_CHARGE_PERCENTAGE;
	totalBill = electricityCharge + distributionCost;

	// Show the result
	printf("\nElectricity Charge: %.2f TL", electricityCharge);
	printf("\nDistribution Cost: %.2f TL", distributionCost);
	printf("\nTotal bill is %.2f TL", totalBill);

	return 0;
}