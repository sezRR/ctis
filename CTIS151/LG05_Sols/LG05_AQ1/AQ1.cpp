/* LB05_AQ1 -> Purpose of the Program is Finding to Income of the Company
   with using logic statements. */

#define _CRT_SECURE_NO_WARNINGS

#define SALES_CATERING_GREATER_AND_EQUALS_TO_40K_INCOME 375
#define SALES_CATERING_GREATER_AND_EQUALS_TO_40K_SALES_PERCENTAGE .16

#define SALES_CATERING_LESS_THAN_40K_INCOME 350
#define SALES_CATERING_LESS_THAN_40K_SALES_PERCENTAGE .14

#define SALES_MEDICAL_GREATER_AND_EQUALS_TO_25K_INCOME 325
#define SALES_MEDICAL_GREATER_AND_EQUALS_TO_25K_SALES_PERCENTAGE .12

#define SALES_MEDICAL_LESS_THAN_25K_INCOME 300
#define SALES_MEDICAL_LESS_THAN_25K_SALES_PERCENTAGE .09

#include <stdio.h>

int main(void)
{
	// Define variables
	char companyType;
	int salesOfCompany = 0;
	double incomeOfCompany = 0;

	// Get inputs from the user
	printf("Enter the company type (C/c) Catering (M/m) Medical: ");
	scanf("%c", &companyType);

	// Find income of the company
	if (companyType == 'c' || companyType == 'C') {
		printf("Enter the sales of the company: ");
		scanf("%d", &salesOfCompany);

		if (salesOfCompany > 0 && salesOfCompany < 40000)
			incomeOfCompany = SALES_CATERING_LESS_THAN_40K_INCOME + salesOfCompany * SALES_CATERING_LESS_THAN_40K_SALES_PERCENTAGE;
		else if (salesOfCompany >= 40000)
			incomeOfCompany = SALES_CATERING_GREATER_AND_EQUALS_TO_40K_INCOME + salesOfCompany * SALES_CATERING_GREATER_AND_EQUALS_TO_40K_SALES_PERCENTAGE;
	}
	else if (companyType == 'M' || companyType == 'm') {
		printf("Enter the sales of the company: ");
		scanf("%d", &salesOfCompany);

		if (salesOfCompany > 0 && salesOfCompany < 25000)
			incomeOfCompany = SALES_MEDICAL_LESS_THAN_25K_INCOME + salesOfCompany * SALES_MEDICAL_LESS_THAN_25K_SALES_PERCENTAGE;
		else if (salesOfCompany >= 25000)
			incomeOfCompany = SALES_MEDICAL_GREATER_AND_EQUALS_TO_25K_INCOME + salesOfCompany * SALES_MEDICAL_GREATER_AND_EQUALS_TO_25K_SALES_PERCENTAGE;
	}
	else {
		return 1;
	}

	printf("\nIncome of the company is $%.2f", incomeOfCompany);

	return 0;
}