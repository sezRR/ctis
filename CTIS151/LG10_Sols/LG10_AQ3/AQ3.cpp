#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void dispChar(int n, char ch)
{
	for (int i = 0; i < n; i++)
	{
		printf("%c", ch);
	}

	if (ch != ' ')
		printf("\n");
}

int main(void)
{
	// Define variables
	int sideLength;

	do
	{
		printf("Enter the side length (3-20): ");
		scanf("%d", &sideLength);
	} while (sideLength < 3 || sideLength > 20);

	for (int i = sideLength; i > 0; i--)
	{
		dispChar(sideLength - i, ' ');
		dispChar(i * 2, '*');
	}

	for (int i = 1; i <= sideLength; i++)
	{
		dispChar(sideLength - i, ' ');
		dispChar(i * 2, '*');
	}

	return 0;
}