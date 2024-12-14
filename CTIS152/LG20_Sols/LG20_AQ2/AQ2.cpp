#define _CRT_SECURE_NO_WARNINGS

#define STR_MAX 50

#include <stdio.h>
#include <stdlib.h>
#include "linkedList_struct.h"

int readInfoFromFile(FILE* file, LType* temp) {
	return fscanf(file, "%d %s %lf", &temp->id, temp->name, &temp->price) != EOF;
}

node_t* createList(FILE* file) {
	node_t* headP = NULL, * p = NULL;

	LType temp{};
	if (!readInfoFromFile(file, &temp))
		return NULL;

	headP = addBeginning(headP, temp);
	p = headP;

	while (readInfoFromFile(file, &temp))
	{
		addAfter(p, temp);
		p = p->next;
	}

	fclose(file);

	return headP;
}

void displayListElement(node_t* node) {
	printf("%d \t %-7s \t %.2f\n", node->data.id, node->data.name, node->data.price);
}

void displayList(node_t* headP) {
	printf("\nId \t Name \t\t Price \n");
	printf("------------------------------\n");
	while (headP != NULL)
	{
		displayListElement(headP);
		headP = headP->next;
	}
}

int menu() {
	int choice;

	printf("\nMENU\n");
	printf("----------------\n");
	printf("1. Add Record\n");
	printf("2. Update Record\n");
	printf("3. Exit\n");
	do
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 3);

	return choice;
}

node_t* addToEnd(node_t* headP, LType item) {
	node_t* p = headP;
	while (p->next != NULL)
		p = p->next;

	addAfter(p, item);
	return headP;
}

node_t* searchNode(node_t* headP, int id) {
	while (headP != NULL)
	{
		if (headP->data.id == id)
			return headP;
		headP = headP->next;
	}

	return NULL;
}

LType createNewVegetable(node_t* headP) {
	LType vegetable{};

	node_t* searchRes = NULL;
	do
	{
		printf("\nEnter vegetable Id: ");
		scanf("%d", &vegetable.id);

		searchRes = searchNode(headP, vegetable.id);
		if (searchRes != NULL)
			printf("The Id: %d is already exists!\n", vegetable.id);
	} while (searchRes != NULL);

	printf("Enter vegetable name: ");
	scanf("%s", vegetable.name);

	printf("Enter vegetable price: ");
	scanf("%lf", &vegetable.price);

	return vegetable;
}

void updateList(node_t* headP) {
	int id;
	printf("\nEnter vegetable Id: ");
	scanf("%d", &id);

	node_t* searchRes = searchNode(headP, id);
	if (searchRes == NULL)
	{
		printf("There is no vegetable in the list, with the id <%d>!\n", id);
		return;
	}

	displayListElement(searchRes);

	int field;
	printf("\nUpdate (1. Id, 2. Name, 3. Price): ");
	scanf("%d", &field);

	switch (field)
	{
	case 1:
		printf("Enter the new Id: ");
		scanf("%d", &searchRes->data.id);
		break;
	case 2:
		printf("Enter the new name: ");
		scanf("%s", searchRes->data.name);
		break;
	case 3:
		printf("Enter the new price: ");
		scanf("%lf", &searchRes->data.price);
	}
}

void writeList(const char* fileName, node_t* headP) {
	FILE* binFile = fopen(fileName, "wb");
	if (binFile == NULL)
		printf("File could not be created!");
	else {
		while (headP != NULL)
		{
			fwrite(&headP->data, sizeof(vegetable_t), 1, binFile);
			headP = headP->next;
		}

		fclose(binFile);
	}
}

int main(void) {
	FILE* file = NULL;
	char fileName[STR_MAX] = "";

	do
	{
		printf("Enter the text file name: ");
		scanf("%s", fileName);

		file = fopen(fileName, "r");
	} while (file == NULL);

	node_t* headP = createList(file);

	while (1)
	{
		displayList(headP);
		int menuChoice = menu();
		if (menuChoice == 3)
			break;

		switch (menuChoice)
		{
		case 1:
			addToEnd(headP, createNewVegetable(headP));
			break;
		case 2:
			updateList(headP);
		}
	}

	printf("\nWriting linkedlist to binary file 'vegandfruit.bin'\n");
	writeList("vegandfruit.bin", headP);
	printf("Goodbye");

	return 0;
}