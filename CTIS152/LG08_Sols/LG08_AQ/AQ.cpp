#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct {
	char departmentName[MAX];
	char courseCode[MAX];
} codes_t;

int searchCrs(codes_t* codes, int nbCodes, codes_t course) {
	for (int i = 0; i < nbCodes; i++)
		if (strcmp((codes + i)->departmentName, course.departmentName) == 0)
			return i;
	return -1;
}

int main(void) {
	FILE* file = fopen("course.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		int nbOfCourses = 0, nbOfCodes = 8;
		codes_t codeList[MAX] = { {"CS","11"}, {"THM","61"}, {"CTIS","62"}, {"ECON","32"}, {"HIST","94"}, {"TURK","95"} };
		codes_t courses[MAX] = {};

		while (fscanf(file, "%s %s", courses[nbOfCourses].departmentName, (courses + nbOfCourses)->courseCode) != EOF) {
			nbOfCourses++;
		}

		for (int i = 0; i < nbOfCourses; i++)
		{
			printf("%s %s -> ", courses[i].departmentName, (courses + i)->courseCode);
			int index = searchCrs(codeList, nbOfCodes, *(courses + i));
			if (index != -1)
			{
				char tempCode[MAX] = "";
				strcpy(tempCode, codeList[index].courseCode);
				strcat(tempCode, (courses + i)->courseCode);
				printf("%s\n", tempCode);
			}
			else
				printf("ERROR!\n");

		}

		fclose(file);
	}

	return 0;
}