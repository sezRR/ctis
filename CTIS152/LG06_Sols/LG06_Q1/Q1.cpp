#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	char name[50];
	double unitGPA;
	int classLevel;

	double weightedGPA;
} stu_t;

int readFromFile(FILE* file, stu_t* students) {
	int studentCount = 0;
	while (fscanf(file, "%s %lf %d", (students + studentCount)->name, &(students + studentCount)->unitGPA, &(students + studentCount)->classLevel) != EOF)
		studentCount++;
	return studentCount;
}

void calculateWeightedGpa(stu_t* students, int numberOfStudents) {
	for (int i = 0; i < numberOfStudents; i++)
		(students + i)->weightedGPA = (students + i)->unitGPA * (students + i)->classLevel;
}

void calculateTotalWeightedGpa(stu_t* students, int numberOfStudents) 
{
	double sumUnitGPA = 0;
	for (int i = 0; i < numberOfStudents; i++)
		sumUnitGPA += (students + i)->weightedGPA;
	printf("\nThe total weighted GPA of all students: %.2f", sumUnitGPA);
}

int main(void) {
	FILE* studentsFile = fopen("students.txt", "r");
	stu_t students[4];
	int studentCount;

	if (studentsFile == NULL)
		printf("File could not be opened!");
	else {
		studentCount = readFromFile(studentsFile, students);


		printf("Student Name\tGPA\tClass Level\n");
		printf("-------------------------------------------------\n");
		for (int i = 0; i < studentCount; i++)
			printf("%s \t %.2f \t %d\n", (students + i)->name, (students + i)->unitGPA, (students + i)->classLevel);

		calculateWeightedGpa(students, studentCount);

		printf("\nStudent Name\tGPA\tClass Level\tWeightedGPA\n");
		printf("-------------------------------------------------\n");
		for (int i = 0; i < studentCount; i++)
			printf("%s \t %.2f \t %d \t %.2f\n", (students + i)->name, (students + i)->unitGPA, (students + i)->classLevel, (students + i)->unitGPA * (students + i)->classLevel);

		calculateTotalWeightedGpa(students, studentCount);
	}

	return 0;
}