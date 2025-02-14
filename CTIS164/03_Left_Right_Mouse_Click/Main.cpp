#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// STEP #3: Implement Event Handlers that are already registered.
// Event Handler for DISPLAY event
void display() {
    printf("Event: DISPLAY called.\n");
    glClearColor(0, 0, 1, 0); // Blue
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

// button : GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
// state : GLUT_DOWN, GLUT_UP
void onClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x < 300)
            printf("Clicked on the LEFT half of the window : x = %d\n", x);
        else
            printf("Clicked on the RIGHT half of the window: x = %d\n", x);
    }
}

int main(int argc, char* argv[]) {

    // STEP #1: Create Window
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("My First GLUT App.");

    // STEP #2: Register Events
    glutDisplayFunc(display); // Event = DISPLAY, call display
    glutMouseFunc(onClick);   // Event = CLICK,   call onClick

    // STEP #4: Start Event Dispatcher
    // Check event queue, if there is any event
    // Call appropriate event handler based on event type
    // Do this in an infinite loop
    glutMainLoop();

    return 0;
}