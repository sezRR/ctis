#define _CRT_SECURE_NO_WARNINGS

#define MAX_STR_LEN 100
#define MAX_STR_ARR_LEN 20

#include <stdio.h>
#include <string.h>

int shortest(char str_arr[MAX_STR_LEN][MAX_STR_ARR_LEN], int y, int* shortest_length) {
	int smallest_index = 0;
	*shortest_length = strlen(str_arr[0]);
	for (int i = 1; i < y; i++)
	{
		int str_len = strlen(str_arr[i]);
		if (*shortest_length > str_len)
		{
			*shortest_length = str_len;
			smallest_index = i;
		}
	}
	return smallest_index;
}

int main(void) {
	char str_arr[MAX_STR_LEN][MAX_STR_ARR_LEN];
	int y = 0, shortest_length = 0;

	printf("Enter a word (or END): ");
	scanf("%s", str_arr[y]);
	while (strcmp(str_arr[y++], "END") != 0)
	{
		printf("Enter a word (or END): ");
		scanf("%s", str_arr[y]);
	}

	printf("Shortest word: %s\n", str_arr[shortest(str_arr, y, &shortest_length)]);
	printf("Length %d", shortest_length);

	return 0;
}