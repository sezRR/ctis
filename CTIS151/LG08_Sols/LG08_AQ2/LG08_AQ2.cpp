#define _CRT_SECURE_NO_WARNINGS

#define FIRST_RATE_CAR 0
#define FIRST_RATE_TRUCK 1.3
#define FIRST_RATE_BUS 2.5

#define FIRST_RATE_DURATION_CAR 2
#define FIRST_RATE_DURATION_TRUCK 3
#define FIRST_RATE_DURATION_BUS 1

#define SECOND_RATE_AFTER_FIRST_DURATION_CAR 2.5
#define SECOND_RATE_AFTER_FIRST_DURATION_TRUCK 2.7
#define SECOND_RATE_AFTER_FIRST_DURATION_BUS 3.5

#include <stdio.h>
#include "LG08_AQ2.h"

int main(void)
{
	// Declare variables
	int vehicleType = 0,
		vehicleHourDuration = 0,
		vehicleCounter = 0;

	double bill = 0,
		income = 0;

	// Show the menu and get the choose from the user
	while (1)
	{
		getVehicleTypeInputWithShowingMenu(&vehicleType);

		if (vehicleType > 4 || vehicleType < 1)
		{
			printf("Wrong Choice!\n\n");
			continue;
		}

		if (vehicleType == 4)
			break;

		getDurationInput(&vehicleHourDuration);

		vehicleCounter++;
		printf("The bill is $%.2f\n\n", calculateBill(vehicleType, vehicleHourDuration, bill, income));
		bill = 0;
	}

	printf("\nToday %d vehicle parked and the income from the vehicles is %.3f", vehicleCounter, income);
	return 0;
}

void showMenu()
{
	printf("MENU\n");
	printf("----\n");
	printf("1) Car\n");
	printf("2) Truck\n");
	printf("3) Bus\n");
	printf("4) Exit\n");
}

int getVehicleTypeInputWithShowingMenu(int* vehicleType)
{
	showMenu();
	printf("Enter the vehicle type: ");
	scanf("%d", vehicleType);

	return *vehicleType;
}

int getDurationInput(int* durationInput)
{
	printf("Enter the duration: ");
	scanf("%d", durationInput);

	return *durationInput;
}

double calculateBill(int vehicleType, int vehicleHourDuration, double& bill, double& income)
{
	switch (vehicleType)
	{
	case 1:
		if (vehicleHourDuration > FIRST_RATE_DURATION_CAR) {
			bill = (vehicleHourDuration - FIRST_RATE_DURATION_CAR) * SECOND_RATE_AFTER_FIRST_DURATION_CAR;
			income += bill;
		}
		break;

	case 2:
		bill += FIRST_RATE_TRUCK;

		if (vehicleHourDuration > FIRST_RATE_DURATION_TRUCK)
			bill += (vehicleHourDuration - FIRST_RATE_DURATION_TRUCK) * SECOND_RATE_AFTER_FIRST_DURATION_TRUCK;

		income += bill;
		break;

	case 3:
		bill += FIRST_RATE_BUS;

		if (vehicleHourDuration > FIRST_RATE_DURATION_BUS)
			bill += (vehicleHourDuration - FIRST_RATE_DURATION_BUS) * SECOND_RATE_AFTER_FIRST_DURATION_BUS;

		income += bill;
	}

	return bill;
}
