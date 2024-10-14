#define _CRT_SECURE_NO_WARNINGS

#define COLLEGE_FREE 68500

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char type;
	int degree;
	int percentage;
} scholarship_info_t;

typedef struct {
	char name[50];
	char surname[50];
	double scholarshipExamScore;
	int schoolFee;
	scholarship_info_t scholarship_info;
} student_t;

void readFromFile(FILE* file, student_t* students, int studentCount) {
	for (int i = 0; i < studentCount; i++) {
		fscanf(file, "%s %s %lf %c %d", (students + i)->name, (students + i)->surname, &(students + i)->scholarshipExamScore, &(students + i)->scholarship_info.type, &(students + i)->scholarship_info.degree);

		switch ((students + i)->scholarship_info.type)
		{
		case 'R':
			switch ((students + i)->scholarship_info.degree)
			{
			case 1:
				(students + i)->scholarship_info.percentage = 100;
				break;
			case 2:
				(students + i)->scholarship_info.percentage = 20;
			}
			break;
		case 'I':
			switch ((students + i)->scholarship_info.degree)
			{
			case 1:
				(students + i)->scholarship_info.percentage = 50;
				break;
			case 2:
				(students + i)->scholarship_info.percentage = 30;
				break;
			case 3:
				(students + i)->scholarship_info.percentage = 15;
			}
		}

		// EXTRA
		if ((students + i)->scholarshipExamScore >= 90)
			(students + i)->scholarship_info.percentage += 15;
		else if ((students + i)->scholarshipExamScore < 90 && (students + i)->scholarshipExamScore >= 70)
			(students + i)->scholarship_info.percentage += 10;
		else if ((students + i)->scholarshipExamScore < 70 && (students + i)->scholarshipExamScore >= 50)
			(students + i)->scholarship_info.percentage += 5;

		if ((students + i)->scholarship_info.percentage > 100)
			(students + i)->scholarship_info.percentage = 100;

		(students + i)->schoolFee = COLLEGE_FREE * (100 - (students + i)->scholarship_info.percentage) / 100.0;
	}
}

void displayReport(student_t* students, int studentCount) {
	printf("Student Name Surname \t Scholarship Exam Score \t Scholarship Type \t Percentage \t School Free\n");
	printf("-------------------- \t ---------------------- \t ---------------- \t  ---------- \t ----------\n");
	for (int i = 0; i < studentCount; i++)
		printf("%-10s %-10s \t %-10.2f \t\t\t\t %c \t\t %d \t\t\t %d\n", (students + i)->name,
			(students + i)->surname,
			(students + i)->scholarshipExamScore,
			(students + i)->scholarship_info.type,
			(students + i)->scholarship_info.percentage,
			(students + i)->schoolFee);
}

int main(void) {
	FILE* scholarshipFile = fopen("scholarship.txt", "r");
	student_t* students;

	if (scholarshipFile == NULL)
		printf("File could not be opened!");
	else {
		int studentCount;
		fscanf(scholarshipFile, "%d", &studentCount);
		students = (student_t*)malloc(studentCount * sizeof(student_t));
		readFromFile(scholarshipFile, students, studentCount);
		displayReport(students, studentCount);
	}

	return 0;
}