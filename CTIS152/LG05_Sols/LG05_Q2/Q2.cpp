#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char studentName[50];
	double cgpa;
	double alesGrade;
	double ydsGrade;

	double grade;
	int scholarAmount;
} stu_t;

int main(void) {
	FILE* graduateStudentFile = fopen("graduateStudent.txt", "r");
	stu_t* student;

	int stuCount = 0;

	if (graduateStudentFile == NULL)
		printf("File could not be opened!");
	else {
		fscanf(graduateStudentFile, "%d", &stuCount);
		student = (stu_t*)malloc(stuCount * sizeof(stu_t));

		for (int i = 0; i < stuCount; i++)
		{
			fscanf(graduateStudentFile, "%s %lf %lf %lf", (student + i)->studentName, &(student + i)->cgpa, &(student + i)->alesGrade, &(student + i)->ydsGrade);
			(student + i)->scholarAmount = 0;
			(student + i)->grade = 0;
		}

		for (int i = 0; i < stuCount; i++)
		{
			(student + i)->grade = ((student + i)->cgpa * (30 / 100.0)) + ((student + i)->alesGrade * (45 / 100.0) + ((student + i)->ydsGrade) * (25 / 100.0));

			if ((student + i)->grade > 90)
				(student + i)->scholarAmount = 100;
			else if ((student + i)->grade < 90 && (student + i)->grade > 80)
				(student + i)->scholarAmount = 75;
			else if ((student + i)->grade < 80 && (student + i)->grade > 65)
				(student + i)->scholarAmount = 50;
		}

		printf("STUDENT NAME\t\tCGPA\tALES\tYDS\t\tGRADE\t\tSCHOLAR PERCENTAGE\n");
		printf("************\t\t****\t****\t***\t\t*****\t\t*******************\n");
		for (int i = 0; i < stuCount; i++)
			printf("%s \t\t %.2f \t %.2f \t %.2f \t\t %.2f \t\t %d %% \n", 
				(student + i)->studentName,
				(student + i)->cgpa,
				(student + i)->alesGrade,
				(student + i)->ydsGrade,
				(student + i)->grade,
				(student + i)->scholarAmount);

		free(student);
		fclose(graduateStudentFile);
	}

	return 0;
}