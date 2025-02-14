#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// STEP #3: Implement Event Handlers
void display() {
	glClearColor(1, 0, 0, 0); // red
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void onKey(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
}

// button: GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
// state : GLUT_DOWN, GLUT_UP
void onClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		printf("LEFT BUTTON --");
	else if (button == GLUT_RIGHT_BUTTON)
		printf("RIGHT BUTTON --");

	if (state == GLUT_DOWN)
		printf("DOWN [%d %d]\n", x, y);
	else
		printf("UP [%d %d]\n", x, y);
}

// GLUT_KEY_DOWN, GLUT_KEY_F1
void onSpecialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		printf("UP arrow pressed.\n");
		break;
	case GLUT_KEY_DOWN:
		printf("DOWN arrow pressed.\n");
		break;
	case GLUT_KEY_LEFT:
		printf("LEFT arrow pressed.\n");
		break;
	case GLUT_KEY_RIGHT:
		printf("RIGHT arrow pressed.\n");
		break;
	}
}

int main(int argc, char* argv[]) {
	printf("Press ESC to exit from the program.\n");
	printf("Click on the window with left or right mouse button.\n");
	printf("Press arrow keys to be detected.\n");
	// STEP #1: Create Window
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Window, Mouse, and Keyboard Events");

	// STEP #2: Register Events
	// Window Related Events
	glutDisplayFunc(display);

	// Keyboard Related Events
	glutKeyboardFunc(onKey);
	glutSpecialFunc(onSpecialKey);

	// Mouse Related Events
	glutMouseFunc(onClick);

	// STEP #4: Start Event Dispatcher
	glutMainLoop();

	return 0;
}