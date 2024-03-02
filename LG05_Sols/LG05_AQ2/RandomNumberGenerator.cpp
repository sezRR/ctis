#include <stdio.h>
#include <stdlib.h> //for srand funtion
#include <time.h> //for time function

int generateRandomNumber(void)
{
	int num;
	/* we use srand function to be able to get a random number but we cannot use the srand function on
	its own, so we also use time function in it to give a start point to the srand function; because time
	is different every time you run the program, the random number will be different also */
	srand(time(NULL));

	/* because time returns a very big number it returns the millisecond value of the hour, so we want
	to get a random number between 0 and 99, we get the modulus 100 of the rand function */
	num = rand() % 100;

	/* to create a number between a range*/
	//num = rand() % ((Max+1)-Min) + Min
	//printf("The random number is: %d", num);
	return num;
}