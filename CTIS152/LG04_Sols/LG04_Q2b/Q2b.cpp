#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	char brand[30];
	int horsepower;
	char color[15];
	char bodyType[30];} car_t;

int main(void) {
	car_t car;

	printf("Enter the information of the car:\n");
	printf("Brand: ");
	scanf("%s", &car.brand);
	printf("Horse Power: ");
	scanf("%d", &car.horsepower);
	printf("Color: ");
	scanf("%s", &car.color);
	printf("Body Type: ");
	scanf("%s", &car.bodyType);

	printf("\nThe car information is:\n");
	printf("Brand: %s\n", car.brand);
	printf("Horse Power: %d\n", car.horsepower);
	printf("Color: %s\n", car.color);
	printf("Body Type: %s\n", car.bodyType);

	return 0;
}