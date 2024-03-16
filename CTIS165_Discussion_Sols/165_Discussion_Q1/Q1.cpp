/*
The TC Id numbers are actually 9 digits, the last 2 digits are calculated based on the first 9 digits. These are the steps:

- add digits in positions 1,3,5,7,9 and multiply it by 7.

- subtract from the computed number digits in position 2,4,6,8.

- from the calculated number calculate modulo 10, the result will be your 10th TC Id digit.

- Add all 10 digits now, and calculate modulo 10, the result will be your 11th TC Id digit.

CTIS students, can you write a C code that calculates digits 10 and 11 by using the first 9 digits?
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	char citizenshipIdInput;
	int digit,
		charIndexCounter = 1,
		sumOddIndexedDigits = 0,
		sumEvenIndexedDigits = 0,
		tenthDigitOfIdNumber,
		eleventhDigitOfIdNumber,
		identityNumber = 0;

	printf("Enter the first 9 digits of your Turkish ID number: ");
	scanf("%c", &citizenshipIdInput);

	while (citizenshipIdInput != '\n')
	{
		// Convert ASCII character to integer
		digit = citizenshipIdInput - '0';

		identityNumber += digit * (pow(10, 9 - charIndexCounter));

		if (charIndexCounter % 2 == 0)
			sumEvenIndexedDigits += digit;
		else
			sumOddIndexedDigits += digit;

		scanf("%c", &citizenshipIdInput);
		charIndexCounter++;
	}

	// Calculate 10th digit
	tenthDigitOfIdNumber = (sumOddIndexedDigits * 7 - sumEvenIndexedDigits) % 10;

	// Calculate 11th digit
	eleventhDigitOfIdNumber = (sumOddIndexedDigits + sumEvenIndexedDigits + tenthDigitOfIdNumber) % 10;

	printf("10th Digit of the Identity Number: %d", tenthDigitOfIdNumber);
	printf("\n11th Digit of the Identity Number: %d", eleventhDigitOfIdNumber);
	printf("\n\nComplete Identity Number: %d%d%d", identityNumber, tenthDigitOfIdNumber, eleventhDigitOfIdNumber);

	return 0;
}