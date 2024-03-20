#define _CRT_SECURE_NO_WARNINGS

#define RESIDENTAL_INITIAL_PRICE 6
#define RESIDENTAL_PLUS_PER_KWH_USED 0.052

#define COMMERCIAL_INITIAL_PRICE_FIRST_1000KWH 60
#define COMMERCIAL_PLUS_PER_KWH_USED_AFTER_1000_KWH 0.045

#define INDUSTRIAL_PEAK_HOURS_INITIAL_PRICE_FIRST_1000KW 76
#define INDUSTRIAL_PEAK_HOURS_PLUS_PER_KWH_USED_AFTER_1000_KWH 0.065

#define INDUSTRIAL_OFF_PEAK_HOURS_INITIAL_PRICE_FIRST_1000KW 40
#define INDUSTRIAL_OFF_PEAK_HOURS_PLUS_PER_KWH_USED_AFTER_1000_KWH 0.028

#include <stdio.h>

int main(void)
{
	// Define variables
	int numberOfCustomers, kwh, peakKwh;
	char customerUsageType, isCustomerUsageTypeValid = 0;
	double bill = 0;

	int residentalCustomerCounter = 0,
		commercialCustomerCounter = 0,
		industrialCustomerCounter = 0;

	double sumBillResidentalCustomer = 0,
		sumBillCommercialCustomer = 0,
		sumBillIndustrialCustomer = 0;

	// Get inputs from the user
	printf("Please enter the number of customers: ");
	scanf("%d", &numberOfCustomers);

	for (int i = 0; i < numberOfCustomers; i++)
	{
		do
		{
			printf("\nEnter the usage type(R/r-Residental, C/c-Commercial, I/i-Industrial): ");
			scanf(" %c", &customerUsageType);

			if (customerUsageType != 'R' &&
				customerUsageType != 'r' &&
				customerUsageType != 'C' &&
				customerUsageType != 'c' &&
				customerUsageType != 'I' &&
				customerUsageType != 'i')
			{
				isCustomerUsageTypeValid = 0;
				printf("!Invalid type!n");
			}
			else {
				isCustomerUsageTypeValid = 1;
			}
		} while (!isCustomerUsageTypeValid);

		// Make calculations
		switch (customerUsageType)
		{
		case 'R':
		case 'r':
			// Get kwh input from the user for each customer
			printf("Enter the kwh: ");
			scanf("%d", &kwh); 

			if (kwh != 0)
			{
				bill += RESIDENTAL_INITIAL_PRICE + kwh * RESIDENTAL_PLUS_PER_KWH_USED;
			}
			
			residentalCustomerCounter++;
			sumBillResidentalCustomer += bill;
			break;
		case 'C':
		case 'c':
			// Get kwh input from the user for each customer
			printf("Enter the kwh: ");
			scanf("%d", &kwh); 

			if (kwh != 0)
			{
				bill += COMMERCIAL_INITIAL_PRICE_FIRST_1000KWH;

				if (kwh > 1000)
					bill += (kwh - 1000) * COMMERCIAL_PLUS_PER_KWH_USED_AFTER_1000_KWH;
			}

			commercialCustomerCounter++;
			sumBillCommercialCustomer += bill;
			break;
		case 'I':
		case 'i':
			// Get kwh inputs from the user for each customer
			printf("Please enter the kwh for PEAK hours: ");
			scanf("%d", &peakKwh);

			if (peakKwh != 0)
			{
				bill += INDUSTRIAL_PEAK_HOURS_INITIAL_PRICE_FIRST_1000KW;

				if (peakKwh > 1000)
					bill += (peakKwh - 1000) * INDUSTRIAL_PEAK_HOURS_PLUS_PER_KWH_USED_AFTER_1000_KWH;
			}

			printf("Please enter the kwh for OFFPEAK hours: ");
			scanf("%d", &kwh);

			if (kwh != 0)
			{
				bill += INDUSTRIAL_OFF_PEAK_HOURS_INITIAL_PRICE_FIRST_1000KW;

				if (kwh > 1000)
					bill += (kwh - 1000) * INDUSTRIAL_OFF_PEAK_HOURS_PLUS_PER_KWH_USED_AFTER_1000_KWH;
			}

			industrialCustomerCounter++;
			sumBillIndustrialCustomer += bill;
		}

		printf("Please pay %.2f TL\n", bill);
		bill = 0;
	}

	printf("\n\nThe average price of the residental usage is: %.2f TL", sumBillResidentalCustomer / residentalCustomerCounter);
	printf("\nThe average price of the commercial usage is: %.2f TL", sumBillCommercialCustomer / commercialCustomerCounter);
	printf("\nThe average price of the industrial usage is: %.2f TL", sumBillIndustrialCustomer / industrialCustomerCounter);

	return 0;
}