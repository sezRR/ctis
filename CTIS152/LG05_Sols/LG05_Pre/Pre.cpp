
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char brand[30];
	int horsepower;
	char color[15];
	char bodyType[30];
} car_t;

int main(void)
{
	FILE* carFile = fopen("cars.txt", "r");
	car_t* car;
	int count;

	if (carFile == NULL)
		printf("The file flowers.txt couldn't be opened.\n");
	else
	{
		fscanf(carFile, "%d", &count);

		car = (car_t*)malloc(count * sizeof(car_t));

		printf("There are %d cars.\n\n", count);

		for (int i = 0; i < count; i++)
			fscanf(carFile, "%s %d %s %s", (car + i)->brand, &(car + i)->horsepower, (car + i)->color, (car + i)->bodyType);

		printf("\nThe car information is:\n");
		printf("*********************\n");

		for (int i = 0; i < count; i++)
		{
			printf("Brand: %s\n", (car + i)->brand);
			printf("Horse Power: %d\n", (car + i)->horsepower);
			printf("Color: %s\n", (car + i)->color);
			printf("Body Type: %s\n", (car + i)->bodyType);
			printf("***********************\n");
		}

		fclose(carFile);
		free(car);
	}

	return 0;
}
