#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int i = 0, firstElement, lastElement;
	double sum = 0, average = 0;

	printf("Enter a range: ");
	scanf("%d %d", &firstElement, &lastElement);

	for (i = firstElement; i <= lastElement; i++)
	{
		sum += i;
	}

	average = sum / (lastElement - firstElement + 1);

	printf("The sum of the numbers is %.0f", sum);
	printf("\nThe average of the numbers is %.2f", average);

	return 0;
}