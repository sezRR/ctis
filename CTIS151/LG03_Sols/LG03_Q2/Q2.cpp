#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	int distanceBetweenCities, speed, resultInHours;

	// Get inputs from the user
	printf("Enter the km distance between first city and second city: ");
	scanf("%d", &distanceBetweenCities);

	printf("Enter your speed: ");
	scanf("%d", &speed);

	// Make calculations
	resultInHours = distanceBetweenCities / speed;

	// Show the result
	printf("You can reach %d hours totally", resultInHours);
}