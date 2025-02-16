/*******************************************************
   CTIS164 - Lab01
   GLUT: Counting mouse clicks in the given time period
*******************************************************/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Global variables
int duration, whichButton,
counter = 0, // For counting seconds
clicks = 0;  // Number of clicks

// STEP #3: Implement Event Handlers that are already registered.
void display() {
    printf("Event: DISPLAY called.\n");
    glClearColor(1.0, 0.5, 0.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void onKeyDown(unsigned char key, int x, int y) {
    if (key == 27)   // 27 is Escape key
        exit(0);
}

void onClick(int button, int state, int x, int y) {
    if (button == whichButton && state == GLUT_DOWN)
        clicks++;
}

void onTimer(int v) {
    counter++;
    if (counter <= duration) {
        printf("%d clicks in %d seconds.\n", clicks, counter);
        glutTimerFunc(1000, onTimer, 0);
    }
    else // logically stop the timer (not invoke onTimer again)
        printf("End of counting.\n");
}

int main(int argc, char* argv[]) {
    printf("Enter duration (in seconds): ");
    scanf("%d", &duration);
    printf("Enter button (0:Left / 1:Middle / 2:Right): ");
    scanf("%d", &whichButton);
    printf("Press <ENTER> to start:");
    getc(stdin);
    getc(stdin);

    // STEP #1: Create Window
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(600, 200);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("CTIS164 - Lab01: Counting Mouse Clicks");

    // STEP #2: Register Events
    glutDisplayFunc(display);
    glutKeyboardFunc(onKeyDown);
    glutMouseFunc(onClick);
    glutTimerFunc(1000, onTimer, 0);

    // STEP #4: Start Event Dispatcher
    glutMainLoop();
    return 0;
}