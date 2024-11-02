#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char extension[25];
	char description[125];
} domain_t;

int read(FILE* file, domain_t* domains) {
	int c = 0;
	while (fscanf(file, "%s %[^\n]", (domains + c)->extension, (domains + c)->description) != EOF)
		c++;
	return c;
}

void findExtension(char* url, char* ext) {
	int urlLen = strlen(url), occurIndex = 0, occurLen = 0;
	for (int i = urlLen - 1 - 3; i > 0; i--)
		if (url[i] == '.') {
			occurIndex = i + 1;
			strncpy(ext, url + occurIndex, occurLen);
			return;
		}
		else
			occurLen++;

}

int search(domain_t* domains, char* ext, int domainLen) {
	int res = -1, extLen = strlen(ext);
	for (int i = 0; i < domainLen; i++)
		if (strncmp(ext, (domains + i)->extension, extLen) == 0)
			return i;
	return res;
}

int main(void) {
	FILE* file = fopen("extensions.txt", "r");
	domain_t domains[50];
	if (file == NULL)
		printf("File could not be opened!");
	else {
		int c = read(file, domains);

		char url[100];
		printf("Enter a website URL: ");
		scanf("%s", url);

		char ext[250] = "";
		findExtension(url, ext);
		int resIndex = search(domains, ext, c);
		printf("%s extension is used for %s", ext, (domains + resIndex)->description);
	}

	return 0;
}