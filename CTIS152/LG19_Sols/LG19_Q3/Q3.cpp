#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "linkedList_struct.h"

void displayList(node_t* head) {
	node_t* p = head;
	printf("List of ALL Runners\n");
	printf("Name \t Surname \t Age \t Country \t Score \n");
	printf("******* \t ******** \t *** \t ******* \t ***** \n");
	while (p != NULL) {
		runner_t t = p->data;
		printf("%s \t %s \t %d \t %s \t %d ->\n", t.name, t.surname, t.age, t.country, t.score);
		p = p->next;
	}
	printf("NULL\n");
}

node_t* createList(FILE* file) {
	node_t* headP = NULL, *p;
	runner_t r{};

	fscanf(file, "%s %s %d %s %d", r.name, r.surname, &r.age, r.country, &r.score);
	headP = addBeginning(headP, r);
	p = headP;
	while (fscanf(file, "%s %s %d %s %d", r.name, r.surname, &r.age, r.country, &r.score) != EOF)
	{
		addAfter(p, r);
		p = p->next;
	}
	return headP;
}

runner_t findGoldMedalWinner(node_t* head) {
	node_t* p = head;
	node_t* max = p;
	while (p != NULL)
	{
		if (max->data.score < p->data.score)
			max = p;
		p = p->next;
	}
	return max->data;
}

node_t* searchCountry(node_t* head, char* country) {
	node_t* p = head;
	while (p != NULL)
	{
		if (strcmp(p->data.country, country) == 0)
			return p;
		p = p->next;
	}
}

int main(void) {
	FILE* file = fopen("runners.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		node_t* headP = createList(file);
		displayList(headP);
		runner_t t = findGoldMedalWinner(headP);
		printf("The Gold Medal Goes to: %s %s, %d, %d, %d", t.name, t.surname, t.age, t.country, t.score);

		char country[STR_MAX] = "";
		printf("Enter a country to search: ");
		scanf("%s", country);

		node_t* res = searchCountry(headP, country);
		printf("%s", res->data.name);

		fclose(file);
	}

	return 0;
}