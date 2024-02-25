#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SPECIFIC_HEAT 703

int main(void)
{
	// Declare variables
	int currentTemperature, desiredTemperature;
	double thermalEnergy, mass;

	// Get current temperature from the user
	printf("Please enter the current tempeature in Celcius: ");
	scanf("%d", &currentTemperature);
	
	printf("Please enter the desired temperature in Celcius: ");
	scanf("%d", &desiredTemperature);

	// Get the mass from the user
	printf("Please enter the mass in Kilograms: ");
	scanf("%lf", &mass);

	// Calculate thermal energy
	thermalEnergy = mass * SPECIFIC_HEAT * (desiredTemperature - currentTemperature);

	// Output results
	printf("The energy needed to raise the temperature of a %f kg object %d degress is %f J", mass, desiredTemperature - currentTemperature, thermalEnergy);

	return 0;
}