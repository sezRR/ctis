/*
*	WRITE A PROGRAM TO DISPLAY THE FOLLOWING TRIANGLE, USING A FUNCTION
*
*	OUTPUT:
*	    *
*	   ***
*	  *****
*	 *******
*	**********
* 
*/

#define _CRT_SECURE_NO_WARNINGS

#define ROW_COUNT 5
#define OUTPUT_CHARACTER '*'

#include <stdio.h>

void drawChar(int times, char character)
{
	for (int i = 0; i < times; i++)
		printf("%c", character);

	if (character != ' ')
		printf("\n");
}

void drawTriangle(int rowCount, char character)
{
	for (int i = 1; i <= rowCount; i++)
	{
		drawChar(rowCount - i, ' ');
		drawChar(i * 2 - 1, character);
	}
}

int main(void)
{
	drawTriangle(ROW_COUNT, OUTPUT_CHARACTER);

	return 0;
}