#define _CRT_SECURE_NO_WARNINGS

#define MOVIE_COUNT 10

#include <stdio.h>

typedef struct {
	char movie_name[20];
	char type;
	double price;
	int release_year;
} movie_t;

int main(void) {
	FILE* moviesFile = fopen("movies.txt", "r");
	movie_t movies[MOVIE_COUNT];

	if (moviesFile == NULL)
		printf("File could not be opened!");
	else {
		for (int i = 0; i < MOVIE_COUNT; i++)
			fscanf(moviesFile, "%s %c %lf %d", 
			(movies + i)->movie_name, 
			&(movies + i)->type, 
			&(movies + i)->price, 
			&(movies + i)->release_year);

		printf("The movie information is:\n");
		for (int i = 0; i < MOVIE_COUNT; i++)
		{
			printf("******************************\n");
			printf("Name: %s \n", (movies + i)->movie_name);
			printf("Movie Type: %c \n", (movies + i)->type);
			printf("Price: %.1f: \n", (movies + i)->price);
			printf("Release Year: %d \n", (movies + i)->release_year);
		}

		fclose(moviesFile);
	}

	return 0;
}