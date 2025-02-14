#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

bool inside(int x, int y) {
	return ((200 < x && x < 400) && (200 < y && y < 400));
}

void onResize(int w, int h) {
	// Transforms the GLUT coordinate system to OpenGL.
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// STEP #3: Implement Event Handlers that are already registered.
// Event Handler for DISPLAY event
void display() {
	glClearColor(1, 1, 0, 0); //Yellow
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3ub(255, 229, 204);
	glRectf(-150, 150, 150, -150);

	glLineWidth(5);
	// Draws a rectangle in the middle of the window.
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-100, -100);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, -100);
	glEnd();
	glutSwapBuffers();
}

// Event Handler for Mouse Passive Move event
void onPassiveMove(int x, int y) {
	if (inside(x, y))
		printf("moved inside\n");
	else
		printf("moved outside\n");
}

// Event Handler for Mouse Click
void onClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (inside(x, y)) {
			printf("Clicked inside: x=%d y=%d\n", x, y);
			printf("Finishing the program.\n");
			exit(0);
		}
		else
			printf("Clicked outside: x=%d y=%d\n", x, y);
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {

	// STEP #1: Create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Basic Window");

	// STEP #2: Register Events
	glutDisplayFunc(display);  //Event = DISPLAY, call display
	glutReshapeFunc(onResize); //Event = RESIZE,  call onResize
	glutPassiveMotionFunc(onPassiveMove);
	glutMouseFunc(onClick);    //Event = CLICK,   call onClick

	// STEP #4: Start Event Dispatcher
	// Check event queue, if there is any event
	// Call appropriate event handler based on event type
	// Do this in an infinite loop
	glutMainLoop();

	return 0;
}