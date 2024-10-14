#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int batteryScore;
	int cameraScore;
	int performanceScore;
	double overallScore;
} phone_score;

typedef struct {
	char brand[50];
	char model[50];
	phone_score scores;
} phone_t;

void readFromFile(FILE* file, phone_t* phones, int phoneCount) {
	for (int i = 0; i < phoneCount; i++)
	{
		fscanf(file, "%s %s %d %d %d",
			(phones + i)->brand,
			(phones + i)->model,
			&(phones + i)->scores.batteryScore,
			&(phones + i)->scores.cameraScore,
			&(phones + i)->scores.performanceScore);

		(phones + i)->scores.overallScore = (phones + i)->scores.batteryScore * (25 / 100.0) + (phones + i)->scores.cameraScore * (40 / 100.0) + (phones + i)->scores.performanceScore * (35 / 100.0);
	}
}

void displayReport(phone_t* phones, int phoneCount) {
	printf("Brand\tModel\tBattery\tCamera\tPerformance\tOverall Score\n");
	printf("------------------\t------------------\t-------\t-----------\t-----------\t --------------\n");
	for (int i = 0; i < phoneCount; i++)
		printf("%s \t %s \t %d \t %d \t %d \t %.2f\n", (phones + i)->brand, (phones + i)->model, (phones + i)->scores.batteryScore, (phones + i)->scores.cameraScore, (phones + i)->scores.performanceScore, (phones + i)->scores.overallScore);
}

int main(void) {
	FILE* smartphonesFile = fopen("smartphones.txt", "r");
	phone_t* phones;

	if (smartphonesFile == NULL)
		printf("File could not be opened!");
	else {
		int phoneCount;
		fscanf(smartphonesFile, "%d", &phoneCount);
		phones = (phone_t*)malloc(phoneCount * sizeof(phone_t));

		readFromFile(smartphonesFile, phones, phoneCount);
		displayReport(phones, phoneCount);
	}

	return 0;
}