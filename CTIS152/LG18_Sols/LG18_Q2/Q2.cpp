#define _CRT_SECURE_NO_WARNINGS

#define MAX_PRODUCTS 100

#include <stdio.h>
#include "queue_int.h"
#include "stack_int.h"

typedef struct {
	int id;
	double price;
	int stock;
} product_t;


int getIndex(int id) {
	return id / 111 - 1;
}

void displayQueue(queue_t q, product_t* products) {
	printf("Queue contents:\n");
	while (!isEmptyQ(&q))
	{
		int id = remove(&q);
		int index = getIndex(id);
		printf("%d %.2f %d\n", id, products[index].price, products[index].stock);
	}
}

void displayStack(stack_t s, product_t* products) {
	while (!isEmptyS(&s))
	{
		int id = pop(&s);
		int index = getIndex(id);
		printf("%d %.2f %d\n", id, products[index].price, products[index].stock);
	}
}


int main(void) {
	FILE* file = fopen("items.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		product_t products[MAX_PRODUCTS];

		queue_t q;
		stack_t s;

		initializeQ(&q);
		initializeS(&s);

		int i = 0;
		while (fscanf(file, "%d %lf %d", &products[i].id, &products[i].price, &products[i].stock) != EOF)
		{
			if (products[i].stock < 100)
				insert(&q, products[i].id);
			else
				push(&s, products[i].id);
			i++;
		}

		displayQueue(q, products);

		printf("\nStack contents:\n");
		displayStack(s, products);

		while (!isEmptyQ(&q))
		{
			int id = remove(&q);
			int index = getIndex(id);
			product_t product = products[index];

			int minStock = 100 - product.stock;
			int stockToAdd;
			do
			{
				printf("Enter the purchase amount for item %d (min %d): ", id, minStock);
				scanf("%d", &stockToAdd);
				if (minStock > stockToAdd)
					printf("Wrong Input!\n");
			} while (minStock > stockToAdd);

			product.stock += stockToAdd;
			push(&s, id);
		}

		printf("\nStack contents after purchases:\n");
		displayStack(s, products);

		fclose(file);
	}
	return 0;
}
