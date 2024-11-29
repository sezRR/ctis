#define _CRT_SECURE_NO_WARNINGS

#define MAX 10

#include <stdio.h>
#include <string.h>

typedef struct {
	char brand[10];
	int stock;
	int arriveStock;
} phone_t;

/* Returns: STEP AMOUNT */
int rBinarySearch(phone_t* phones, char* brand, phone_t* result, int size, int l, int r) {
	if (l > r)
		return 0;

	int step = 0;
	int m = (l + r) / 2;
	int res = strcmp(phones[m].brand, brand);
	step++;
	if (res == 0)
	{
		*result = phones[m];
		return step;
	}
	else if (res > 0)
		step += rBinarySearch(phones, brand, result, size, l, m - 1);
	else
		step += rBinarySearch(phones, brand, result, size, m + 1, r);
}

int main(void) {
	FILE* file = fopen("phones.bin", "rb");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		phone_t phones[MAX]{}, result{"", -1, -1};
		char brandToSearch[MAX] = "";

		int phonesIndex = 0;
		while (fread(&phones[phonesIndex], sizeof(phone_t), 1, file) == 1)
			phonesIndex++;

		printf("Enter a phone brand to search: ");
		scanf("%s", brandToSearch);

		int steps = rBinarySearch(phones, brandToSearch, &result, phonesIndex, 0, phonesIndex - 1);
		printf("After %d step(s) ", steps);
		if (result.stock == -1)
			printf("%s could not be found!", brandToSearch);
		else
			printf("%s found with %d stocks and %d stocks will arrive", brandToSearch, result.stock, result.arriveStock);

		fclose(file);
	}
	
	return 0;
}