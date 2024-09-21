#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LENGTH 99

#include <stdio.h>

int displayType(int courseCodes[], int courseCodesSize, char courseCodeChars[], int courseCodeCharsSize, int searchingCourse)
{
	for (int i = 0; i < courseCodesSize; i++)
	{
		if (courseCodes[i] == searchingCourse)
		{
			printf("164 course is ");
			switch (courseCodeChars[i])
			{
			case 'O':
				printf("Online education type!");
				return 1;
			case 'F':
				printf("Face-to-Face education type!");
				return 1;
			}
		}
	}

	return 0;
}

int main(void)
{
	FILE* coursesFile = fopen("courses.txt", "r");

	if (coursesFile == NULL)
		printf("File could not be opened!");
	{
		int searchCourseCode;
		printf("Enter your search course code: ");
		scanf("%d", &searchCourseCode);

		int i = 0;
		int courseCodes[MAX_ARR_LENGTH];
		char courseCodeChars[MAX_ARR_LENGTH];
		while (fscanf(coursesFile, "%d", &courseCodes[i]) != EOF)
		{
			fscanf(coursesFile, " %c", &courseCodeChars[i]);
			i++;
		}

		if (displayType(courseCodes, i + 1, courseCodeChars, i + 1, searchCourseCode) == 0)
			printf("COURSE NOT FOUND");
	}

	return 0;
}