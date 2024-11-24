#define _CRT_SECURE_NO_WARNINGS

#define MAX_SHELF 3
#define SHELF_CAPACITY 10

#include <stdio.h>
#include <string.h>

typedef struct {
	char name[50];
	char ISBN[16];
	char author[50];
	char publishedYear[50];
	int shelfNo;
} book_t;

typedef struct {
	int shelfNumber;
	char index[50];
	int numberOfBooks;
	book_t books[SHELF_CAPACITY];
} shelf_t;

void swap(book_t* b1, book_t* b2) {
	book_t temp = *b1;
	*b1 = *b2;
	*b2 = temp;
}

void bubbleSort(book_t* books, int arrLen, int progress, int sorted = 0) {
	if (sorted)
		return;
	
	sorted = 1;

	for (int i = 0; i < arrLen - progress; i++)
		if (strcmp(books[i].name, books[i + 1].name) > 0)
		{
			swap(&books[i], &books[i + 1]);
			sorted = 0;
		}

	bubbleSort(books, arrLen, progress++, sorted);
}

void makeIndex(shelf_t* shelfs) {
	for (int i = 0; i < MAX_SHELF; i++)
	{
		shelfs[i].shelfNumber = i + 1;
		for (int j = 0; j < shelfs[i].numberOfBooks; j++)
		{
			char shelfIndex[50] = "";
			shelfIndex[0] = shelfs[i].books[0].name[0];
			shelfIndex[1] = '-';
			shelfIndex[2] = shelfs[i].books[shelfs[i].numberOfBooks - 1].name[0];
			shelfIndex[3] = ';';

			strncpy(shelfIndex + 4, shelfs[i].books[0].ISBN, 4);
			strcat(shelfIndex, "-");
			strncpy(shelfIndex + 9, shelfs[i].books[shelfs[i].numberOfBooks - 1].ISBN, 4);

			strcpy(shelfs[i].index, shelfIndex);
		}
	}
}

int main(void) {
	FILE* file = fopen("books.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		book_t books[50];
		shelf_t shelfs[MAX_SHELF]{ {0} };

		int i = 0;
		while (fscanf(file, "%d %[^0-9] %s %[^0-9] %d", 
			&books[i].shelfNo,
			books[i].name,
			books[i].ISBN,
			books[i].author,
			&books[i].publishedYear) != EOF)
		{
			i++;
		}

		bubbleSort(books, i + 1, 1, 0);

		for (int j = 0; j < i; j++)
		{
			shelfs[books[j].shelfNo - 1].books[shelfs[books[j].shelfNo - 1].numberOfBooks] = books[j];
			shelfs[books[j].shelfNo - 1].numberOfBooks++;
		}

		makeIndex(shelfs);

		printf("Contents of ALL Shelves\n*********************************************\n");
		for (int i = 0; i < MAX_SHELF; i++)
		{
			printf("Shelf No: %d\n", shelfs[i].shelfNumber);
			for (int j = 0; j < shelfs[i].numberOfBooks; j++)
				printf("%s \t %s \n", shelfs[i].books[j].name, shelfs[i].books[j].ISBN);
			printf("Index of %d. Shelf: %s", shelfs[i].shelfNumber, shelfs[i].index);
			printf("---------------------------------------------\n");
		}

		fclose(file);
	}
	return 0;
}