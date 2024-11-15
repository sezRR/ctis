#include "BinFileUtil.h"

int createSeedBinFile(FILE* binFile, int maxEl, bool closeAfterWrite)
{
	for (int i = 1; i <= maxEl; i++)
		fwrite(&i, sizeof(int), 1, binFile);

	int createdEl = ftell(binFile) / sizeof(int);

	if (closeAfterWrite)
		fclose(binFile);

	return createdEl;
}
