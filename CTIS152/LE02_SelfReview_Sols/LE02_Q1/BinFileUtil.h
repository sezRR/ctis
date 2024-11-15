#include <stdio.h>

#ifndef BIN_FILE_UTIL_H
#define BIN_FILE_UTIL_H

int createSeedBinFile(FILE* binFile, int maxEl = 30, bool closeAfterWrite = true);

#endif
