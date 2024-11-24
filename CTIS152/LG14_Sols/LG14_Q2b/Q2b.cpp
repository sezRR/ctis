#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* file = fopen("Q2.bin", "rb");
	if (file == NULL)
		printf("File could not be read!");
	else {
		int numAmount, *numbs;
		printf("Please enter the number of items to be read: ");
		scanf("%d", &numAmount);

		numbs = (int*)malloc(sizeof(int) * numAmount);

		size_t actualRead = fread(numbs, sizeof(int), numAmount, file);
		for (int i = 0; i < actualRead; i++)
			printf("%d. %d\n", i + 1, numbs[i]);

		free(numbs);
		fclose(file);
	}

	return 0;
}