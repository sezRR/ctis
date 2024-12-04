#define _CRT_SECURE_NO_WARNINGS

#define ADD_TOPIC_INP_VALIDATOR(inp_chr) c != 'Y' && c != 'N' && c != 'y' && c != 'n'
#define DIFFICULTY_VALIDATOR(inp_diff, diff_e, diff_m, diff_h) strcmp(inp_diff, diff_e) != 0 && strcmp(inp_diff, diff_m) != 0 && strcmp(inp_diff, diff_h) != 0

#define DIFF_EASY "Easy"
#define DIFF_MEDIUM "Medium"
#define DIFF_HARD "Hard"

#include <stdio.h>
#include <string.h>
#include "queue_struct.h"

void insertAccDiff(queue_t* q_e, queue_t* q_m, queue_t* q_h, topic_t el) {
	if (strcmp(el.level, DIFF_EASY) == 0)
		insert(q_e, el);
	else if (strcmp(el.level, DIFF_MEDIUM) == 0)
		insert(q_m, el);
	else
		insert(q_h, el);
}

topic_t removeAccDiff(queue_t* q_e, queue_t* q_m, queue_t* q_h, char* diff) {
	if (strcmp(diff, DIFF_EASY) == 0)
		return remove(q_e);
	else if (strcmp(diff, DIFF_MEDIUM) == 0)
		return remove(q_m);
	else
		return remove(q_h);
}

void displayQueue(queue_t q) {
	printf("Topic \t\t\t Level\n*******************************\n");
	while (!isEmptyQ(&q))
	{
		topic_t temp = remove(&q);
		printf("%-15s \t %s\n", temp.topic, temp.level);
	}
	printf("\n");
}

void displayQueueAccDiff(queue_t q_e, queue_t q_m, queue_t q_h, char* diff) {
	if (strcmp(diff, DIFF_EASY) == 0)
		displayQueue(q_e);
	else if (strcmp(diff, DIFF_MEDIUM) == 0)
		displayQueue(q_m);
	else
		displayQueue(q_h);
}


void displayQueues(queue_t q_e, queue_t q_m, queue_t q_h) {
	printf("Easy Topics;\n");
	displayQueue(q_e);

	printf("Medium Topics;\n");
	displayQueue(q_m);

	printf("Hard Topics;\n");
	displayQueue(q_h);
}


int main(void) {
	FILE* file = fopen("math.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		queue_t q_e;
		initializeQ(&q_e);

		queue_t q_m;
		initializeQ(&q_m);

		queue_t q_h;
		initializeQ(&q_h);

		topic_t temp;
		while (fscanf(file, " %[^:]:%s", temp.topic, temp.level) != EOF)
			insertAccDiff(&q_e, &q_m, &q_h, temp);

		displayQueues(q_e, q_m, q_h);
		while (1)
		{
			char c;
			do
			{
				printf("Do you want t o add any topic? (Y/N): ");
				scanf(" %c", &c);
				if (ADD_TOPIC_INP_VALIDATOR(c))
					printf("Invalid choice!\n\n");
			} while (ADD_TOPIC_INP_VALIDATOR(c));

			if (c == 'N' || c == 'n')
				break;

			topic_t newTopic{};
			printf("Enter the topic: ");
			scanf(" %[^\n]", newTopic.topic);

			do
			{
				printf("Enter the level of the question: ");
				scanf(" %s", newTopic.level);
				if (DIFFICULTY_VALIDATOR(newTopic.level, DIFF_EASY, DIFF_MEDIUM, DIFF_HARD))
					printf("Invalid difficulty!\n\n");
			} while (DIFFICULTY_VALIDATOR(newTopic.level, DIFF_EASY, DIFF_MEDIUM, DIFF_HARD));

			insertAccDiff(&q_e, &q_m, &q_h, newTopic);
			displayQueueAccDiff(q_e, q_m, q_h, newTopic.level);
		}

		char toSolveDiff[STR_SIZE] = "";
		do
		{
			printf("Which level do you prefer to solve questions?: ");
			scanf("%s", toSolveDiff);
			if (DIFFICULTY_VALIDATOR(toSolveDiff, DIFF_EASY, DIFF_MEDIUM, DIFF_HARD))
				printf("Invalid difficulty!");
		} while (DIFFICULTY_VALIDATOR(toSolveDiff, DIFF_EASY, DIFF_MEDIUM, DIFF_HARD));

		printf("You should solve the %s question.\nGood Luck :)", removeAccDiff(&q_e, &q_m, &q_h, toSolveDiff).topic);

		fclose(file);
	}

	return 0;
}
