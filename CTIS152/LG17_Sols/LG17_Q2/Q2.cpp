#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "queue_string.h"

void display(queue_t q);

int main(void) {
	FILE* file = fopen("busstop.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		queue_t q;
		initializeQ(&q);

		char str[STR_SIZE] = "";
		while (fscanf(file, "%s", str) != EOF)
			insert(&q, str);

		printf("Waiting passengers:\n");
		display(q);

		printf("The bus arrived to the bus stop!\n");

		int passengersToGet;
		printf("How many passengers getting on the bus? ");
		scanf("%d", &passengersToGet);

		printf("The list of passengers getting on the bus:\n");
		for (int i = 0; i < passengersToGet; i++) {
			char str[STR_SIZE];
			strcpy(str, remove(&q));
			printf("%s\n", str);
		}

		printf("Waiting passengers:\n");
		display(q);

		fclose(file);
	}

	return 0;
}

void display(queue_t q) {
	while (!isEmptyQ(&q)) {
		char str[STR_SIZE];
		strcpy(str, remove(&q));
		printf("%s\n", str);
	}
}