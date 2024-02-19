/* Purpose to find the age of user */

#define _CRT_SECURE_NO_WARNINGS
#define CURRENTYEAR 2024

#include <stdio.h>

int main(void)
{
	// Declare variables
	int age, birthYear;

	// Get the age from user as a input
	printf("Enter your birth year: ");
	scanf("%d", &birthYear);

	// Calculate the age
	age = CURRENTYEAR - birthYear;

	// Print the age of user
	printf("Nice age: %d", age);

	return(0);
}