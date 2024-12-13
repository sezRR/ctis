#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	int englishProficiency, jury, graduateExam;
} grades_t;

typedef struct {
	int id;
	grades_t gr;
	double overall;
}applicantsOfII_t;

int readFile(FILE* file, applicantsOfII_t* arr) {
	int size = 0;
	applicantsOfII_t temp{ 0, 0, 0, 0, 0 };
	while (fscanf(file, "%d %d %d %d", &temp.id, &temp.gr.englishProficiency, &temp.gr.jury, &temp.gr.graduateExam) != EOF)
		arr[size++] = temp;
	return size;
}

void calculate(applicantsOfII_t* arr, int size) {
	for (int i = 0; i < size; i++)
		arr[i].overall = arr[i].gr.englishProficiency * 3 / 10.0
		+ arr[i].gr.graduateExam * 2 / 10.0
		+ arr[i].gr.jury * 5 / 10.0;;
}

void display(applicantsOfII_t* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("Applicant ID: %d\n", arr[i].id);
		printf("Scores:\n");
		printf("Applicant English Proficiency: %d\n", arr[i].gr.englishProficiency);
		printf("Applicant Jury: %d\n", arr[i].gr.jury);
		printf("Applicant Graduate Examination: %d\n", arr[i].gr.graduateExam);
		printf("Applicant Overall: %.1f\n\n", arr[i].overall);
	}
}

void findPassFail(applicantsOfII_t* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i].overall;

	double avg = sum / (size);

	int fail = 0;
	for (int i = 0; i < size; i++)
		if (arr[i].overall < avg)
			fail++;

	printf("Average is %.1f\n", avg);
	printf("Number of the applications who pass is %d\n", size - fail);
	printf("Number of the applications who fail is %d", fail);
}

int main(void) {
	FILE* file = fopen("applicants.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		applicantsOfII_t arr[10]{};
		int size = readFile(file, arr);

		calculate(arr, size);
		display(arr, size);
		findPassFail(arr, size);

		fclose(file);
	}

	return 0;
}