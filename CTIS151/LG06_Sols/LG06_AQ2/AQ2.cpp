#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Define variables
	char logicalOperator;
	int a, b;

	// Get inputs from the user
	printf("Enter the logical operator: ");
	scanf("%c", &logicalOperator);

	printf("Enter the value of A: ");
	scanf("%d", &a);

	printf("Enter the value of B: ");
	scanf("%d", &b);

	switch (logicalOperator)
	{
	case '&':
		printf("The truth value of the operation is: %d", a & b);
		break;
	case 'V':
		printf("The truth value of the operation is: %d", a | b);
		break;
	case 'X':
		printf("The truth value of the operation is: %d", a ^ b);
		break;
	default:
		printf("Invalid Character");
		break;
	}

	return 0;
}