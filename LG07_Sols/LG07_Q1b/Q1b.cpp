#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int i = 0, lastElement;
	double sum = 0, average = 0;

	printf("Enter a value: ");
	scanf("%d", &lastElement);

	for (i = 1; i <= lastElement; i++)
	{
		sum += i;
	}

	average = sum / lastElement;

	printf("The sum of the numbers is %.0f", sum);
	printf("\nThe average of the numbers is %.2f", average);

	return 0;
}