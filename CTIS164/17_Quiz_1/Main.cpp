/*********************************************
   SEZER TETIK
   22303222
   SECTION CTIS164-3
*********************************************/
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600
#define D2R 0.01745329252
#define PI  3.14159265358

bool up = false, down = false, right = false, left = false;

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

// Display text with variables
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

// To display onto window using OpenGL commands
void display() {
	// Draw window
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glPointSize(5);

	glBegin(GL_LINES);
	glVertex2f(0, 300);
	glVertex2f(0, -300);

	glVertex2f(-300, 0);
	glVertex2f(300, 0);
	glEnd();

	vprint(10, 280, GLUT_BITMAP_HELVETICA_18, "y");
	vprint(280, 10, GLUT_BITMAP_HELVETICA_18, "x");

	glColor3f(1, 0, 0);
	circle(-150, -150, 100);

	vprint(100, -150, GLUT_BITMAP_HELVETICA_18, "CIRCLE");

	glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-150, 250);
	glVertex2f(-250, 50);
	glVertex2f(-50, 50);
	glEnd();

	vprint(100, 150, GLUT_BITMAP_HELVETICA_18, "TRIANGLE");


	glutSwapBuffers();
}

// Key function for ASCII charachters like ESC, a,b,c..,A,B,..Z
void onKeyDown(unsigned char key, int x, int y) {
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
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Init() {
	//Smoothing shapes
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Sezer Tetik - QUIZ#1");

	// Window Events
	glutDisplayFunc(display);
	glutReshapeFunc(onResize);

	// Keyboard Events
	glutKeyboardFunc(onKeyDown);

	//Init();
	glutMainLoop();
	return 0;
}