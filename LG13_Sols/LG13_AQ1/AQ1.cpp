#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Define variables
	FILE* expressionFilePtr = fopen("expression.txt", "w");

	char expressionChar;
	int waitingBrackets = 0;

	// Get expression from the user
	if (expressionFilePtr == NULL) {
		printf("File could not be opened!");
		return 1;
	}

	printf("Enter expressions # to finish:\n");
	scanf(" %c", &expressionChar);
	while (expressionChar != '#')
	{
		if (expressionChar != '\n')
			fprintf(expressionFilePtr, "%c", expressionChar);

		switch (expressionChar)
		{
		case '(':
			waitingBrackets++;
			break;
		case ')':
			waitingBrackets--;
			break;
		case '\n':
			if (waitingBrackets > 0)
				fprintf(expressionFilePtr, "   UNBALANCED closing paranthese(s) is/are missing\n");
			else if (waitingBrackets < 0)
				fprintf(expressionFilePtr, "   UNBALANCED opening paranthese(s) is/are missing\n");
			else
				fprintf(expressionFilePtr, "   BALANCED\n");

			waitingBrackets = 0;
		}

		scanf("%c", &expressionChar);
	}

	return 0;
}