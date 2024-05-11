#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LENGTH 6

#include <stdio.h>

void maxMinIndex(int ids[], int applicants[], int* greatestIndex, int* smallestIndex)
{
	int greatest = -99999, smallest = 99999;
	for (int i = 0; i < MAX_ARR_LENGTH; i++)
	{
		if (applicants[i] > greatest)
		{
			*greatestIndex = ids[i];
			greatest = applicants[i];

		}
		
		if (applicants[i] < smallest)
		{
			*smallestIndex = ids[i];
			smallest = applicants[i];
		}
	}
}

int main(void)
{
	FILE* applicantsFile = fopen("applicants.txt", "r");
	int ids[MAX_ARR_LENGTH];
	int applicantTotals[MAX_ARR_LENGTH];


	if (applicantsFile == NULL)
		printf("File could not be opened!");
	else 
	{
		int temp, idIndex = 0, applicantIndex = 0;
		while (fscanf(applicantsFile, "%d", &temp) != EOF)
		{
			ids[idIndex] = temp;
			idIndex++;

			if (fscanf(applicantsFile, "%d", &temp) != EOF)
			{
				applicantTotals[applicantIndex] = temp;
				applicantIndex++;
			}
		}

		int greatest = 0, smallest = 0;

		maxMinIndex(ids, applicantTotals, &greatest, &smallest);

		printf("The maximum number of applications were made to the %d coded job pos.\n", greatest);
		printf("The minimum number of applications were made to the %d coded job pos.", smallest);
	}

	return 0;
}