#define _CRT_SECURE_NO_WARNINGS

#define MAIL_EXTENSION "@abc.com.tr"

#include <stdio.h>
#include <string.h>

typedef struct {
	char name[50];
	char surname[50];
} employee_t;

void convertLower(char* str) {
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
}

int main(void) {
	FILE* workerFile = fopen("worker.txt", "r"), *mailsFile = fopen("mails.txt", "w");
	if (workerFile == NULL || mailsFile == NULL)
		printf("File(s) could not be opened!");
	else {
		employee_t employees[50]{};
		int employeeCounter = 0;
		while (fscanf(workerFile, "%s %s", employees[employeeCounter].name, (employees + employeeCounter)->surname) != EOF)
			employeeCounter++;
		
		for (int i = 0; i < employeeCounter; i++)
		{
			char tempStr[50] = "";

			convertLower(employees[i].surname);
			strcpy(tempStr, employees[i].surname);
			strncat(tempStr, employees[i].name, 1);
			strcat(tempStr, MAIL_EXTENSION);

			fprintf(mailsFile, "%s\n", tempStr);
		}

		fclose(workerFile);
	}
	return 0;
}