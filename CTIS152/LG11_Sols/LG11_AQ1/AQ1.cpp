#define _CRT_SECURE_NO_WARNINGS

#define MAX 50

#include <stdio.h>
#include <string.h>

typedef struct {
	char name[MAX];
	char surname[MAX];
	int birthYear;
} person_t;

void swap(person_t* person1, person_t* person2) {
	person_t tempPerson = *person1;
	*person1 = *person2;
	*person2 = tempPerson;
}

void bubbleSortTwoLevel(person_t* persons, int noe) {
	int pass, k, sorted;
	// Primary sort by surname
	pass = 1;
	do {
		sorted = 1;
		for (k = 0; k < noe - pass; k++) {
			if (strcmp(persons[k].surname, persons[k + 1].surname) > 0) {
				swap(&persons[k], &persons[k + 1]);
				sorted = 0;
			}
			else if (strcmp(persons[k].surname, persons[k + 1].surname) == 0) {
				if (strcmp(persons[k].name, persons[k + 1].name) > 0) {
					swap(&persons[k], &persons[k + 1]);
					sorted = 0;
				}
			}
		}
		pass++;
	} while (!sorted);
}

int main(void) {
	FILE* peopleFile = fopen("people.txt", "r"), * sortedFile = fopen("sorted.txt", "w");

	if (peopleFile == NULL)
		printf("File could not be opened!");
	else {
		person_t persons[MAX]{};

		int personCount = 0;
		while (fscanf(peopleFile, "%s %s %d",
			(persons + personCount)->name,
			(persons + personCount)->surname,
			&(persons + personCount)->birthYear) != EOF)
			personCount++;

		bubbleSortTwoLevel(persons, personCount);

		for (int i = 0; i < personCount; i++)
			fprintf(sortedFile, "%-15s \t %-15s \t %d\n",
				(persons + i)->name,
				(persons + i)->surname,
				(persons + i)->birthYear);

		fclose(sortedFile);
		fclose(peopleFile);
	}

	return 0;
}