/***********************************
   CTIS164 Lab-Man
***********************************/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define WINDOW_WIDTH  400
#define WINDOW_HEIGHT 400
#define PI  3.14159265358

// To draw a filled circle, centered at (x,y) with radius r
void circle(int x, int y, int r) {
	float angle;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		angle = 2 * PI * i / 100;
		glVertex2f(x + r * cos(angle), y + r * sin(angle));
	}
	glEnd();
}

// Display text with variables.
void vprint(int x, int y, void* font, const char* string, ...) {
	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);

	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, str[i]);
}

void Mydisplay_Q1() {
	printf("Function MyDisplay_Q1\n");
	glClearColor(1, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(255, 229, 204);
	glRectf(-150, 150, 150, -150);

	glColor3ub(0, 0, 255);
	circle(0, 0, 50);

	glutSwapBuffers();
}

void Mydisplay_Q2() {
	printf("Function MyDisplay_Q2\n");
	glClearColor(0, 1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(255, 229, 204);
	glRectf(-150, 150, 150, -150);

	glColor3f(0.5, 0.5, 1);
	circle(60, 150, 30);

	glColor3f(1, 1, 1);
	circle(60, 150, 20);

	glColor3f(1, 0, 0);
	circle(60, 150, 10);

	glutSwapBuffers();
}

// To display onto window using OpenGL commands
void display() {
	printf("Function DISPLAY\n");
	// Clear window to black
	glClearColor(0.7, 0.7, 0.7, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3ub(96, 96, 96); // Gray
	// Horizontal grid lines
	for (int y = -200; y <= 200; y += 20) {
		glVertex2f(-200, y);
		glVertex2f(200, y);
	}
	// Vertical grid lines
	for (int x = -200; x <= 200; x += 20) {
		glVertex2f(x, -200);
		glVertex2f(x, 200);
	}

	glColor3ub(255, 255, 0); // Yellow lines
	// Horizontal line
	glVertex2f(-200, 0);
	glVertex2f(200, 0);
	// Vertical line
	glVertex2f(0, -200);
	glVertex2f(0, 200);
	glEnd();

	// Yellow quad (body)
	glBegin(GL_QUADS);
	glVertex2f(-50, 0);
	glVertex2f(0, 50);
	glVertex2f(50, 0);
	glVertex2f(0, -50);
	glEnd();

	// Green circle (head)
	glColor3ub(102, 204, 0); // Green
	circle(0, 120, 40);

	// Red rectangle (mouth)
	glColor3ub(204, 0, 0); // Red
	glBegin(GL_POLYGON);
	glVertex2f(-25, 93);
	glVertex2f(-25, 108);
	glVertex2f(25, 108);
	glVertex2f(25, 93);
	glEnd();

	// Red triangle (nose)
	glBegin(GL_TRIANGLES);
	glVertex2f(-15, 113);
	glVertex2f(15, 113);
	glVertex2f(0, 122);
	glEnd();

	// Black circles (eyes)
	glColor3ub(0, 0, 0); // Black
	circle(-20, 130, 5);
	circle(20, 130, 5);

	// Red rectangle
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0); // Red
	glVertex2f(-50, 190);
	glColor3ub(51, 25, 0); // Brown
	glVertex2f(50, 190);
	glColor3ub(51, 25, 0); // Brown
	glVertex2f(50, 170);
	glColor3ub(204, 0, 0); // Red
	glVertex2f(-50, 170);
	glEnd();

	glColor3ub(51, 125, 255); // Blue
	vprint(-45, -100, GLUT_BITMAP_TIMES_ROMAN_24, "Hi There!!!");

	glutSwapBuffers();
}

// Key function for ASCII charachters like ESC, a,b,c..,A,B,..Z
void onKey(unsigned char key, int x, int y) {
	// Exit when ESC is pressed.
	if (key == 27)
		exit(0);
	// To refresh the window it calls display() function
	glutPostRedisplay();
}

// This function is called when the window size changes.
// w : is the new width of the window in pixels.
// h : is the new height of the window in pixels.
void onResize(int w, int h) {
	printf("Event: RESIZE New width: %d height: %d\n", w, h);
	glEnable(GL_SCISSOR_TEST);
	glViewport(0, 0, w / 2, h / 2);
	glScissor(0, 0, w / 2, h / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	printf("Function DISPLAY in RESIZE function is called.\n");
	display();

	glViewport(w / 2, h / 2, w / 2, h / 2);
	glScissor(w / 2, h / 2, w / 2, h / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	printf("Function MyDISPLAY_Q1 in RESIZE function is called.\n");
	Mydisplay_Q1();
	/*
	glViewport(0, h/2, w / 2, h / 2);
	glScissor(0, h/2, w / 2, h / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	printf("Function MyDISPLAY_Q2 in RESIZE function is called.\n");
	Mydisplay_Q2();
	*/
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(800, 400);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("CTIS164 Lab-Man");

	//glutDisplayFunc(display);
	glutDisplayFunc(Mydisplay_Q1);
	glutReshapeFunc(onResize);

	// Keyboard registration "ESC to EXIT"
	glutKeyboardFunc(onKey);

	glutMainLoop();
	return 0;
}