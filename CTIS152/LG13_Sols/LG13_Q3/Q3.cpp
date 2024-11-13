#define _CRT_SECURE_NO_WARNINGS

#define MAX 30

#include <stdio.h>
#include <string.h>

typedef struct {
	int taskId;
	int orderNo;
	char fileName[MAX];
} task_t;

int readFromFile(FILE* file, task_t* tasks) {
	int counter = 0;

	while (fscanf(file, "%d %d %s",
		&tasks[counter].taskId,
		&tasks[counter].orderNo,
		tasks[counter].fileName) != EOF)
		counter++;

	return counter;
}

void display(task_t* tasks, int arrLen) {
	printf("Task Id \t Order No \t File Name \n");
	printf("******* \t ******** \t ********* \n");
	for (int i = 0; i < arrLen; i++)
		printf("%-7d \t %-7d \t %s \n", tasks[i].taskId, tasks[i].orderNo, tasks[i].fileName);
	printf("\n");
}

void swap(task_t* t1, task_t* t2) {
	task_t temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

void recBubbleSort(task_t* tasks, int arrLen, int progress, int sorted) {
	if (sorted)
		return;

	sorted = 1;
	for (int i = 0; i < arrLen - progress; i++) {
		if (strcmp(tasks[i].fileName, tasks[i + 1].fileName) > 0)
		{
			swap(&tasks[i], &tasks[i + 1]);
			sorted = 0;
		}
	}
	progress++;

	recBubbleSort(tasks, arrLen, progress, sorted);
}

int recBinarySearch(task_t* tasks, char* searchFileName, int arrLen, int l, int r) {
	int m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (strcmp(tasks[m].fileName, searchFileName) == 0)
			return m;
		else if (strcmp(tasks[m].fileName, searchFileName) > 0)
			return recBinarySearch(tasks, searchFileName, arrLen, l, m - 1);
		else
			return recBinarySearch(tasks, searchFileName, arrLen, m + 1, r);
	}

	return -1;
}

int main(void) {
	FILE* file = fopen("taskList.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		task_t tasks[MAX];
		char fileName[MAX] = "";

		int arrLen = readFromFile(file, tasks);
		recBubbleSort(tasks, arrLen, 1, 0);
		display(tasks, arrLen);

		do
		{
			printf("Enter a filename (END for exit): ");
			scanf("%s", fileName);

			if (strcmp(fileName, "END") != 0)
			{
				int res = recBinarySearch(tasks, fileName, arrLen, 0, arrLen - 1);
				if (res == -1)
					printf("NOT FOUND\n\n");
				else {
					printf("Task Id \t Order No \t File Name \n");
					printf("******* \t ******** \t ********* \n");
					printf("%-7d \t %-7d \t %s \n\n", tasks[res].taskId, tasks[res].orderNo, tasks[res].fileName);
				}
			}
		} while (strcmp(fileName, "END") != 0);

		fclose(file);
	}

	return 0;
}