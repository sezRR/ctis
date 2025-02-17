/*********************************************
   CTIS164 - Lab02
   OpenGL: Drawing different primitive shapes
*********************************************/
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define WINDOW_WIDTH  400
#define WINDOW_HEIGHT 400
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

	// DRAW 3 POINTS
	glColor3f(1, 0, 0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(-180, 180);
	glVertex2f(-170, 170);
	glVertex2f(-160, 180);
	glEnd();
	vprint(-190, 140, GLUT_BITMAP_8_BY_13, "3 POINTS");

	// DRAW 2 DISCONNECTED LINES
	glColor3ub(255, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	// Line 1
	glVertex2f(-90, 110);
	glVertex2f(-10, 180);
	// Line 2
	glColor3f(0, 1, 0);
	glVertex2f(-90, 150);
	glVertex2f(5, 115);
	glEnd();
	vprint(-80, 90, GLUT_BITMAP_8_BY_13, "2 LINES");

	// DRAW A LINE STRIP (CONNECTED LINES)
	glColor3f(0.3, 0.3, 1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(120, 100);
	glVertex2f(130, 120);
	glVertex2f(140, 100);
	glVertex2f(150, 180);
	glVertex2f(160, 90);
	glVertex2f(170, 150);
	glVertex2f(190, 150);
	glEnd();
	vprint(103, 75, GLUT_BITMAP_8_BY_13, "6 LINE STRIP");

	// DRAW A LINE LOOP
	glColor3f(0.8, 0.2, 0.8);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-180, -20);
	glVertex2f(-170, 30);
	glVertex2f(-130, 70);
	glVertex2f(-90, 40);
	glVertex2f(-120, -30);
	glEnd();
	vprint(-175, -50, GLUT_BITMAP_8_BY_13, "LINE LOOP");

	// DRAW CIRCLES
	glColor3f(0.5, 0.5, 1);
	circle(60, 150, 30);

	glColor3f(1, 1, 1);
	circle(60, 150, 20);

	glColor3f(1, 0, 0);
	circle(60, 150, 10);
	vprint(25, 100, GLUT_BITMAP_8_BY_13, "3 CIRCLES");

	// DRAW TWO DISCONNECTED TRIANGLES
	glColor3f(0.5, 1, 0.4);
	glBegin(GL_TRIANGLES);
	glVertex2f(-50, 40);
	glVertex2f(-20, 60);
	glVertex2f(0, 20);

	// A Gradient (color Transition )
	glColor3f(1, 0, 0); // red
	glVertex2f(-35, 10);
	glColor3f(0, 1, 0); // green
	glVertex2f(-40, -40);
	glColor3f(0, 0, 1); // blue
	glVertex2f(0, -15);
	glEnd();
	vprint(-50, -60, GLUT_BITMAP_8_BY_13, "2 TRIANGLES");

	// DRAW A TRIANGLE STRIP
	glColor3f(0.7, 0.8, 0.2);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(65, 25);
	glVertex2f(85, -30);
	glVertex2f(115, 20);
	glVertex2f(140, -30);
	glVertex2f(160, 25);
	glVertex2f(180, -10);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(65, 25);
	glVertex2f(85, -30);
	glVertex2f(115, 20);
	glVertex2f(140, -30);
	glVertex2f(160, 25);
	glVertex2f(180, -10);
	glEnd();
	vprint(65, -50, GLUT_BITMAP_8_BY_13, "TRIANGLE STRIP");

	// DRAW A RECTANGLE
	glColor3f(0.6, 0, 0.6);
	glRectf(-180, -150, -100, -100);
	vprint(-180, -165, GLUT_BITMAP_8_BY_13, "A RECTANGLE");

	// DRAW a QUAD
	glColor3f(1, 1, 0.3);
	glBegin(GL_QUADS);
	glVertex2f(-60, -120);
	glVertex2f(-25, -90);
	glVertex2f(30, -100);
	glVertex2f(30, -145);
	glEnd();
	vprint(-50, -160, GLUT_BITMAP_8_BY_13, "A QUAD");

	// DRAW a POLYGON
	// INTERIOR
	glColor3f(0.4, 0.4, 1);
	glBegin(GL_POLYGON);
	glVertex2f(75, -150);
	glVertex2f(70, -120);
	glVertex2f(105, -85);
	glVertex2f(160, -100);
	glVertex2f(170, -130);
	glVertex2f(140, -155);
	glEnd();

	// BOUNDARY
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(75, -150);
	glVertex2f(70, -120);
	glVertex2f(105, -85);
	glVertex2f(160, -100);
	glVertex2f(170, -130);
	glVertex2f(140, -155);
	glEnd();

	// VERTICES
	glColor3f(1, 1, 0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(75, -150);
	glVertex2f(70, -120);
	glVertex2f(105, -85);
	glVertex2f(160, -100);
	glVertex2f(170, -130);
	glVertex2f(140, -155);
	glEnd();
	glColor3f(0.4, 0.4, 1);
	vprint(60, -175, GLUT_BITMAP_8_BY_13, "6-Sided POLYGON");

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
	glutCreateWindow("CTIS164 - Lab02: Drawing OpenGL Primitives");

	// Window Events
	glutDisplayFunc(display);
	glutReshapeFunc(onResize);

	// Keyboard Events
	glutKeyboardFunc(onKeyDown);

	//Init();
	glutMainLoop();
	return 0;
}