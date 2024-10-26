#define _CRT_SECURE_NO_WARNINGS

#define MAX_STR_LEN 250

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE* file = fopen("recipe.txt", "r");
	int lineCounter = 1;

	if (file == NULL)
		printf("File could not be opened!");
	{
		int wordCounter = 0;
		char tempStr[MAX_STR_LEN] = "";
		while (fscanf(file, "%s ", tempStr) != EOF)
		{
			if (strcmp(tempStr, "EOL") == 0)
			{
				printf("%d. line contains %d words\n", lineCounter++, wordCounter);
				wordCounter = 0;
			}
			else
				wordCounter++;
		}

		fclose(file);
	}

	return 0;
}