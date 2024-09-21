#define _CRT_SECURE_NO_WARNINGS

#define FIX_PRICE 400
#define DISCOUNTED_PERCENTAGE_4_UNDER_AGE .45
#define DISCOUNTED_PERCENTAGE_4_AND_OLDER_AGE .35

#include <stdio.h>

int main(void)
{
	int applicantCount, applicantAge;
	double discountedPercentage = 0, applicantPrice = FIX_PRICE;
	char applicantGenger, parentStatus;

	printf("Enter the number of applicants for kindergarten: ");
	scanf("%d", &applicantCount);

	for (int i = 1; i <= applicantCount; i++)
	{
		applicantPrice = FIX_PRICE;
		discountedPercentage = 0;

		printf("\nEnter %d. applicant gender and age: ", i);
		scanf(" %c %d", &applicantGenger, &applicantAge);

		printf("Enter %d. applicant parent status(Staff / NOT Staff) (S / Any other char): ", i);
		scanf(" %c", &parentStatus);

		switch (parentStatus)
		{
		case 'S':
		case 's':
			if (applicantAge < 4)
			{
				discountedPercentage += 1 - DISCOUNTED_PERCENTAGE_4_UNDER_AGE;
			}
			else if (applicantAge >= 4)
			{
				discountedPercentage += 1 - DISCOUNTED_PERCENTAGE_4_AND_OLDER_AGE;
			}

			if (discountedPercentage != 0)
			{
				applicantPrice *= discountedPercentage;
			}
			break;
		default:
			break;
		}

		printf("Applicant price is %.2f TL\n", applicantPrice);
	}
}