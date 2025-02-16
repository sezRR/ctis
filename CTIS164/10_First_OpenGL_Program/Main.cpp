/********************************
   CTIS164 - First OpenGL Program
*********************************/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600
#define TIMER_PERIOD   20	// Period for the timer.
#define TIMER_ON        1	// 0:disable timer, 1:enable timer
#define D2R 0.01745329252
#define PI  3.14159265358

/* Global Variables for Template File */
bool up = false, down = false, right = false, left = false;
int  winWidth, winHeight;	// current Window width and height

/* Global variables for this Program */
int locX = 0, locY = 0;		// location of the circle
int radius = 50;			// radius of the circle
int colR = 0, colG = 0, colB = 0; // color of the circle

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

// To display onto window using OpenGL commands
void display() {
    printf("Display called\n");
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(255, 229, 204);
    glRectf(-250, 250, 250, -250);

    glColor3ub(colR, colG, colB);
    circle(locX, locY, radius);

    glutSwapBuffers();
}

// This function is called when the window size changes.
// w : is the new width of the window in pixels.
// h : is the new height of the window in pixels.
void onResize(int w, int h) {
    winWidth = w;
    winHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    display(); // Refresh window.
}

// Key function for ASCII charachters like ESC, a,b,c..,A,B,..Z
void onKeyDown(unsigned char key, int x, int y) {
    // Exit when ESC is pressed.
    if (key == 27)
        exit(0);

    if (key == 'e' || key == 'E') // Enlarge circle
        if (radius < 100)
            radius += 5;

    if (key == 's' || key == 'S') // Shrink circle
        if (radius > 5)
            radius -= 5;

    // To refresh the window it calls display() function
    glutPostRedisplay();
}

// Special Key like GLUT_KEY_F1, F2, F3,...
// Arrow Keys, GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT
void onSpecialKeyDown(int key, int x, int y) {
    // Write your codes here.
    switch (key) {
    case GLUT_KEY_UP:
        up = true;
        break;
    case GLUT_KEY_DOWN:
        down = true;
        break;
    case GLUT_KEY_LEFT:
        left = true;
        break;
    case GLUT_KEY_RIGHT:
        right = true;
        break;
    }
    // To refresh the window it calls display() function
    glutPostRedisplay();
}

// Special Key like GLUT_KEY_F1, F2, F3,...
// Arrow Keys, GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT
void onSpecialKeyUp(int key, int x, int y) {
    // Write your codes here.
    switch (key) {
    case GLUT_KEY_UP:
        up = false;
        break;
    case GLUT_KEY_DOWN:
        down = false;
        break;
    case GLUT_KEY_LEFT:
        left = false;
        break;
    case GLUT_KEY_RIGHT:
        right = false;
        break;
    }
    // To refresh the window it calls display() function
    glutPostRedisplay();
}

// When a click occurs in the window, It provides which button
// buttons : GLUT_LEFT_BUTTON , GLUT_RIGHT_BUTTON
// states  : GLUT_UP , GLUT_DOWN
// x, y is the coordinate of the point that mouse clicked.
//
// GLUT to OpenGL coordinate conversion:
//   x2 = x1 - winWidth / 2
//   y2 = winHeight / 2 - y1
void onClick(int button, int stat, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && stat == GLUT_DOWN) {
        colR = rand() % 256;
        colG = rand() % 256;
        colB = rand() % 256;
    }
    if (button == GLUT_RIGHT_BUTTON && stat == GLUT_DOWN) {
        locX = x - winWidth / 2;
        locY = winHeight / 2 - y;
    }
    // To refresh the window it calls display() function
    glutPostRedisplay();
}

#if TIMER_ON == 1
void onTimer(int v) {
    glutTimerFunc(TIMER_PERIOD, onTimer, 0);
    if (right) {
        if (locX < 300 - radius)
            locX += 2;
    }
    if (left) {
        if (locX > -250 + radius)
            locX -= 2;
    }
    if (up) {
        if (locY < 300 - radius)
            locY += 2;
    }
    if (down) {
        if (locY > -250 + radius)
            locY -= 2;
    }
    // To refresh the window it calls display() function
    glutPostRedisplay(); // display()
}
#endif

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(600, 200);
    glutCreateWindow("First OpenGL Program");

    // Window Events
    glutDisplayFunc(display);
    glutReshapeFunc(onResize);

    // Keyboard Events
    glutKeyboardFunc(onKeyDown);
    glutSpecialFunc(onSpecialKeyDown);
    glutSpecialUpFunc(onSpecialKeyUp);

    // Mouse Events
    glutMouseFunc(onClick);

#if  TIMER_ON == 1
    // Timer event
    glutTimerFunc(TIMER_PERIOD, onTimer, 0);
#endif

    srand(time(0));
    glutMainLoop();
    return 0;
}