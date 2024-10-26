#define _CRT_SECURE_NO_WARNINGS

#define validate_menu_inp(choice) (choice < 1 || choice > 3)

#define COVID_DEPARTMENT_EXTRA_FEE 102.5 / 100

#include <stdio.h>
#include <stdlib.h>

enum DepartmentCode {
	COVID = 'C',
	OTHER = 'O',
};

enum WorkerType {
	DOCTOR = 'D',
	NURSE = 'N',
};

enum WorkerTypeExtraFee {
	OTHER_F = 55,
	DOCTOR_F = 100
};

typedef struct {
	char name[50];
	int id;
	DepartmentCode deptCode;
	WorkerType workerT;
	int extraHour;
	double extraFee;
} employee_t;

int menu() {
	int choice;
	do
	{
		printf("Menu:\n");
		printf("1. Calculate Extra Fee\n");
		printf("2. Display by Department\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		if (validate_menu_inp(choice))
			printf("Invalid Menu Item Choice, Re-Enter!\n\n");
	} while (validate_menu_inp(choice));

	return choice;
}

void readFile(FILE* file, employee_t* employees, int employeeCount) {
	for (int i = 0; i < employeeCount; i++)
	{
		char tempDeptChar, tempWorkerTypeChar;

		fscanf(file, "%s %d %c %c %d",
			(employees + i)->name,
			&(employees + i)->id,
			&tempDeptChar,
			&tempWorkerTypeChar,
			&(employees + i)->extraHour);

		(employees + i)->deptCode = (DepartmentCode)tempDeptChar;
		(employees + i)->workerT = (WorkerType)tempWorkerTypeChar;
		(employees + i)->extraFee = 0;
	}
}

void calculateExtraFee(employee_t* employees, int employeeCount) {
	for (int i = 0; i < employeeCount; i++)
	{
		(employees + i)->extraFee += (employees + i)->extraHour;
		if ((employees + i)->workerT == WorkerType::DOCTOR)
			(employees + i)->extraFee *= WorkerTypeExtraFee::DOCTOR_F;
		else
			(employees + i)->extraFee *= WorkerTypeExtraFee::OTHER_F;

		if ((employees + i)->deptCode == DepartmentCode::COVID)
			(employees + i)->extraFee *= COVID_DEPARTMENT_EXTRA_FEE;
	}
}

void displayDepartment(employee_t* employees, int employeeCount, DepartmentCode dpt) {
	printf("Name \t\t Id \t Dept \t Type \t Extra Hour \t Extra Fee \n");
	printf("----------------------------------------------------------------------\n");
	for (int i = 0; i < employeeCount; i++)
		if ((employees + i)->deptCode == dpt)
			printf("%s \t %d \t %c \t %c \t %d \t\t %.2f\n",
				(employees + i)->name,
				(employees + i)->id,
				(employees + i)->deptCode,
				(employees + i)->workerT,
				(employees + i)->extraHour,
				(employees + i)->extraFee);
	printf("\n");
}

int main(void) {
	FILE* file = fopen("healthEmployee.txt", "r");
	employee_t* employees;

	if (file == NULL)
		printf("File could not be opened!");
	{
		int employeeCount;
		fscanf(file, "%d", &employeeCount);
		employees = (employee_t*)malloc(employeeCount * sizeof(employee_t));
		readFile(file, employees, employeeCount);

		int choice = -1;
		while (choice != 3)
		{
			choice = menu();
			switch (choice)
			{
			case 1:
				calculateExtraFee(employees, employeeCount);
				printf("Extra Fees are calculated.\n\n");
				break;
			case 2:
				char dpt;
				printf("Enter Employee Department (C: Covid - O: Other): ");
				scanf(" %c", &dpt);
				displayDepartment(employees, employeeCount, (DepartmentCode)dpt);
			}
		}

		free(employees);
		fclose(file);
	}

	return 0;
}
