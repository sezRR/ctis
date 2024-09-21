#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int numOfDigit(int digit)
{
	int counter = 0;
	while (digit > 0)
	{
		digit /= 10;
		counter++;
	}

	return counter;
}

int findCity(int cityCode, int* phoneNumber)
{
	int plateNumber;
	switch (cityCode)
	{
	case 312: // Ankara
		plateNumber = 6;
		break;
	case 212: // Istanbul
		plateNumber = 34;
		break;
	case 232: // Izmir
		plateNumber = 35;
		break;
	case 332: // Konya
		plateNumber = 42;
	}

	*phoneNumber += plateNumber * cityCode;
	return plateNumber;
}

int main(void)
{
	// Define variables
	int cityCode = 0, phoneNumber, plateNumber;

	// Get inputs from the user
	for (int i = 1; i <= 3; i++)
	{
		do
		{
			printf("Enter %d. user the city code and phone number: ", i);
			scanf("%d %d", &cityCode, &phoneNumber);

			if (numOfDigit(phoneNumber) != 7
				|| (cityCode != 312
					&& cityCode != 212
					&& cityCode != 232
					&& cityCode != 332))
				printf("Wrong city code or phone enter again!\n\n");
		} while (numOfDigit(phoneNumber) != 7
			|| numOfDigit(cityCode) != 3
			|| (cityCode != 312
				&& cityCode != 212
				&& cityCode != 232
				&& cityCode != 332));

		plateNumber = findCity(cityCode, &phoneNumber);
		printf("%d. user Plate Code is %d and new phone number is %d\n\n", i, plateNumber, phoneNumber);
	}

	return 0;
}