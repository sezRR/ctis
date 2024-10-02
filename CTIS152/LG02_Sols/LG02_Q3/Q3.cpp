#define _CRT_SECURE_NO_WARNINGS

#define MAX 250

#include <stdio.h>

int main(void) {
	int arr[MAX] = { 0 }, counter = 0, duplicateCounter = 0;
	FILE* matchedItemsFile = fopen("matchedItems.txt", "w");

	if (matchedItemsFile == NULL)
		printf("File could not be opened!");
	else {
		while (1)
		{
			printf("Enter a number: ");
			scanf("%d", &arr[counter]);

			if (arr[counter] < 0)
				break;

			for (int i = 0; i < counter; i++)
				if (arr[i] == arr[counter]) {
					fprintf(matchedItemsFile, "%d\n", *(arr + i));
					duplicateCounter++;
				}
			counter++;
		}
		printf("Total number of duplicate elements found in the array -> %d", duplicateCounter);
	}
	return 0;
}