#include <stdio.h>
#define LAST_ELEMENT 10

int main(void)
{
	int i = 0;
	double sum = 0, average = 0;

	for (i = 1; i <= LAST_ELEMENT; i++)
	{
		sum += i;
	}

	average = sum / LAST_ELEMENT;

	printf("The sum of the numbers is %.0f", sum);
	printf("\nThe average of the numbers is %.2f", average);

	return 0;
}