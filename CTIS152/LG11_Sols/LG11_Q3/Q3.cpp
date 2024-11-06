#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char month[50];
	char seminarName[50];
	int participants;
} seminar_t;

void swap(seminar_t* seminar1, seminar_t* seminar2) {
	seminar_t temp;
	temp = *seminar1;
	*seminar1 = *seminar2;
	*seminar2 = temp;
}

void readFromFile(FILE* file, seminar_t* seminars, int numberOfElement) {
	for (int i = 0; i < numberOfElement; i++)
		fscanf(file, "%s %[^0-9] %d",
		(seminars + i)->month,
		(seminars + i)->seminarName,
		&(seminars + i)->participants);
}

void display(seminar_t* seminars, int nbOfElements) {
	printf("Month \t\t Seminar \t\t\t Participant\n--------------------------------------------------------\n");
	for (int i = 0; i < nbOfElements; i++)
		printf("%-10s \t %-15s \t\t %d \n", seminars[i].month, seminars[i].seminarName, seminars[i].participants);
}

void bubleSort(seminar_t* seminars, int n) {
	int sorted, visited = 1;
	do
	{
		sorted = 1;
		for (int i = 0; i < n - visited; i++)
		{
			if (seminars[i].participants < seminars[i + 1].participants)
			{
				swap(&seminars[i], &seminars[i + 1]);
				sorted = 0;
			}
		}
		visited++;
	} while (!sorted);
}

int main(void) {
	FILE* file = fopen("seminars.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		seminar_t* seminars;

		int seminarCount;
		fscanf(file, "%d", &seminarCount);

		seminars = (seminar_t*)malloc(seminarCount * sizeof(seminar_t));
		readFromFile(file, seminars, seminarCount);

		bubleSort(seminars, seminarCount);
		display(seminars, seminarCount);

		fclose(file);
	}
	return 0;
}