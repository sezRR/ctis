#define _CRT_SECURE_NO_WARNINGS

#define PACKAGE_SIZE 2

#include <stdio.h>
#include <string.h>
#include "queue_struct.h"

void displayQ(queue_t q) {
	printf("The list of people;\n\n");
	printf("House Houlder \t\t Distance \t # of People \t # of Package\n");
	printf("***********************************************************************\n");
	while (!isEmptyQ(&q))
	{
		house_t temp = remove(&q);
		printf("%-15s \t %-10d \t %-10d \t %d\n", temp.holder, temp.dist, temp.nbOfPeople, temp.nbOfPackage);
	}
}

void fillQ(FILE* file, queue_t* q) {
	house_t temp;
	while (fscanf(file, " %[^:]:%d %d", temp.holder, &temp.dist, &temp.nbOfPeople) != EOF) {
		int people = temp.nbOfPeople;
		if (temp.nbOfPeople % 2 == 1)
			people++;

		temp.nbOfPackage = people / PACKAGE_SIZE;

		insert(q, temp);
	}
	fclose(file);
}

bool searchInQ(queue_t q, char* householder) {
	while (!isEmptyQ(&q))
		if (strcmp(householder, remove(&q).holder) == 0)
			return 1;
	return 0;
}

int removeFromQ(queue_t* q, char* householder, house_t* deletedInfo) {
	queue_t temp;
	initializeQ(&temp);

	house_t temp_house;

	int searchRes = searchInQ(*q, householder);
	if (searchRes == 0) {
		printf("There is no householder with the specified name!\n\n");
		return 0;
	}

	while (!isEmptyQ(q)) {
		temp_house = remove(q);
		if (strcmp(temp_house.holder, householder) != 0)
			insert(&temp, temp_house);
		else
			*deletedInfo = temp_house;
	}

	while (!isEmptyQ(&temp))
		insert(q, remove(&temp));

	return 1;
}

int main(void) {
	FILE* file = fopen("village.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		queue_t q;
		initializeQ(&q);

		fillQ(file, &q);

		char isPackageDamaged;
		while (1)
		{
			displayQ(q);

			printf("\nAll of the packages were distributed.\n");
			do
			{
				printf("Do we have damaged package? (Y / N): ");
				scanf(" %c", &isPackageDamaged);
				if (isPackageDamaged != 'Y' && isPackageDamaged != 'y' && isPackageDamaged != 'N' && isPackageDamaged != 'n')
					printf("Invalid option!\n\n");
			} while (isPackageDamaged != 'Y' && isPackageDamaged != 'y' && isPackageDamaged != 'N' && isPackageDamaged != 'n');

			if (isPackageDamaged == 'N' || isPackageDamaged == 'n')
				break;

			char householder[STR_MAX] = "";
			house_t deletedHouse{};
			printf("\nEnter the household: ");
			scanf(" %[^\n]", householder);
			bool isDeleted = removeFromQ(&q, householder, &deletedHouse);
			if (!isDeleted)
				continue;

			int damagedPackages;
			printf("How many package was damaged?: ");
			scanf("%d", &damagedPackages);

			deletedHouse.nbOfPackage -= damagedPackages;

			insert(&q, deletedHouse);
		}

		printf("\nThank you for your help :)");
	}

	return 0;
}