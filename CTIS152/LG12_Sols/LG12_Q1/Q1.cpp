#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char gender[50];
	char injPart[50];
	char injType[50];
	double incCost;
} safety_comp_t;

void readFromFile(FILE* file, safety_comp_t* companies, int count) {
	for (int i = 0; i < count; i++)
		fscanf(file, "%s %s %s %lf",
			companies[i].gender,
			companies[i].injPart,
			companies[i].injType,
			&companies[i].incCost);
}

void display(safety_comp_t* companies, int count) {
	printf("Gender \t Injured PartOfBody \t Injury Type \t Cost \n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < count; i++)
		printf("%s \t %s \t %s \t $ %.2f \n",
			companies[i].gender,
			companies[i].injPart,
			companies[i].injType,
			companies[i].incCost);
}

void swap(safety_comp_t* c1, safety_comp_t* c2) {
	safety_comp_t temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void bubbleSort(safety_comp_t* companies, int count) {
	int sorted = 0,
		progress = 1;

	do
	{
		sorted = 1;
		for (int i = 0; i < count - progress; i++) {
			if (companies[i].incCost < companies[i + 1].incCost) {
				swap(&companies[i], &companies[i + 1]);
				sorted = 0;
			}
		}
		progress++;
	} while (!sorted);
}

int main(void) {
	FILE* file = fopen("safety.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		int count;
		fscanf(file, "%d", &count);

		safety_comp_t* companies;
		companies = (safety_comp_t*)malloc(count * sizeof(safety_comp_t));

		readFromFile(file, companies, count);
		bubbleSort(companies, count);
		display(companies, count);

		fclose(file);
	}

	return 0;
}