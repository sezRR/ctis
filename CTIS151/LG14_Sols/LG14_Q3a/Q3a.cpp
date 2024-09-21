#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LENGTH 10

#include <stdio.h>

int main(void)
{
	// Declare variables
	int ids[MAX_ARR_LENGTH] = { 111, 222, 333, 444, 555, 666, 777, 888, 999, 100 };
	double salaries[MAX_ARR_LENGTH];
	
	int equalsToAvaragesSalariesIndexes[MAX_ARR_LENGTH];
	int greaterThanAvaragesSalariesIndexes[MAX_ARR_LENGTH];
	int lessThanAvaragesSalariesIndexes[MAX_ARR_LENGTH];

	double sumOfSalaries = 0, avarageOfSalaries = 0;
	int i, equalsToAvarageCounter = 0, greaterThanAvarageCounter = 0, lessThanAvarageCounter = 0;

	// Get inputs from the user
	printf("Enter %d employees' salaries:\n", MAX_ARR_LENGTH);
	for (i = 0; i < MAX_ARR_LENGTH; i++)
	{
		printf("id = %d salary = ", ids[i]);
		scanf(" %lf", &salaries[i]);
		sumOfSalaries += salaries[i];
	}

	// Calculate avarage and print it
	avarageOfSalaries = sumOfSalaries / i;
	printf("\nThe average salary is %.2f\n\n", avarageOfSalaries);

	// Determine how many salaries equal to avarage salary and print it
	for (int i = 0; i < MAX_ARR_LENGTH; i++)
	{
		if (salaries[i] == avarageOfSalaries)
		{
			equalsToAvaragesSalariesIndexes[equalsToAvarageCounter] = i;
			equalsToAvarageCounter++;
		}
		else if (salaries[i] > avarageOfSalaries)
		{
			greaterThanAvaragesSalariesIndexes[greaterThanAvarageCounter] = i;
			greaterThanAvarageCounter++;
		}
		else if (salaries[i] < avarageOfSalaries)
		{
			lessThanAvaragesSalariesIndexes[lessThanAvarageCounter] = i;
			lessThanAvarageCounter++;
		}
	}

	if (equalsToAvarageCounter == 0)
		printf("Number of salaries equal to average salary is %d\n", equalsToAvarageCounter);
	else
	{
		printf("\nEquals\n");
		for (int i = 0; i < equalsToAvarageCounter; i++)
			printf("%d %.2f\n", ids[equalsToAvaragesSalariesIndexes[i]], salaries[equalsToAvaragesSalariesIndexes[i]]);
	}

	if (greaterThanAvarageCounter == 0)
		printf("Number of salaries greater than average salary is %d\n", greaterThanAvarageCounter);
	else
	{
		printf("\nGreater\n");
		for (int i = 0; i < greaterThanAvarageCounter; i++)
			printf("%d %.2f\n", ids[greaterThanAvaragesSalariesIndexes[i]], salaries[greaterThanAvaragesSalariesIndexes[i]]);
	}

	if (lessThanAvarageCounter == 0)
		printf("Number of salaries less than average salary is %d\n", lessThanAvarageCounter);
	else
	{
		printf("\nLower\n");
		for (int i = 0; i < lessThanAvarageCounter; i++)
			printf("%d %.2f\n", ids[lessThanAvaragesSalariesIndexes[i]], salaries[lessThanAvaragesSalariesIndexes[i]]);
	}

	return 0;
}