#define _CRT_SECURE_NO_WARNINGS
#define PI 3.1415

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	double diameterOfConeInCm, heightOfConeInM, slantHeightOfCone, surfaceAreaOfCone, volumeOfCone, radiusOfConeInCm;

	// Get inputs from the user
	printf("Enter the diameter of the cone (in cm): "); 
	scanf_s("%lf", &diameterOfConeInCm);

	printf("Enter the height of the cone (in m): "); 
	scanf_s("%lf", &heightOfConeInM);

	// Make calculations
	radiusOfConeInCm = diameterOfConeInCm / 2;
	
	slantHeightOfCone = sqrtf(pow(heightOfConeInM, 2) + pow(radiusOfConeInCm / 100, 2));
	surfaceAreaOfCone = PI * pow(radiusOfConeInCm / 100, 2) + PI * radiusOfConeInCm / 100 * slantHeightOfCone;
	volumeOfCone = 1.0 / 3 * PI * pow(radiusOfConeInCm, 2) * heightOfConeInM * 100;

	// Show the results
	printf("\nThe slant height of the cone is %.1f m", slantHeightOfCone);
	printf("\nThe surface area of the cone is %.3f m2", surfaceAreaOfCone);
	printf("\nThe volume of the cone is %.2f cm3", volumeOfCone);
}