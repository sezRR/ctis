#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "linkedList_struct.h"

void createList(FILE* file, node_t* A[]) {
	course_t temp{};
	int type;
	while (fscanf(file, " %d %[^:]: %[^\n]", &temp.courseId, temp.courseName, temp.duration) != EOF)
	{
		switch (temp.courseId)
		{
		case 1:
			A[0] = addBeginning(A[0], temp);
			break;
		case 2:
			A[1] = addBeginning(A[1], temp);
			break;
		case 3:
			A[2] = addBeginning(A[2], temp);
		}
	}
}

void displayList(node_t* headP) {
	switch (headP->data.courseId)
	{
	case 1:
		printf("Aerobics\n**********************************************\n");
		break;
	case 2:
		printf("Zumba\n**********************************************\n");
		break;
	case 3:
		printf("Pilates\n**********************************************\n");
	}

	while (headP != NULL)
	{
		printf("\t %d %-15s \t %-10s ->\n", headP->data.courseId, headP->data.courseName, headP->data.duration);
		headP = headP->next;
	}
	printf("NULL\n\n");
}

void displayLists(node_t* A[]) {
	displayList(A[0]);
	displayList(A[1]);
	displayList(A[2]);
}

int main(void) {
	FILE* file = fopen("courses.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		node_t* A[3];
		for (int i = 0; i < 3; i++)
			A[i] = NULL;
		createList(file, A);
		displayLists(A);
		fclose(file);
	}

	return 0;
}