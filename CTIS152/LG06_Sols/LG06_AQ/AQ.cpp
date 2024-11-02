#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int englishProficiency, jury, graduateExam;
} grades_t;

typedef struct {
	int id;
	double overall;
	grades_t gr;
} applicantsOfII_t;

int readFile(FILE* file, applicantsOfII_t* applicants) {
	int size = 0;
	while (fscanf(file, "%d %d %d %d", &(applicants + size)->id, &(applicants + size)->gr.englishProficiency, &(applicants + size)->gr.jury, &(applicants + size)->gr.graduateExam) != EOF)
	{
		(applicants + size)->overall = 0;
		size++;
	}
	return size;
}

void calculate(applicantsOfII_t* applicants, int nmbApplicants, double* avgAll) {
	for (int i = 0; i < nmbApplicants; i++)
	{
		(applicants + i)->overall += (applicants + i)->gr.englishProficiency * (0.3);
		(applicants + i)->overall += (applicants + i)->gr.jury * (0.5);
		(applicants + i)->overall += (applicants + i)->gr.graduateExam * (0.2);
		*avgAll += (applicants + i)->overall;
	}
	*avgAll /= nmbApplicants;
}

void display(applicantsOfII_t* applicants, int nmbApplicants) {

	for (int i = 0; i < nmbApplicants; i++)
	{
		printf("Applicant ID: %d\n\n", (applicants + i)->id);
		printf("Scores:\n");
		printf("Applicant English Proficiency: %d\n", (applicants + i)->gr.englishProficiency);
		printf("Applicant Jury: %d\n", (applicants + i)->gr.jury);
		printf("Applicant Graduate Exam: %d\n", (applicants + i)->gr.graduateExam);
		printf("Applicant Overall: %.1lf\n\n", (applicants + i)->overall);
	}
}

void findPassFail(applicantsOfII_t* applicants, int nmbApplicants, double avgAll) {
	int pass = 0, fail = 0;
	for (int i = 0; i < nmbApplicants; i++)
		if ((applicants + i)->overall >= avgAll)
			pass++;
		else
			fail++;

	printf("Average is %.1f\n", avgAll);
	printf("Number of the applicants who pass is: %d\n", pass);
	printf("Number of the applicants who fail is: %d\n", fail);
}

int main(void) {
	FILE* file = fopen("applicants.txt", "r");
	applicantsOfII_t applicants[100];

	if (file == NULL)
		printf("File could not be opened!");
	else {
		int size = readFile(file, applicants);
		double avg = 0;
		calculate(applicants, size, &avg);
		display(applicants, size);
		findPassFail(applicants, size, avg);
	}

	return 0;
}