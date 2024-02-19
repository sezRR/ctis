/* Purpose to find the volume of a Ellipsoid get the one side
   value and height from the user */

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14

#include <stdio.h>

int main(void)
{
	// Declaring variables
	double a, b, c;

	// Get input valeu for one axis of the ellipsoid from the user
	printf("Enter first axis (a) of the Ellipsoid : ");
	scanf("%lf", &a);

	// Get input valeu for one axis of the ellipsoid from the user
	printf("Enter first axis (b) of the Ellipsoid : ");
	scanf("%lf", &b);

	// Get input valeu for one axis of the ellipsoid from the user
	printf("Enter first axis (c) of the Ellipsoid : ");
	scanf("%lf", &c);

	// Calculate the volume of ellipsoid
	double volumeOfEllipsoid = (4.0 / 3) * PI * a * b * c;

	// Print the result
	printf("The Volume of Ellipsoid is: %lf", volumeOfEllipsoid);

	return(0);
}