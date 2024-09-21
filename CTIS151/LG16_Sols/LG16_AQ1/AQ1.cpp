#define _CRT_SECURE_NO_WARNINGS

#define ARR_MAX_LENGTH 20

#include <stdio.h>

int readFromFile(FILE* file, int sales[], int bonusses[])
{
	int counter = 0;

	while (fscanf(file, "%d %d", &sales[counter], &bonusses[counter]) != EOF)
		counter++;

	return counter;
}

double findAvg(int arr[], int lengthOfArray)
{
	double sum = 0;

	for (int i = 0; i < lengthOfArray; i++)
		sum += arr[i];

	return sum / lengthOfArray;
}

void displayReport(int sales[], int bonusses[], int counter)
{
	printf("SALESPERSON  SALES    BONUS\n", ' ');
	printf("*********** *******   *****\n");
	for (int i = 0; i < counter; i++)
		printf("%7d %4c %d %7d\n", i + 1, ' ', sales[i], bonusses[i]);

	printf("***************************\n");
	printf("%5c Avg: %6.2f %6.2f", ' ', findAvg(sales, counter), findAvg(bonusses, counter));

}

int main(void)
{
	FILE* paymentsFile = fopen("payments.txt", "r");

	if (paymentsFile == NULL)
		printf("File could not be opened!");
	else 
	{
		int sales[ARR_MAX_LENGTH];
		int bonusses[ARR_MAX_LENGTH];
		int lengthOfArr;

		lengthOfArr = readFromFile(paymentsFile, sales, bonusses);
		displayReport(sales, bonusses, lengthOfArr);
	}

	return 0;
}