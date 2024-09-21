#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Define variables
	int classOfStudent, courseHour1, courseHour2, courseHour3, totalCourseHours;
	char semesterOfStudent;

	// Get inputs from the user
	printf("Enter the class of the student: ");
	scanf("%d", &classOfStudent);

	printf("Enter the semester of the student: ");
	scanf(" %c", &semesterOfStudent);

	switch (classOfStudent) {
		case 1:
			switch (semesterOfStudent) {
				case 'F':
				case 'f':
					printf("Courses");
					printf("\nEnter number of course hours for 151/163/165: ");
					scanf("%d %d %d", &courseHour1, &courseHour2, &courseHour3);

					totalCourseHours = courseHour1 + courseHour2 + courseHour3;

					printf("Student spends %d hours for must courses", totalCourseHours);
					break;

				case 's':
				case 'S':
					printf("Courses");
					printf("\nEnter number of course hours for 152/164/166: ");
					scanf("%d %d %d", &courseHour1, &courseHour2, &courseHour3);

					totalCourseHours = courseHour1 + courseHour2 + courseHour3;

					printf("Student spends %d hours for must courses", totalCourseHours);
					break;

				default:
					printf("Invalid Semester!");
			}  break;

		case 2:
			switch (semesterOfStudent) {
				case 'F':
				case 'f':
					printf("Courses");
					printf("\nEnter number of course hours for 221,255,259: ");
					scanf("%d %d %d", &courseHour1, &courseHour2, &courseHour3);

					totalCourseHours = courseHour1 + courseHour2 + courseHour3;

					printf("Student spends %d hours for must courses", totalCourseHours);
					break;

				case 's':
				case 'S':
					printf("Courses");
					printf("\nEnter number of course hours for 222,256,264: ");
					scanf("%d %d %d", &courseHour1, &courseHour2, &courseHour3);

					totalCourseHours = courseHour1 + courseHour2 + courseHour3;

					printf("Student spends %d hours for must courses", totalCourseHours);
					break;

				default:
					printf("Invalid Semester!");
			}

		default:
			printf("Invalid Class!");
	}
	return 0;
}