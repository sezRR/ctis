#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int founded;
	int monitored_count;
} company_info_t;

typedef struct {
	char name[50];
	char product_type[50];
	company_info_t company;
} agency_t;

void readFromFile(FILE* file, agency_t* agencies, int numberOfAgency) {
	for (int i = 0; i < numberOfAgency; i++)
		fscanf(file, "%s %s %s %d %d",
			(agencies + i)->name, 
			(agencies + i)->product_type, 
			(agencies + i)->company.name,
			&(agencies + i)->company.founded,
			&(agencies + i)->company.monitored_count);
}

void displayAllViews(agency_t* agencies, int numberOfAgency) {
	for (int i = 0; i < numberOfAgency; i++)
	{
		printf("From the Agency %s, %s (%s) founded in %d Views ",
			(agencies + i)->name,
			(agencies + i)->company.name,
			(agencies + i)->product_type,
			(agencies + i)->company.founded
		);

		double calculation;
		if ((agencies + i)->company.monitored_count < 1000)
			printf("%d", (agencies + i)->company.monitored_count);
		else if ((agencies + i)->company.monitored_count < 1000000) {
			calculation = (agencies + i)->company.monitored_count / 1000.0;
			printf("%.1f K", calculation);
		}
		else {
			calculation = (agencies + i)->company.monitored_count / 1000000.0;
			printf("%.1f M", calculation);
		}

		printf("\n\n");
	}
}

int findMaxMonitoredIndex(agency_t* agencies, int numberOfAgency) {
	int maxMonitoredIndex = 0;
	for (int i = 1; i < numberOfAgency; i++)
		if ((agencies + i)->company.monitored_count > (agencies + maxMonitoredIndex)->company.monitored_count)
			maxMonitoredIndex = i;
	return maxMonitoredIndex;
}

int main(void) {
	FILE* adCompaniesFile = fopen("adCompanies.txt", "r");
	agency_t* agencies;

	if (adCompaniesFile == NULL)
		printf("File could not be opened!");
	else {
		int agencyCount;
		fscanf(adCompaniesFile, "%d", &agencyCount);

		agencies = (agency_t*)malloc(agencyCount * sizeof(agency_t));

		readFromFile(adCompaniesFile, agencies, agencyCount);
		displayAllViews(agencies, agencyCount);
		int maxMonitoredIndex = findMaxMonitoredIndex(agencies, agencyCount);

		printf("The winner of the competition is -> %s", (agencies + maxMonitoredIndex)->company.name);
		fclose(adCompaniesFile);
	}
	
	return 0;
}