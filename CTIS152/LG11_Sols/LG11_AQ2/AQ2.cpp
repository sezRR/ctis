#define _CRT_SECURE_NO_WARNINGS

#define PRIVATE_HEALTH_INSURANCE_FAMILY 194
#define PRIVATE_HEALTH_INSURANCE_INDIVIDUAL 97

#define OTOBES_OF_GROSS_SALARY 0.03

#define MAX 50

#include <stdio.h>
#include <string.h>

typedef struct {
	char healthInsurance[MAX]; // FAMILY - INDIVIDUAL - NONE
	char otoBes; // Y - N
	int contrPercentageSGK;
} stoppage_details_t;

typedef struct {
	int ssn;
	char name[MAX];
	char surname[MAX];
	double grossSalary;
	double netSalary;
	stoppage_details_t stoppageDetails;
} employee_t;

int readEmpInfo(FILE* file, employee_t* employees) {
	int employeeCount = 0;
	while (fscanf(file, "%d %s %s %lf %s %s %d",
		&(employees + employeeCount)->ssn,
		(employees + employeeCount)->name,
		(employees + employeeCount)->surname,
		&(employees + employeeCount)->grossSalary,
		&(employees + employeeCount)->stoppageDetails.healthInsurance,
		&(employees + employeeCount)->stoppageDetails.otoBes,
		&(employees + employeeCount)->stoppageDetails.contrPercentageSGK) != EOF)
	{
		employees[employeeCount].netSalary = employees[employeeCount].grossSalary;
		employeeCount++;
	}

	return employeeCount;
}

void displayEmpInfo(employee_t* employees, int employeeCount) {
	printf("SSN \t NAME \t SURNAME \t Health Ins \t BES \t SGK \t GrossSalary \t NET Payment\n");
	printf("*** \t **** \t ******* \t ********** \t *** \t *** \t *********** \t ***********\n");
	for (int i = 0; i < employeeCount; i++)
		printf("%d \t %s \t %-7s \t %-7s \t %c \t %%%d \t  %.2f TL \t %.2f TL \n",
			employees[i].ssn,
			employees[i].name,
			employees[i].surname,
			employees[i].stoppageDetails.healthInsurance,
			employees[i].stoppageDetails.otoBes,
			employees[i].stoppageDetails.contrPercentageSGK,
			employees[i].grossSalary,
			employees[i].netSalary);
}

void swap(employee_t* employee1, employee_t* employee2) {
	employee_t tempEmployee = *employee1;
	*employee1 = *employee2;
	*employee2 = tempEmployee;
}

void bubbleSort(employee_t* employees, int employeeCount) {
	int sorted = 0,
		progress = 1;
	do
	{
		sorted = 1;
		for (int i = 0; i < employeeCount - progress; i++)
		{
			if (strcmp(employees[i].surname, employees[i + 1].surname) > 0)
			{
				swap(&employees[i], &employees[i + 1]);
				sorted = 0;
			}
		}
		progress++;
	} while (!sorted);
}

void calcNetSalary(employee_t* employees, int employeeCount) {
	for (int i = 0; i < employeeCount; i++)
	{
		if (strcmp(employees[i].stoppageDetails.healthInsurance, "family") == 0)
			employees[i].netSalary -= PRIVATE_HEALTH_INSURANCE_FAMILY;
		else if (strcmp(employees[i].stoppageDetails.healthInsurance, "individual") == 0)
			employees[i].netSalary -= PRIVATE_HEALTH_INSURANCE_INDIVIDUAL;

		if (employees[i].stoppageDetails.otoBes == 'Y')
			employees[i].netSalary -= employees[i].grossSalary * OTOBES_OF_GROSS_SALARY;

		employees[i].netSalary -= employees[i].grossSalary * (employees[i].stoppageDetails.contrPercentageSGK / 100.0);
	}
}

int main(void) {
	FILE* file = fopen("employee.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		employee_t employees[MAX]{};
		int employeeCount = readEmpInfo(file, employees);
		calcNetSalary(employees, employeeCount);
		bubbleSort(employees, employeeCount);
		displayEmpInfo(employees, employeeCount);
		fclose(file);
	}

	return 0;
}