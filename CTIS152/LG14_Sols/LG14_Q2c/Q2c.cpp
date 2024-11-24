#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	FILE* file = fopen("Q2.bin", "rb");
	if (file == NULL)
		printf("File could not be read!");
	else {
		int numIndex, num;
		printf("Please enter the order of the item to be read: ");
		scanf("%d", &numIndex);

		fseek(file, sizeof(int) * (numIndex - 1), SEEK_SET);
		int read = fread(&num, sizeof(int), 1, file);
		if (read != 1)
		{
			printf("Something goes wrong...");
			return 1;
		}

		printf("%d. %d\n", numIndex, num);

		fclose(file);
	}

	return 0;
}