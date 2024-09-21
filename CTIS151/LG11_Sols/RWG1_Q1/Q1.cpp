#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int subtraction(int num1, int num2)
{
	int result = 0;
	while (num2 >= num1)
	{
		result = num2 - num1;
		num2 = result;
	}

	printf("%d < %d -> Result of the Operation : %d\n\n", num1, num2, result);
	return result;
}

int summation(int num1, int num2)
{
	int result = 0;
	for (int i = 0; i < num1; i++)
	{
		result += num2;
	}

	printf("%d > %d -> Result of the Operation : %d\n\n", num1, num2, result);
	return result;
}

int main(void)
{
	// Define variables
	int num1, num2, result;

	while (1)
	{
		// Get inputs from the user
		printf("Enter the num1 and num2: ");
		scanf("%d %d", &num1, &num2);

		if (num1 == num2) {
			printf("Goodbyee :)");
			break;
		}

		if (num1 > num2)
			result = summation(num1, num2);
		else if (num2 > num1)
			result = subtraction(num1, num2);
	}

	return 0;
}