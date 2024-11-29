#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "queue_struct.h"

void fillQueue(FILE* file, queue_t* q) {
	class_t temp{};
	while (fscanf(file, "%s %d", temp.className, &temp.questions) != EOF)
		insert(q, temp);
}

void display(queue_t q) {
	printf("Class Name \t # of Questions\n****************************\n");
	while (!isEmptyQ(&q))
	{
		class_t temp = remove(&q);
		printf("%s \t %d\n", temp.className, temp.questions);
	}
}

class_t classOfTheDay(queue_t q) {
	class_t max{};
	while (!isEmptyQ(&q))
	{
		class_t temp = remove(&q);
		if (max.questions < temp.questions)
			max = temp;
	}
	return max;
}

int main(void) {
	FILE* file = fopen("classes.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		queue_t q;
		initializeQ(&q);

		fillQueue(file, &q);

		printf("The list of all classes;\n\n");
		display(q);

		class_t bestClass = classOfTheDay(q);
		printf("The Class of the day\n*********************\n");
		printf("%s \t %d", bestClass.className, bestClass.questions);

		fclose(file);
	}
	
	return 0;
}