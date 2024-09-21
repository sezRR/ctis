#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void printDirection(int headingDegrees)
{
	if (headingDegrees >= 0 && headingDegrees <= 45)
		printf("NORTH\n\n");
	else if (headingDegrees >= 316 && headingDegrees <= 360)
		printf("NORTH\n\n");
	else if (headingDegrees >= 226 && headingDegrees <= 315)
		printf("WEST\n\n");
	else if (headingDegrees >= 136 && headingDegrees <= 225)
		printf("SOUTH\n\n");
	else if (headingDegrees > 45 && headingDegrees <= 135)
		printf("EAST\n\n");
	else
		return;
}

int main(void)
{
	int headingDegrees;

	while (1)
	{
		printf("Compass Reading? ");
		while (1)
		{
			scanf("%d", &headingDegrees);

			if (headingDegrees > 360)
				printf("INVALID! Enter another compass reading? ");
			else if (headingDegrees < 0)
				return 0;
			else
				break;
		}

		printDirection(headingDegrees);
	}

	return 0;
}