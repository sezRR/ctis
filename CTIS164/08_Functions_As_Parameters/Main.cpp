#include <stdio.h>

void display(int a, float var1) {
	printf("display(int): %d \t %f\n\n", a, var1);
}

void display() {
	printf("display(void)\n\n");
}

void executer1(void (*fnc)(int, float), int a, float b) {
	fnc(a, b);
}

void executer1(void (*fnc)(int, float)) {
	fnc(5, 0.5); // Related arguments are passed by OS in glut functions
}

void executer2(void (*fnc)()) {
	fnc();
}

int main() {
	executer1(display, 100, 0.1);
	executer1(display);
	executer2(display);
	return 0;
}