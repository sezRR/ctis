#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "stack_struct.h"

int menu() {
	int choice;
	do
	{
		printf("MENU\n************************\n");
		printf("1. Display all of the jobs\n");
		printf("2. Complete the Project\n");
		printf("3. Add a new project\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 4);
	return choice;
}

void projectsToStack(FILE* projectsBin, stack_t* s) {
	project_t p{};
	while (fread(&p, sizeof(project_t), 1, projectsBin) == 1)
		push(s, p);
	fclose(projectsBin);
}

/*
	RETURNS:
		0 -> No ERROR
		1 -> ERROR
*/
int display(FILE* teamsBin, stack_t s) {
	team_t t{};
	project_t p{};
	while (!isEmptyS(&s))
	{
		p = pop(&s);
		printf("\nProject: %s, profit: %.2f TL\n", p.name, p.profit);
		for (int i = 0; i < MAX_TEAM; i++)
		{
			int toLocate = p.teamCodes[i] - TEAM_CODE_PREFIX;
			fseek(teamsBin, toLocate * sizeof(team_t), SEEK_SET);
			if (fread(&t, sizeof(team_t), 1, teamsBin) != 1)
				return 1;
			printf("\t%d %-12s \t %s\n", t.code, t.name, t.project);
		}
		printf("***************************************************\n");
	}
	printf("\n");
	return 0;
}

/*
	RETURNS:
		0 -> NOT DELETED
		1 -> DELETED
*/
int completeProject(stack_t* s, char* projectName) {
	stack_t temp;
	project_t p{ "", 0, {} }, res{};
	bool isFound = 0;

	initializeS(&temp);
	while (!isEmptyS(s))
	{
		p = pop(s);
		if (strcmp(p.name, projectName) == 0) {
			res = p;
			isFound = 1;
		}
		else
			push(&temp, p);
	}

	while (!isEmptyS(&temp))
		push(s, pop(&temp));

	if (!isFound)
	{
		printf("There is NO project belonging to the %s\n\n", projectName);
		return 0;
	}

	printf("\nCongratulations :)\n");
	printf("You finished the %s's project.\n", projectName);
	printf("You will get %.2f TL profit from this project.\n\n", res.profit);
}

void addNewProject(stack_t* s) {
	project_t p{};

	printf("\nEnter the project name: ");
	scanf("%s", p.name);

	printf("Enter the profit: ");
	scanf("%lf", &p.profit);

	printf("Enter %d team codes: ", MAX_TEAM);
	for (int i = 0; i < MAX_TEAM; i++)
		scanf("%d", &p.teamCodes[i]);
	
	push(s, p);
	printf("\nNew Job is added to the list.\n\n");
}

int main(void) {
	FILE* teamsBin = fopen("teams.bin", "rb"), * projectsBin = fopen("projects.bin", "rb");

	if (teamsBin == NULL || projectsBin == NULL) {

		printf("File(s) could not be opened!");
		return 1;
	}

	stack_t s;
	initializeS(&s);
	projectsToStack(projectsBin, &s);

	while (1)
	{
		int choice = menu();
		if (choice == 4)
			break;

		switch (choice)
		{
		case 1:
			display(teamsBin, s);
			break;
		case 2:
			char project[MAX_STR_SIZE];
			printf("\nEnter the project name to complete: ");
			scanf("%s", project);
			completeProject(&s, project);
			break;
		case 3:
			addNewProject(&s);
			break;
		}
	}

	fclose(projectsBin);

	return 0;
}