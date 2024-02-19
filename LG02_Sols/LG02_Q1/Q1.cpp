/* Purpose to find the area of a Rhombus get the one side
   value and height from the user */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	//Declaring variables
	double side, area, height;

	side = 2;
	height = 4;

	//Calculating area
	area = side * height;

	//Display area
	printf("Area of Rhombus is : %f\n", area);

	//Get input valeu for one side of the rhombus from the user
	printf("Enter one side of the Rhombus : ");
	scanf("%lf", &side);

	//Get input value for height from the user
	printf("Enter height of the Rhombus : ");
	scanf("%lf", &height);

	//Calculating area
	area = side * height;

	//Display area
	printf("Area of Rhombus is : %f\n", area);

	return(0);
}