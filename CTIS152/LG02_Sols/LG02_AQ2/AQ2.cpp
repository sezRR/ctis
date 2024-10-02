#define _CRT_SECURE_NO_WARNINGS

#define validate_row_and_column(r, c) ( r > 0 && c > 0 )
#define validate_non_zero_el_count(z, all) (all / 2 > z)
#define validate_arr_index_boundaries(actual_r, actual_c, inp_r, inp_c) (actual_r >= inp_r && actual_c >= inp_c)

#include <stdio.h>
#include <stdlib.h>

void getNonzeroElement(int rowSize, int colSize, int* rowIndex, int* colIndex, int* value) {
	int temp_r, temp_c, temp_val;
	do
	{
		printf("Enter row and column indexes and nonzero element: ");
		scanf("%d %d %d", &temp_r, &temp_c, &temp_val);

		if (!validate_arr_index_boundaries(rowSize, colSize, temp_r, temp_c))
			printf("\nInvalid array index boundaries! (for [%d][%d])\n\n", temp_r, temp_c);
	} while (!validate_arr_index_boundaries(rowSize, colSize, temp_r, temp_c));

	*rowIndex = temp_r;
	*colIndex = temp_c;
	*value = temp_val;
}

int main(void) {
	int r, c, *arr, nonZeroEl;

	do
	{
		printf("Enter number of rows and columns: ");
		scanf("%d %d", &r, &c);
		if (!validate_row_and_column(r, c))
			printf("\nInvalid row or column value!\n");
	} while (!validate_row_and_column(r, c));

	arr = (int*)malloc(r * c * sizeof(int));

	if (arr == nullptr)
	{
		printf("Memory allocation for 'arr' could not be completed successfully.\nExiting...");
		return 1;
	}

	for (int i = 0; i < r * c; i++)
		*(arr + i) = 0;

	do
	{
		printf("\nEnter number of nonzero elements: ");
		scanf("%d", &nonZeroEl);

		if (!validate_non_zero_el_count(nonZeroEl, r * c))
			printf("\nInvalid nonzero element count.\nNonzero element count cannot be greater than the half of the array size (r * c / 2)!\n");
	} while (!validate_non_zero_el_count(nonZeroEl, r * c));


	for (int i = 0; i < nonZeroEl; i++)
	{
		int temp_r, temp_c, temp_val;
		getNonzeroElement(r + 1, c + 1, &temp_r, &temp_c, &temp_val);

		*(arr + (temp_r * c + temp_c)) = temp_val;
	}

	printf("\nThe Sparse Matrix:\n");
	for (int i = 0; i < r * c; i++)
	{
		printf("%d ", *(arr + i));
		if (i != 0 && (i + 1) % c == 0)
			printf("\n");
	}

	free(arr);

	return 0;
}