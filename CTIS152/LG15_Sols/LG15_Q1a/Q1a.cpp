#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	char country[5];
	double dolarUnit;
	double euroUnit;
} curr_t;

void convertTxtToBin(FILE* binFile, curr_t* currencies, int el) {
	for (int i = 0; i < el; i++)
		fwrite(&currencies[i], sizeof(curr_t), 1, binFile);
}

int main(void) {
	FILE *file = fopen("currency.txt", "r"), *binFile = fopen("currency.bin", "wb");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		curr_t currencies[10];
		int i = 0;

		while (fscanf(file, "%s %lf %lf",
			currencies[i].country,
			&currencies[i].dolarUnit,
			&currencies[i].euroUnit) != EOF)
			i++;

		convertTxtToBin(binFile, currencies, i);
		
		printf("FILE created with %d lines", ftell(binFile) / sizeof(curr_t));

		fclose(binFile);
		fclose(file);
	}

	return 0;
}