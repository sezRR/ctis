#define _CRT_SECURE_NO_WARNINGS

#define LINE_SIZE 10
#define LINE_CHARACTER '#'

#include <stdio.h>

void dispLine(); // Function Prototype

int main(void)
{

	dispLine();
	return 0;
}

void dispLine()
{
	for (int i = 0; i < LINE_SIZE; i++)
	{
		printf("%c", LINE_CHARACTER);
	}
	printf("\n");
}