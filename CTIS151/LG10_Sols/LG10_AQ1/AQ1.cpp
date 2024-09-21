#define _CRT_SECURE_NO_WARNINGS

#define SIDE_LENGTH_MAX 10
#define SIDE_LENGTH_MIN 4

#include <stdio.h>

void drawChar(int lineSize, char character, bool newLineAfterProcess)
{
	for (int i = 0; i < lineSize; i++)
	{
		printf("%c", character);
	}

	if (newLineAfterProcess)
		printf("\n");
}

void drawGap(int gapAmount)
{
	drawChar(gapAmount, ' ', 0);
}

void drawRhombus(int sideLength, char character)
{
	for (int i = 1; i <= sideLength; i++)
	{
		drawGap(sideLength - i);
		drawChar(2 * i - 1, character, 1);
	}

	for (int i = sideLength - 1; i >= 0; i--)
	{
		drawGap(sideLength - i);
		drawChar(2 * i - 1, character, 1);
	}
}

char getCharacterInput(char& characterInput)
{
	printf("Enter a character (! to stop): ");
	scanf(" %c", &characterInput);

	return characterInput;
}

void getSideLengthInput(int& sideLength)
{
	do
	{
		printf("Enter the side length (4 - 10): ");
		scanf("%d", &sideLength);
	} while (sideLength < SIDE_LENGTH_MIN || sideLength > SIDE_LENGTH_MAX);
}

int main(void)
{
	// Define variables
	char printableCharacter;
	int sideLength;

	while (1)
	{
		// Get character input from the user
		getCharacterInput(printableCharacter);

		// Check whether printable character '!' or not
		if (printableCharacter == '!')
			break;

		// Get side length from the user
		getSideLengthInput(sideLength);

		// Draw rhombus by specified inputs
		drawRhombus(sideLength, printableCharacter);
	}

	return 0;
}