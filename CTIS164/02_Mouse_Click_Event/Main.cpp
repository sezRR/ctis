#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// STEP #3: Implement Event Handlers that are already registered.
// Event Handler for DISPLAY event
void display() {
    printf("Event: DISPLAY called.\n");
    glClearColor(0, 1, 0, 0); //green
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

// Event Handler for RESIZE event
void onResize(int width, int height) {
    printf("Event: RESIZE New width: %d height: %d\n", width, height);
}

// button : GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
// state  : GLUT_DOWN, GLUT_UP
void onClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x > 350 && y > 350)
            exit(0);
        printf("Event: CLK  x=%3d  y=%3d\n", x, y);
    }
}

int main(int argc, char* argv[]) {

    // STEP #1: Create Window
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("My First GLUT App.");

    // STEP #2: Register Events
    glutDisplayFunc(display);  // Event = DISPLAY, call display
    glutReshapeFunc(onResize); // Event = RESIZE,  call onResize
    glutMouseFunc(onClick);   // Event = CLICK,   call onClick

    // STEP #4: Start Event Dispatcher
    // Check event queue, if there is any event
    // Call appropriate event handler based on event type
    // Do this in an infinite loop
    glutMainLoop();

    return 0;
}