#define _CRT_SECURE_NO_WARNINGS

#define MAX 20

#define COMMAND_PUSH "Push"
#define COMMAND_POP "Pop"
#define COMMAND_DISPLAY "Display"

#include <stdio.h>
#include <string.h>
#include "stack_struct.h"

void display(stack_t s);

int main(void) {
	FILE* commandsFile = fopen("commands.txt", "r");
	if (commandsFile == NULL)
		printf("File could not be opened!");
	else {
		stack_t s;
		initializeS(&s);
		char command[MAX] = "";
		person_t tempPerson{};

		while (fscanf(commandsFile, "%s", command) != EOF)
		{
			if (strcmp(command, COMMAND_PUSH) == 0)
				if (fscanf(commandsFile, "%s %d", tempPerson.name, &tempPerson.age) == 2)
					push(&s, tempPerson);
				else {
					printf("Something went wrong while reading the file, exiting...");
					return 1;
				}
			else if (strcmp(command, COMMAND_POP) == 0) {
				tempPerson = pop(&s);
				if (tempPerson.age != 0)
					printf("%s and %d is removed from the stack\n", tempPerson.name, tempPerson.age);
			}
			else if (strcmp(command, COMMAND_DISPLAY) == 0)
				display(s);
		}

		fclose(commandsFile);
	}
	
	return 0;
}

void display(stack_t s) {
	printf("\nStack content is\n");
	while (!isEmptyS(&s))
	{
		person_t tempPerson = pop(&s);
		printf("%-4s \t %d\n", tempPerson.name, tempPerson.age);
	}
	printf("\n");
}
