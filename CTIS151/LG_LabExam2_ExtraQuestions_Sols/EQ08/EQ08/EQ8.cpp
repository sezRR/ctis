#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char menu()
{
	char userChoice;

	printf("%16cMENU%16c\n", ' ', ' ');
	printf("*************************************\n");
	printf("A. Add fractional parts of two numbers\n");
	printf("B. Convert a double number to decimal\n");
	printf("C. QUIT\n");

	do
	{
		printf("Enter your choice: ");
		scanf(" %c", &userChoice);
	} while (userChoice > 'C' || userChoice < 'A');

	return userChoice;
}

double fracPart(double number)
{
	int integerNumber = number;
	return number - integerNumber;
}

int roundNum(double number)
{
	if (fracPart(number) >= .5)
		return number + 1;
	else
		return number;
}

int main(void)
{
	while (1)
	{
		switch (menu())
		{
		case 'A':
			double number1, number2;
			printf("Enter two double numbers: ");
			scanf("%lf %lf", &number1, &number2);

			number1 = fracPart(number1);
			number2 = fracPart(number2);
			printf("%.4f + %.4f = %.4f\n\n", number1, number2, number1 + number2);
			break;
		case 'B':
			printf("Enter a double number: ");

			double number;
			scanf("%lf", &number);
			printf("The number %.4f converted to the decimal number %d\n\n", number, roundNum(number));
			break;
		default:
			return 0;
		}
	}

	return 0;
}