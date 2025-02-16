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

void onResize(int width, int height) {
    printf("Event: RESIZE New width: %d height: %d\n", width, height);
}

// button: GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON
// state : GLUT_DOWN, GLUT_UP
void onClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x > 350 && y > 350) // Lower right corner of the window
            exit(0);
        printf("Event : CLICK %d %d\n", x, y);
    }
}

void onMove(int x, int y) {
    printf("Event : MOVE %d %d\n", x, y);
}

void onMoveDown(int x, int y) {
    printf("Event : MOVEDOWN %d %d\n", x, y);
}

void onKeyDown(unsigned char key, int x, int y) {
    printf("Event : KEYDOWN-ASCII %d %c\n", key, key);
    if (key == ' ')
        activeTimer = !activeTimer; // To stop or resume timer.
}

void onKeyUp(unsigned char key, int x, int y) {
    printf("Event : KEYUP-ASCII %d %c\n", key, key);
    if (key == 27)  // 27 is Escape key
        exit(0);
}

// GLUT_KEY_DOWN, GLUT_KEY_F1
void onSpecialKeyDown(int key, int x, int y) {
    printf("Event : SPC-DOWN %d\n", key);
    if (key == GLUT_KEY_F1)
        exit(0);
}

void onSpecialKeyUp(int key, int x, int y) {
    printf("Event : SPC-UP %d\n", key);
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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Window, Mouse, Keyboard and Timer Events");

    // STEP #2: Register Events
    // Window Related Events
    glutDisplayFunc(display);
    glutReshapeFunc(onResize);

    // Mouse Related Events
    glutMouseFunc(onClick);
    glutPassiveMotionFunc(onMove);
    glutMotionFunc(onMoveDown);

    // Keyboard Related Events
    glutKeyboardFunc(onKeyDown);
    glutKeyboardUpFunc(onKeyUp);
    glutSpecialFunc(onSpecialKeyDown);
    glutSpecialUpFunc(onSpecialKeyUp);

    // Timer Event
    glutTimerFunc(1000, onTimer, 0);

    // STEP #4: Start Event Dispatcher
    glutMainLoop();
    return 0;
}