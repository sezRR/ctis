#define _CRT_SECURE_NO_WARNINGS

#define DIESEL_PER_L 43.44
#define FUEL_PER_L 42.71


#define CAR_TYPE_DIESEL 'D'
#define CAR_TYPE_FUEL 'F'

#include <stdio.h>
#include "queue_struct.h"

void calculatePayment(car_t* c) {
	switch (c->fuelType)
	{
	case 'D':
		c->payment = c->liter * DIESEL_PER_L;
		break;
	case 'F':
		c->payment = c->liter * FUEL_PER_L;
	}
}

void fillQueue(FILE* file, queue_t* q) {
	car_t temp;
	while (fscanf(file, "%s %c %lf", temp.carPlate, &temp.fuelType, &temp.liter) != EOF)
	{
		calculatePayment(&temp);
		insert(q, temp);
	}
}

void dailyReport(queue_t q) {
	double totalLiterSold = 0;
	double totalPayment = 0;

	printf("Plate \t\t FuelType \t Liter \t Payment\n");
	printf("********* \t ******** \t ***** \t **********\n");
	while (!isEmptyQ(&q))
	{
		car_t temp = remove(&q);

		totalLiterSold += temp.liter;
		totalPayment += temp.payment;

		printf("%-7s \t %-7c \t %.2f \t %.2f TL\n", temp.carPlate, temp.fuelType, temp.liter, temp.payment);
	}

	printf("\nTotal liter sold: %.2f\n", totalLiterSold);
	printf("Total payment: %.2f TL", totalPayment);
}

int main(void) {
	FILE* file = fopen("customers.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		queue_t q;
		initializeQ(&q);

		fillQueue(file, &q);
		dailyReport(q);

		fclose(file);
	}
	
	return 0;
}