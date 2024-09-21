#define _CRT_SECURE_NO_WARNINGS

#define ONE_YEAR_DAYS 365
#define ONE_MONTH_DAYS 30

#include <stdio.h>

void convertDays(int* year, int* month, int* days)
{
	int reminder = *days % ONE_YEAR_DAYS;

	*year = *days / ONE_YEAR_DAYS;
	*days -= *year * ONE_YEAR_DAYS;

	if (reminder != 0)
	{
		*month = reminder / ONE_MONTH_DAYS;
		*days -= *month * ONE_MONTH_DAYS;
	}
}

int main(void)
{
	// Define variables
	int year = 0, month = 0, days = 0, oldDays = 0;

	// Get inputs from the user
	while (1)
	{
		printf("Enter the number of days: ");
		scanf("%d", &days);

		if (days == -1)
			break;

		oldDays = days;
		convertDays(&year, &month, &days);
		printf("%d days is %d year(s), %d month(s), %d day(s)\n\n", oldDays, year, month, days);
	}

	return 0;
}
