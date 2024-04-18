#define _CRT_SECURE_NO_WARNINGS

#define MENU_CONSTANT_PRODUCTS_OF_DIGITS 'D'
#define MENU_CONSTANT_PRODUCTS_OF_DIGITS_SMALL_CAPS 'd'

#define MENU_CONSTANT_PRIME_NUMBER 'P'
#define MENU_CONSTANT_PRIME_NUMBER_SMALL_CAPS 'p'

#define MENU_CONSTANT_EXIT 'E'
#define MENU_CONSTANT_EXIT_SMALL_CAPS 'e'

#include <stdio.h>
#include <math.h>

int menu()
{
	char userChoice;

	printf("%9cMENU%13c\n", ' ', ' ');
	printf("**************************\n");
	printf("D) Products of the digits\n");
	printf("P) Prime number\n");
	printf("E) Exit\n");
	do
	{
		printf("Enter your choice: ");
		scanf(" %c", &userChoice);
	} while (userChoice != MENU_CONSTANT_PRODUCTS_OF_DIGITS
		&& userChoice != MENU_CONSTANT_PRODUCTS_OF_DIGITS_SMALL_CAPS
		&& userChoice != MENU_CONSTANT_PRIME_NUMBER
		&& userChoice != MENU_CONSTANT_PRIME_NUMBER_SMALL_CAPS
		&& userChoice != MENU_CONSTANT_EXIT
		&& userChoice != MENU_CONSTANT_EXIT_SMALL_CAPS);

	return userChoice;
}

int productOfDigits(int number)
{
	int result = 1;
	for (int i = 0; 1 < number; i++)
	{
		result *= number % 10;
		number /= 10;
	}

	return result;
}

bool isPrime(int number)
{
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
			return 0;
	}

	return 1;
}

int main(void)
{
	// Define variables
	char userChoice;
	int numberInput;

	while (1)
	{
		userChoice = menu();

		if (userChoice == MENU_CONSTANT_EXIT || userChoice == MENU_CONSTANT_EXIT_SMALL_CAPS) {
			printf("EXIT!");
			break;
		}
		
		switch (userChoice)
		{
		case MENU_CONSTANT_PRODUCTS_OF_DIGITS_SMALL_CAPS:
		case MENU_CONSTANT_PRODUCTS_OF_DIGITS:
			printf("Enter a number for product calculation: ");
			scanf("%d", &numberInput);

			printf("The product of the digits: %d\n", productOfDigits(numberInput));
			break;
		case MENU_CONSTANT_PRIME_NUMBER:
		case MENU_CONSTANT_PRIME_NUMBER_SMALL_CAPS:
			printf("Enter a number to check prime number or not: ");
			scanf("%d", &numberInput);

			if (isPrime(numberInput))
			{
				printf("The number %d is a prime number\n", numberInput);
			}
			else {
				printf("The number %d is NOT a prime number\n", numberInput);
			}
		}
	}

	return 0;
}