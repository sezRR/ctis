#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char brand[30];
	int horsepower;
	char color[15];
	char bodyType[30];} car_t;

int main(void) {
	car_t car = { "GMC", 275, "white", "SUV" }, *carptr;
	carptr = &car;

	printf("The car information is:\n");
	printf("Brand: %s\n", carptr->brand);
	printf("Horse Power: %d\n", carptr->horsepower);
	printf("Color: %s\n", carptr->color);
	printf("Body Type: %s\n", carptr->bodyType);

	return 0;
}