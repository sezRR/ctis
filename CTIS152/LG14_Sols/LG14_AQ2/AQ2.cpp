#define _CRT_SECURE_NO_WARNINGS

#define MAX 50
#define OUTP_BIN_FILE "binary.bin"

#include <stdio.h>

typedef struct {
	char comm;
	int curPos;
	char content;
} input_t;

/*
	Returns:
		0 -> In order to show that there was no ERROR
		1 -> In order to show that there was an ERROR
*/
bool writeToBin(FILE* inpFile, const char* outputBinFileName) {
	FILE* outputBinFile = fopen(outputBinFileName, "wb");
	if (outputBinFile == NULL)
		return 1;

	input_t temp{};
	while (fscanf(inpFile, " %c %d %c", &temp.comm, &temp.curPos, &temp.content) != EOF) {
		if (fwrite(&temp, sizeof(input_t), 1, outputBinFile) != 1)
			return 1;
	}

	fclose(outputBinFile);
	fclose(inpFile);
	return 0;
}

void move(FILE* binFile, input_t record) {
	printf("%c", record.content);
	switch (record.comm)
	{
	case 'S':
		fseek(binFile, (record.curPos - 1) * sizeof(input_t), SEEK_SET);
		break;
	case 'C':
		fseek(binFile, (record.curPos - 1) * sizeof(input_t), SEEK_CUR);
			break;
	case 'E':
		fseek(binFile, -record.curPos * sizeof(input_t), SEEK_END);
	}
}

int main(void) {
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("File could not be opened!");
		return 1;
	}

	int res = writeToBin(file, OUTP_BIN_FILE);
	if (res == 1)
	{
		printf("Something went wrong while writing to binary file. Exiting...");
		return 1;
	}

	FILE* binFile = fopen(OUTP_BIN_FILE, "rb");
	if (binFile == NULL) {
		printf("Binary file could not be opened!");
		return 1;
	}

	input_t input{};
	while (fread(&input, sizeof(input_t), 1, binFile) == 1)
		move(binFile, input);

	return 0;
}