#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// STEP #3: Implement Event Handlers that are already registered.
// Event Handler for DISPLAY event
void display() {
	printf("Event: DISPLAY called.\n");
	glClearColor(1, 1, 0, 0); // yellow, r: 1, g: 1, b: 0
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

// Event Handler for RESIZE event
void onResize(int width, int height) {
	printf("Event: RESIZE, New width: %d height: %d\n", width, height);
}

int main(int argc, char* argv[]) {

	// STEP #1: Create Window
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Basic Window");

	// STEP #2: Register Events
	glutDisplayFunc(display);  // Event = DISPLAY, call display
	glutReshapeFunc(onResize); // Event = RESIZE,  call onResize

	// STEP #4: Start Event Dispatcher
	// Check event queue, if there is any event
	// Call appropriate event handler based on event type
	// Do this in an infinite loop
	glutMainLoop();

	return 0;
}