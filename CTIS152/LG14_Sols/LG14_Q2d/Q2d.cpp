#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	FILE* file = fopen("Q2.bin", "rb");
	if (file == NULL)
		printf("File could not be read!");
	else {
		fseek(file, sizeof(int) * 1, SEEK_END);
		fseek(file, sizeof(int) * -4, SEEK_CUR);

		int num;
		fread(&num, sizeof(int), 1, file);
		printf("%d. %d\n", 1, num);

		fseek(file, sizeof(int) * -4, SEEK_CUR);
		fread(&num, sizeof(int), 1, file);
		printf("%d. %d\n", 1, num);

		fclose(file);
	}

	return 0;
}