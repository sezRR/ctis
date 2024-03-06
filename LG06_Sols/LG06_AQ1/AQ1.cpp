#define _CRT_SECURE_NO_WARNINGS

#define DOMESTIC_FLIGHT_PRICE 1099.99
#define EXTRA_BAGGAGE_PRICE 45.00
#define EXTRA_BAGGAGE_LIMIT 15

#define DISCOUNT_RATE_DISABLED_PASSENGERS 0.4
#define DISCOUNT_RATE_OVER_65_AGED_PASSENGERS 0.15
#define DISCOUNT_RATE_0_TO_12_AGED_PASSENGERS 0.33

#include <stdio.h>

int main(void)
{
	// Define variables
	int age;
	char disabilityStatus;
	double ticketPayment = DOMESTIC_FLIGHT_PRICE, baggageWeight = 0, discountRate = 0;

	// Get inputs from the user
	printf("Enter your age: ");
	scanf("%d", &age);

	if (age > 65)
	{
		discountRate += DISCOUNT_RATE_OVER_65_AGED_PASSENGERS;
	}
	else if (age >= 0 && age <= 12)
	{
		discountRate += DISCOUNT_RATE_0_TO_12_AGED_PASSENGERS;
	}
	else if (age < 0) {
		return 1;
	}

	printf("Disability ? (y/n): ");
	scanf(" %c", &disabilityStatus);

	if (disabilityStatus == 'y')
	{
		discountRate += DISCOUNT_RATE_DISABLED_PASSENGERS;
	}
	else if (disabilityStatus != 'n')
	{
		return 1;
	}

	ticketPayment *= (1 - discountRate);
	printf("Ticket payment: %.2f TL", ticketPayment);

	printf("\nEnter baggage weight: ");
	scanf("%lf", &baggageWeight);

	if (baggageWeight > EXTRA_BAGGAGE_LIMIT)
	{
		double excedeedBaggageKg = baggageWeight - EXTRA_BAGGAGE_LIMIT;
		printf("Your baggage weight exceeds the limit with %.2f kg, please pay %.2f TL", excedeedBaggageKg, EXTRA_BAGGAGE_PRICE * excedeedBaggageKg);
	}

	return (0);
}