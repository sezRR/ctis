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

void bubbleSortTwoLevel(person_t* persons, int nbOfPerson) {
	int sorted = 0,
		progress = 1;

	// SORT BY SURNAME ASC
	do
	{
		sorted = 1;
		for (int i = 0; i < nbOfPerson - progress; i++)
		{
			if (strcmp(persons[i].surname, persons[i + 1].surname) > 0)
			{
				swap(&persons[i], &persons[i + 1]);
				sorted = 0;
			}
		}
		progress++;
	} while (!sorted);

	// WHERE PERSON.SURNAME = PERSON + 1.SURNAME
	// SORT BY NAME ASC
	sorted = 0;
	progress = 0;
	do
	{
		sorted = 1;
		for (int i = 0; i < nbOfPerson - progress; i++)
		{
			if (strcmp(persons[i].surname, persons[i + 1].surname) == 0)
			{
				if (strcmp(persons[i].name, persons[i + 1].name) > 0)
				{
					swap(&persons[i], &persons[i + 1]);
					sorted = 0;
				}
			}
		}
		progress++;
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