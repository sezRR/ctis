#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// GLOBAL VARIABLES
bool activeTimer = true;
int counter = 0;

// STEP #3: Implement Event Handlers
void display() {
    glClearColor(0, 0, 1, 0); // Blue
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void onKeyDown(unsigned char key, int x, int y) {
    if (key == 27) {   // 27 is Escape key
        printf("End of program.\n");
        exit(0);
    }
    if (key == ' ') {
        activeTimer = !activeTimer; // To stop or resume timer.
        if (activeTimer)
            printf("Spacebar: Timer is activated.\n");
        else
            printf("Spacebar: Timer is deactivated.\n");
    }
}

void onTimer(int v) {

    glutTimerFunc(1000, onTimer, 0);

    if (activeTimer) {
        printf("Event : TIMER %d\n", counter);
        counter++;
    }
}

int main(int argc, char* argv[]) {

    // STEP #1: Create Window
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(400, 200);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Window, Keyboard and Timer Events");

    // STEP #2: Register Events
    // Display Event
    glutDisplayFunc(display);

    // Keyboard Event
    glutKeyboardFunc(onKeyDown);

    // Timer Event
    glutTimerFunc(1000, onTimer, 0);

    // STEP #4: Start Event Dispatcher
    glutMainLoop();
    return 0;
}