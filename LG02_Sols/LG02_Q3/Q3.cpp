#include <stdio.h>

int main(void)
{
	int megabyte = 379;
	double bit = 0, byte = 0, kilobyte = 0;

	//calculate the values of kilobyte, byte and bit
	kilobyte = 1024 * megabyte;

	//byte = 1024*1024*megabyte;
	byte = 1024 * kilobyte;

	//bit = 8*1024*1024*megabyte;
	bit = 8 * byte;

	return(0);
}