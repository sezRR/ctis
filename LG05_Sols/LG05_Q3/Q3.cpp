#define _CRT_SECURE_NO_WARNINGS
#define BUSINESS_WAGON_UNIT_PRICE 590
#define PULLMAN_WAGON_UNIT_PRICE 475
#define SLEEPER_COMPARTMENT_WAGON_UNIT_PRICE 3100

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	int numberOfPassengers;
	double totalFee = 0;
	char vagonType;

	// Get input from the user
	printf("Ticket point of sale:");
	printf("\nSelect wagon type(case sensitive):");
	printf("\nB or b: Business");
	printf("\nP or p: Pullman");
	printf("\nC or c: Compartment");

	printf("\nPlease enter wagon type: ");
	scanf("%c", &vagonType);

	if (vagonType == 'B' || vagonType == 'b') {
		printf("Please enter number of passengers: ");
		scanf("%d", &numberOfPassengers);

		totalFee = numberOfPassengers * BUSINESS_WAGON_UNIT_PRICE;
		printf("For %d passengers, the total fee %.2f for %c wagon.", numberOfPassengers, totalFee, vagonType);
	}
	else if (vagonType == 'P' || vagonType == 'p') {
		printf("Please enter number of passengers: ");
		scanf("%d", &numberOfPassengers);

		totalFee = numberOfPassengers * PULLMAN_WAGON_UNIT_PRICE;
		printf("For %d passengers, the total fee %.2f for %c wagon.", numberOfPassengers, totalFee, vagonType);
	}
	else if (vagonType == 'C' || vagonType == 'c')
	{
		printf("Please enter number of passengers: ");
		scanf("%d", &numberOfPassengers);

		totalFee = numberOfPassengers * SLEEPER_COMPARTMENT_WAGON_UNIT_PRICE;
		printf("For %d passengers, the total fee %.2f for %c wagon.", numberOfPassengers, totalFee, vagonType);
	}
	else {
		printf("Invalid wagon type. Please select B, P or C.");
	}


	return 0;
}