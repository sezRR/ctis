/*********************************************
   CTIS164 - Homework 1
   Owner: Sezer Tetik, 22303222
*********************************************/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_WIDTH  1200
#define WINDOW_HEIGHT 800
#define D2R 0.01745329252
#define PI  3.14159265358

// Global variables for blind state
bool blindsOpen = false;           // blinds start closed
float blindAnimationProgress = 0.0; // 0.0 is fully closed, 1.0 is fully open
const float ANIMATION_SPEED = 0.05;  // How quickly blinds open/close
float adjusterX, adjusterY;
float adjusterRadius;
float frameThickness = 15;           // Global frame thickness

// Global variables for light state
bool lightOn = true;   // Start with light on
float lightLevel = 1.0; // Full brightness when on, set to 0.4 when off
float switchX, switchY;
float switchRadius = 12;

// Utility function to set color adjusted for light level
// (For objects that are meant to reflect the pure light state)
void setLightAdjustedColor(float r, float g, float b) {
    glColor3f(r * lightLevel, g * lightLevel, b * lightLevel);
}

// When light is off, a boost based on blind openness is added.
float getEffectiveRoomLight() {
    const float ROOM_BOOST = 0.3; // Maximum boost when blinds are fully open
    return lightOn ? lightLevel : (lightLevel + ROOM_BOOST * blindAnimationProgress);
}

// Set color for environment objects using effective room light.
void setRoomLightAdjustedColor(float r, float g, float b) {
    float effectiveLight = getEffectiveRoomLight();
    glColor3f(r * effectiveLight, g * effectiveLight, b * effectiveLight);
}

// Function to check if a point is inside a circle
bool isInsideCircle(int px, int py, int cx, int cy, int r) {
    int dx = px - cx;
    int dy = py - cy;
    return dx * dx + dy * dy <= r * r;
}

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

    glRasterPos2f(x, y);
    for (int i = 0; i < (int)strlen(str); i++)
        glutBitmapCharacter(font, str[i]);
}

void createNameSurnameLabel() {
    glColor3f(1, 0, 0);
    vprint(0, WINDOW_HEIGHT / 2 - 50, GLUT_BITMAP_HELVETICA_18, "Sezer Tetik");
}

void drawWallAndSwitch() {
    double w = 2 / 5.0;  // Window width ratio
    double h = 1 / 3.0;  // Window height ratio
    float left = -WINDOW_WIDTH * w;
    float right = WINDOW_WIDTH * w;
    float top = WINDOW_HEIGHT * h;
    float bottom = -WINDOW_HEIGHT * h;
    float wallThickness = 25;

    // Draw wall background using environment light adjustment
    setRoomLightAdjustedColor(0.9, 0.9, 0.95);

    // Calculate pattern area dimensions
    float patternLeft = left - wallThickness - 200;
    float patternRight = right + wallThickness + 200;
    float patternTop = top + wallThickness + 150;
    float patternBottom = bottom - wallThickness - 150;

    glBegin(GL_POLYGON);
    glVertex2f(patternLeft, patternTop);
    glVertex2f(patternRight, patternTop);
    glVertex2f(patternRight, patternBottom);
    glVertex2f(patternLeft, patternBottom);
    glEnd();

    // Draw vertical stripes on wall
    setRoomLightAdjustedColor(0.85, 0.85, 0.9);
    float stripeWidth = 50;
    for (float x = patternLeft; x <= patternRight; x += stripeWidth * 2) {
        glBegin(GL_POLYGON);
        glVertex2f(x, patternTop);
        glVertex2f(x + stripeWidth, patternTop);
        glVertex2f(x + stripeWidth, patternBottom);
        glVertex2f(x, patternBottom);
        glEnd();
    }

    // Draw light switch
    // Position it to the right of the window
    switchX = right + wallThickness + 50;
    switchY = (top + bottom) / 2;

    // Switch background plate
    setRoomLightAdjustedColor(0.95, 0.95, 0.95);
    glBegin(GL_POLYGON);
    glVertex2f(switchX - 20, switchY + 30);
    glVertex2f(switchX + 20, switchY + 30);
    glVertex2f(switchX + 20, switchY - 30);
    glVertex2f(switchX - 20, switchY - 30);
    glEnd();

    // Switch border
    setRoomLightAdjustedColor(0.7, 0.7, 0.7);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(switchX - 20, switchY + 30);
    glVertex2f(switchX + 20, switchY + 30);
    glVertex2f(switchX + 20, switchY - 30);
    glVertex2f(switchX - 20, switchY - 30);
    glEnd();

    // Switch button (color still reflects the switch state)
    if (lightOn) {
        setLightAdjustedColor(0.2, 0.6, 0.2);
    }
    else {
        setLightAdjustedColor(0.7, 0.2, 0.2);
    }
    circle(switchX, switchY, switchRadius);

    // Switch button highlight
    setLightAdjustedColor(0.9, 0.9, 0.9);
    circle(switchX - 3, switchY + 3, 4);

    // Draw switch label
    setRoomLightAdjustedColor(0.3, 0.3, 0.3);
    if (lightOn) {
        vprint(switchX - 15, switchY - 45, GLUT_BITMAP_HELVETICA_10, "LIGHT: ON");
    }
    else {
        vprint(switchX - 18, switchY - 45, GLUT_BITMAP_HELVETICA_10, "LIGHT: OFF");
    }
}

void drawWindow() {
    glPointSize(10);
    glLineWidth(5);
    double w = 2 / 5.0;  // Window width ratio
    double h = 1 / 3.0;  // Window height ratio
    float left = -WINDOW_WIDTH * w;
    float right = WINDOW_WIDTH * w;
    float top = WINDOW_HEIGHT * h;
    float bottom = -WINDOW_HEIGHT * h;

    // Store adjuster position for hit testing
    adjusterX = right - frameThickness - 15;
    adjusterY = bottom + frameThickness + 25;
    adjusterRadius = 8;

    // Outer window frame (wall) drawn using room light adjustment
    setRoomLightAdjustedColor(0.85, 0.85, 0.9);
    float wallThickness = 25;
    glRectf(left - wallThickness, bottom - wallThickness,
        right + wallThickness, top + wallThickness);

    // Window frame (structure around the glass)
    setRoomLightAdjustedColor(0.7, 0.7, 0.75);
    glRectf(left, bottom, right, top);

    // Inner window area (glass)
    // If light is off but blinds are open, simulate external light entering.
    if (!lightOn && blindAnimationProgress > 0) {
        float effectiveWindowLight = lightLevel + (1.0 - lightLevel) * blindAnimationProgress;
        glColor3f(0.8 * effectiveWindowLight, 0.9 * effectiveWindowLight, 1.0 * effectiveWindowLight);
    }
    else {
        // Use default lightLevel for glass
        setLightAdjustedColor(0.8, 0.9, 1.0);
    }
    glRectf(left + frameThickness, bottom + frameThickness,
        right - frameThickness, top - frameThickness);

    // Window frame shadow/highlight effects (using room light adjustment)
    glLineWidth(2);
    setRoomLightAdjustedColor(0.9, 0.9, 0.95);
    glBegin(GL_LINES);
    glVertex2f(left + 2, top - 2);
    glVertex2f(right - 2, top - 2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(left + 2, top - 2);
    glVertex2f(left + 2, bottom + 2);
    glEnd();

    setRoomLightAdjustedColor(0.5, 0.5, 0.55);
    glBegin(GL_LINES);
    glVertex2f(left + 2, bottom + 2);
    glVertex2f(right - 2, bottom + 2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(right - 2, top - 2);
    glVertex2f(right - 2, bottom + 2);
    glEnd();

    // Inner frame highlight/shadow
    setRoomLightAdjustedColor(0.8, 0.8, 0.85);
    glBegin(GL_LINES);
    glVertex2f(left + frameThickness + 2, top - frameThickness - 2);
    glVertex2f(right - frameThickness - 2, top - frameThickness - 2);
    glEnd();

    // Roller blinds
    int numBlinds = 12;
    float blindHeight = (top - bottom - 2 * frameThickness) / numBlinds;
    float windowHeight = top - bottom - 2 * frameThickness;
    float visibleHeight = windowHeight * (1.0 - blindAnimationProgress);
    int visibleBlinds = ceil(visibleHeight / blindHeight);

    for (int i = 0; i < numBlinds && i < visibleBlinds; i++) {
        float y = top - frameThickness - (i + 0.5) * blindHeight;
        if (i == visibleBlinds - 1 && blindAnimationProgress > 0) {
            float partialVisibility = visibleHeight - (i * blindHeight);
            if (partialVisibility < blindHeight) {
                y = top - frameThickness - i * blindHeight - partialVisibility / 2;
            }
        }
        if (i % 2 == 0) {
            setRoomLightAdjustedColor(0.93, 0.93, 0.93);
        }
        else {
            setRoomLightAdjustedColor(0.9, 0.9, 0.9);
        }
        glBegin(GL_POLYGON);
        glVertex2f(left + frameThickness + 5, y + blindHeight / 2 - 3);
        glVertex2f(right - frameThickness - 5, y + blindHeight / 2 - 3);
        glVertex2f(right - frameThickness - 5, y - blindHeight / 2 + 3);
        glVertex2f(left + frameThickness + 5, y - blindHeight / 2 + 3);
        glEnd();

        setRoomLightAdjustedColor(0.7, 0.7, 0.7);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(left + frameThickness + 5, y - blindHeight / 2 + 3);
        glVertex2f(right - frameThickness - 5, y - blindHeight / 2 + 3);
        glEnd();
    }

    // Draw rolled up blinds at the top when partially/fully open
    if (blindAnimationProgress > 0) {
        setRoomLightAdjustedColor(0.85, 0.85, 0.85);
        glRectf(left + frameThickness, top - frameThickness - 10,
            right - frameThickness, top - frameThickness);
    }

    // Modern blind control mechanism
    setRoomLightAdjustedColor(0.75, 0.75, 0.8);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(right - frameThickness - 15, top - frameThickness);
    glVertex2f(right - frameThickness - 15, bottom + frameThickness);
    glEnd();

    // Blind adjuster (cylindrical knob)
    if (blindsOpen) {
        setRoomLightAdjustedColor(0.5, 0.7, 0.5);
    }
    else {
        setRoomLightAdjustedColor(0.6, 0.6, 0.65);
    }
    circle(right - frameThickness - 15, bottom + frameThickness + 25, 8);
    setRoomLightAdjustedColor(0.8, 0.8, 0.85);
    circle(right - frameThickness - 13, bottom + frameThickness + 27, 3);

    glLineWidth(5);
}

// Timer function to animate the blinds
void onTimer(int v) {
    if (blindsOpen) {
        blindAnimationProgress += ANIMATION_SPEED;
        if (blindAnimationProgress > 1.0)
            blindAnimationProgress = 1.0;
    }
    else {
        blindAnimationProgress -= ANIMATION_SPEED;
        if (blindAnimationProgress < 0.0)
            blindAnimationProgress = 0.0;
    }
    if ((blindsOpen && blindAnimationProgress < 1.0) ||
        (!blindsOpen && blindAnimationProgress > 0.0)) {
        glutTimerFunc(16, onTimer, 0);
    }
    glutPostRedisplay();
}

// Mouse click handler
void onClick(int button, int state, int x, int y) {
    int wx = x - WINDOW_WIDTH / 2;
    int wy = WINDOW_HEIGHT / 2 - y;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (isInsideCircle(wx, wy, adjusterX, adjusterY, adjusterRadius)) {
            blindsOpen = !blindsOpen;
            glutTimerFunc(16, onTimer, 0);
        }
        else if (isInsideCircle(wx, wy, switchX, switchY, switchRadius)) {
            lightOn = !lightOn;
            lightLevel = lightOn ? 1.0 : 0.4;
            glutPostRedisplay();
        }
    }
    glutPostRedisplay();
}

// Display function
void display() {
    // Use effective room light for the overall background
    float effectiveRoomLight = getEffectiveRoomLight();
    glClearColor(0.8 * effectiveRoomLight, 0.8 * effectiveRoomLight, 0.8 * effectiveRoomLight, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawWallAndSwitch();
    drawWindow();
    createNameSurnameLabel();

    glutSwapBuffers();
}

// Keyboard event for ASCII characters
void onKeyDown(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
    glutPostRedisplay();
}

// Reshape event
void onResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Init() {
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("CTIS164 - Lab02: Drawing OpenGL Primitives");
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    Init();
    glutDisplayFunc(display);
    glutReshapeFunc(onResize);
    glutKeyboardFunc(onKeyDown);
    glutMouseFunc(onClick);
    glutTimerFunc(0, onTimer, 0);
    glutMainLoop();
    return 0;
}
