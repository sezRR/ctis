#define _CRT_SECURE_NO_WARNINGS

#define MODULUS_NUMBER 9
#define ELEMENT_COUNT 10

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int randomNumber, modulusNumberRemains = 0;
	double sum = 0;
	int _temp;

	srand(time(NULL));   
	randomNumber = rand() % 100;
	modulusNumberRemains = randomNumber % MODULUS_NUMBER;

	switch (modulusNumberRemains)
	{
	case 0:
		printf("%d", randomNumber);
		break;
	case 1:
	case 2:
		for (int i = 1; i <= randomNumber; i++)
		{
			sum += i;
		}

		printf("Sum of the numbers 0 to %d is %.f", randomNumber, sum);
		break;
	case 3:
	case 4:
	case 5:
		printf("Square root of %d is %f", randomNumber, sqrt(randomNumber));
		break;
	default:
		printf("Enter 10 integers:\n");

		for (int i = 0; i < ELEMENT_COUNT; i++)
		{
			scanf("%d", &_temp);
			sum += _temp;
		}

		printf("Average of these numbers is %.1f", sum / ELEMENT_COUNT);
		break;
	}
}