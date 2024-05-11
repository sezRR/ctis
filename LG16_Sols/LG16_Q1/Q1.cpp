#define _CRT_SECURE_NO_WARNINGS

#define ARR_MAX_LENGTH 30

#include <stdio.h>

// Returns -> Numbers of films
int readFromFile(FILE* file, int ids[], double ratings[], char types[])
{
	int counter = 0;

	while (fscanf(file, "%d %lf %c", &ids[counter], &ratings[counter], &types[counter]) != EOF)
		counter++;

	return counter;
}

void displayFilm(int filmId, char type, double rate)
{
	printf("%7d %7.1f", filmId, rate, type);

	switch (type)
	{
	case 'A':
		printf("%5c Action\n", ' ');
		break;
	case 'R':
		printf("%5c Romance\n", ' ');
		break;
	case 'W':
		printf("%5c Western\n", ' ');
	}
}

void display(int ids[], double ratings[], char types[], int filmAmount)
{
	printf("There are %d films in the array\n\n", filmAmount);

	printf("Film Id %3c Rate %3c Type\n", ' ', ' ');
	printf("******* %3c **** %3c ******\n", ' ', ' ');
	for (int i = 0; i < filmAmount; i++)
		displayFilm(ids[i], types[i], ratings[i]);
}

int searchFilm(int ids[], int filmAmount, int searchFilmId)
{
	for (int i = 0; i < filmAmount; i++)
	{
		if (ids[i] == searchFilmId)
			return i;
	}

	return -1;
}

int main(void)
{
	FILE* filmsFile = fopen("films.txt", "r");

	if (filmsFile == NULL)
		printf("File could not be opened!");
	else {
		int ids[ARR_MAX_LENGTH];
		double ratings[ARR_MAX_LENGTH];
		char types[ARR_MAX_LENGTH];

		int filmAmount = readFromFile(filmsFile, ids, ratings, types);

		display(ids, ratings, types, filmAmount);

		int filmToFind;
		while (1)
		{
			printf("Enter a film id to search (negative id to stop): ");
			scanf("%d", &filmToFind);

			if (filmToFind < 0)
				break;

			int foundFilmIndex = searchFilm(ids, filmAmount, filmToFind);
			if (foundFilmIndex == -1)
				printf("The searched film id %d is NOT found\n", filmToFind);
			else
				displayFilm(ids[foundFilmIndex], types[foundFilmIndex], ratings[foundFilmIndex]);

			printf("\n");
		}
	}


	return 0;
}