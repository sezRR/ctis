/* Purpose to find the currency equalities */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	double lira, dollars, euros;

	// Set value of lira
	lira = 675.4;

	// Convert currencies
	dollars = 0.033 * lira;
	euros = 0.93 * dollars;

	return(0);
}