#define _CRT_SECURE_NO_WARNINGS
#define ONE_SQUARE_METER_OF_THE_CARPET 50
#define CARPET_SELLER_EXTRA 250

#include <stdio.h>

int main(void)
{
	// Declare variables
	double firstSideOfLivingRoomAsAMeter, 
		secondSideOfLivingRoomAsAMeter,
		areaOfTheLivingRoom,
		totalPriceToBePaid;

	// Get inputs from the user
	printf("Enter first side of living room: ");
	scanf("%lf", &firstSideOfLivingRoomAsAMeter);
	
	printf("Enter first side of living room: ");
	scanf("%lf", &secondSideOfLivingRoomAsAMeter);

	// Make calculations
	areaOfTheLivingRoom = firstSideOfLivingRoomAsAMeter * secondSideOfLivingRoomAsAMeter;
	totalPriceToBePaid = (areaOfTheLivingRoom * ONE_SQUARE_METER_OF_THE_CARPET) + CARPET_SELLER_EXTRA;

	// Show the results
	printf("\nThe area of the living room is %.2f square meters.", areaOfTheLivingRoom);
	printf("\nThe total price to be paid is %.2f TL", totalPriceToBePaid);
}