#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct.h"

node_t* createList(FILE* file) {
	node_t* p = NULL, *headP = NULL;
	login_t temp{};
	fscanf(file, "%[^,],%[^,],%[^\n]\n", temp.userName, temp.city, temp.lastLogin);
	headP = addBeginning(headP, temp);
	p = headP;
	while (fscanf(file, "%[^,],%[^,],%[^\n]\n", temp.userName, temp.city, temp.lastLogin) != EOF)
	{
		addAfter(p, temp);
		p = p->next;
	}
	return headP;
}

int searchForAUser(node_t* headP, char* username, login_t* res, int* len) {
	node_t* p = headP;
	int i = 0;
	while (p != NULL)
	{
		if (strcmp(p->data.userName, username) == 0)
			res[i++] = p->data;
		p = p->next;
	}
	*len = i;
	return i != 0;
}

node_t* deleteUserLogins(node_t* headP, char* username) {
	node_t* p = NULL;
	while (strcmp(headP->data.userName, username) == 0)
		headP = deleteFirst(headP);
	p = headP;
	while (p != NULL)
	{
		if (strcmp(p->next->data.userName, username) == 0)
			deleteAfter(p);
		p = p->next;
	}
	return headP;
}

int main(void) {
	FILE* file = fopen("alert.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		node_t* headP = createList(file);

		printf("Login information for the users who may have suspicious activities:\n");
		displayList(headP);

		char username[SIZE] = "";
		printf("\nPlease enter your account name to see the login history: ");
		scanf("%s", username);
		login_t resLogin[SIZE]{};
		int len = 0;
		int res = searchForAUser(headP, username, resLogin, &len);
		if (res == 0)
			printf("There is no account with the name tony!");
		else {
			for (int i = 0; i < len; i++)
				printf("%-15s %-15s %-15s ->\n", resLogin[i].userName, resLogin[i].city, resLogin[i].lastLogin);

			char isSus;
			printf("Is there any suspicious activity? (y/n): ");
			scanf(" %c", &isSus);
			printf("** All the login info will be deleted **\n");
			if (isSus == 'n')
			{
				headP = deleteUserLogins(headP, username);
				printf("Login history updated!\n");
				displayList(headP);
			}
		}

		fclose(file);
	}

	return 0;
}