#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	double y, z, result = 0, lastTerm = 1;
	int oddN, sign = -1;

	do
	{
		printf("Enter the value of y: ");
		scanf("%lf", &y);
	} while (y == -1);

	do
	{
		printf("Enter the value of n: ");
		scanf("%d", &oddN);
	} while (oddN % 2 == 0);

	// With math.h
	//for (int i = 3; i <= oddN; i += 2)
	//{
	//	result += sign * (i - 1) / pow(y + 1, i);
	//	sign *= -1;
	//}

	// Without math.h
	for (int i = 3; i <= oddN; i += 2)
	{
		lastTerm = (i - 1);
		for (int j = 0; j < i; j++)
		{
			lastTerm /= y + 1;
		}

		result += sign * lastTerm;
		sign *= -1;
	}
	
	printf("The result is %f", result);

	return 0;
}