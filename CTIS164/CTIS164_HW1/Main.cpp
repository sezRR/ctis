/*********************************************
   CTIS164 - Homework
   Owner: Sezer Tetik, 22303222
   Modified with Airplane Animation and Clipping Fix
*********************************************/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

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

// Global variables for airplane animation
bool planeAnimationActive = false;  // Animation starts off
float planeX = -400;                // Initial position
float planeY = 100;                 // Fixed height
float planeSpeed = 5.0;             // Movement speed
bool movingRight = true;            // Direction of movement

// Utility function to set color adjusted for light level
void setLightAdjustedColor(float r, float g, float b) {
    glColor3f(r * lightLevel, g * lightLevel, b * lightLevel);
}

float getEffectiveRoomLight(bool isObjectOutside = false) {
    if (isObjectOutside)
        return 1.1; // Always use full brightness for outside objects

    const float ROOM_BOOST = 0.3;
    return lightOn ? lightLevel : (lightLevel + ROOM_BOOST * blindAnimationProgress);
}

void setRoomLightAdjustedColor(float r, float g, float b) {
    float effectiveLight = getEffectiveRoomLight();
    glColor3f(r * effectiveLight, g * effectiveLight, b * effectiveLight);
}

void setRoomLightAdjustedColorOutside(float r, float g, float b) {
    float effectiveLight = getEffectiveRoomLight(true);
    glColor3f(r * effectiveLight, g * effectiveLight, b * effectiveLight);
}

bool isInsideCircle(int px, int py, int cx, int cy, int r) {
    int dx = px - cx;
    int dy = py - cy;
    return dx * dx + dy * dy <= r * r;
}

void circle(int x, int y, int r) {
    float angle;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        angle = 2 * PI * i / 100;
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }
    glEnd();
}

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

void drawAirplane(float x, float y) {
    float scale = 0.3;
    x = x * scale;
    y = y * scale;

    // Override y to fix the vertical position within the window area
    y = (WINDOW_HEIGHT * (1 / 3.0) - frameThickness + (-WINDOW_HEIGHT * (1 / 3.0) + frameThickness)) / 2 - 30;

    // 1. Main fuselage
    setRoomLightAdjustedColorOutside(0.8, 0.8, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x - 120, y);
    glVertex2f(x + 80, y);
    glVertex2f(x + 100, y - 15);
    glVertex2f(x - 100, y - 15);
    glEnd();

    // 2. Cockpit
    setRoomLightAdjustedColorOutside(0.7, 0.85, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x + 80, y);
    glVertex2f(x + 110, y);
    glVertex2f(x + 90, y - 15);
    glVertex2f(x + 70, y - 15);
    glEnd();

    // 3. Nose cone
    setRoomLightAdjustedColorOutside(0.7, 0.7, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(x + 110, y);
    glVertex2f(x + 130, y - 7.5);
    glVertex2f(x + 110, y - 15);
    glEnd();

    // 4. Tail fin
    setRoomLightAdjustedColorOutside(0.6, 0.6, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x - 90, y);
    glVertex2f(x - 110, y + 40);
    glVertex2f(x - 120, y + 40);
    glVertex2f(x - 120, y);
    glEnd();

    // 5. Horizontal stabilizer
    setRoomLightAdjustedColorOutside(0.6, 0.6, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x - 90, y - 5);
    glVertex2f(x - 110, y - 25);
    glVertex2f(x - 120, y - 25);
    glVertex2f(x - 120, y - 5);
    glEnd();

    // 6. Main wings
    setRoomLightAdjustedColorOutside(0.7, 0.7, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x - 20, y - 5);
    glVertex2f(x + 30, y - 5);
    glVertex2f(x + 50, y - 45);
    glVertex2f(x - 40, y - 45);
    glEnd();

    // 7. Engine 1
    setRoomLightAdjustedColorOutside(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(x - 10, y - 25);
    glVertex2f(x + 30, y - 25);
    glVertex2f(x + 30, y - 40);
    glVertex2f(x - 10, y - 40);
    glEnd();

    setRoomLightAdjustedColorOutside(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x - 15, y - 27);
    glVertex2f(x - 10, y - 27);
    glVertex2f(x - 10, y - 38);
    glVertex2f(x - 15, y - 38);
    glEnd();

    // 8. Engine 2
    setRoomLightAdjustedColorOutside(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(x - 80, y - 25);
    glVertex2f(x - 40, y - 25);
    glVertex2f(x - 40, y - 40);
    glVertex2f(x - 80, y - 40);
    glEnd();

    setRoomLightAdjustedColorOutside(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x - 85, y - 27);
    glVertex2f(x - 80, y - 27);
    glVertex2f(x - 80, y - 38);
    glVertex2f(x - 85, y - 38);
    glEnd();

    // 9. Windows
    setRoomLightAdjustedColorOutside(0.7, 0.85, 1.0);
    for (int i = 0; i < 8; i++) {
        int wx = x + 60 - i * 20;
        glBegin(GL_POLYGON);
        glVertex2f(wx, y - 5);
        glVertex2f(wx + 10, y - 5);
        glVertex2f(wx + 10, y - 12);
        glVertex2f(wx, y - 12);
        glEnd();
    }

    // 10. Front wheel
    setRoomLightAdjustedColorOutside(0.3, 0.3, 0.3);
    circle(x + 90, y - 25, 7);

    setRoomLightAdjustedColorOutside(0.5, 0.5, 0.5);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(x + 90, y - 15);
    glVertex2f(x + 90, y - 25);
    glEnd();

    // 11. Rear wheels
    setRoomLightAdjustedColorOutside(0.3, 0.3, 0.3);
    circle(x, y - 55, 10);
    circle(x - 50, y - 55, 10);

    setRoomLightAdjustedColorOutside(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    glVertex2f(x, y - 45);
    glVertex2f(x, y - 55);
    glVertex2f(x - 50, y - 45);
    glVertex2f(x - 50, y - 55);
    glEnd();

    // 12. Tail logo
    setRoomLightAdjustedColorOutside(1.0, 0.0, 0.0);
    circle(x - 105, y + 20, 10);

    setRoomLightAdjustedColorOutside(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(x - 110, y + 15);
    glVertex2f(x - 100, y + 25);
    glVertex2f(x - 110, y + 25);
    glVertex2f(x - 100, y + 15);
    glEnd();
}

void drawWallAndSwitch() {
    double w = 2 / 5.0;
    double h = 1 / 3.0;
    float left = -WINDOW_WIDTH * w;
    float right = WINDOW_WIDTH * w;
    float top = WINDOW_HEIGHT * h;
    float bottom = -WINDOW_HEIGHT * h;
    float wallThickness = 25;

    setRoomLightAdjustedColor(0.9, 0.9, 0.95);

    float patternLeft = left - wallThickness - 200;
    float patternRight = right + wallThickness + 200;
    float patternTop = top + wallThickness + 150;
    float patternBottom = bottom - wallThickness - 150;

    // Main wall background
    glBegin(GL_POLYGON);
    glVertex2f(patternLeft, patternTop);
    glVertex2f(patternRight, patternTop);
    glVertex2f(patternRight, patternBottom);
    glVertex2f(patternLeft, patternBottom);
    glEnd();

    // Wall pattern with rectangles
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

    switchX = right + wallThickness + 50;
    switchY = (top + bottom) / 2;

    // Draw Switch
    setRoomLightAdjustedColor(0.95, 0.95, 0.95);
    glBegin(GL_POLYGON);
    glVertex2f(switchX - 20, switchY + 30);
    glVertex2f(switchX + 20, switchY + 30);
    glVertex2f(switchX + 20, switchY - 30);
    glVertex2f(switchX - 20, switchY - 30);
    glEnd();

    setRoomLightAdjustedColor(0.7, 0.7, 0.7);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(switchX - 20, switchY + 30);
    glVertex2f(switchX + 20, switchY + 30);
    glVertex2f(switchX + 20, switchY - 30);
    glVertex2f(switchX - 20, switchY - 30);
    glEnd();

    if (lightOn) {
        setLightAdjustedColor(0.2, 0.6, 0.2);
    }
    else {
        setLightAdjustedColor(0.7, 0.2, 0.2);
    }
    circle(switchX, switchY, switchRadius);

    setLightAdjustedColor(0.9, 0.9, 0.9);
    circle(switchX - 3, switchY + 3, 4);

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
    double w = 2 / 5.0;
    double h = 1 / 3.0;
    float left = -WINDOW_WIDTH * w;
    float right = WINDOW_WIDTH * w;
    float top = WINDOW_HEIGHT * h;
    float bottom = -WINDOW_HEIGHT * h;

    adjusterX = right - frameThickness - 15;
    adjusterY = bottom + frameThickness + 25;
    adjusterRadius = 8;

    // Wall around the window
    setRoomLightAdjustedColor(0.85, 0.85, 0.9);
    float wallThickness = 25;
    glBegin(GL_POLYGON);
    glVertex2f(left - wallThickness, bottom - wallThickness);
    glVertex2f(right + wallThickness, bottom - wallThickness);
    glVertex2f(right + wallThickness, top + wallThickness);
    glVertex2f(left - wallThickness, top + wallThickness);
    glEnd();

    // Window frame
    setRoomLightAdjustedColor(0.7, 0.7, 0.75);
    glBegin(GL_POLYGON);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glVertex2f(left, top);
    glEnd();

    // Sky - draw this BEFORE the airplane
    glColor4f(0.8, 0.9, 1.0, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(left + frameThickness, bottom + frameThickness);
    glVertex2f(right - frameThickness, bottom + frameThickness);
    glVertex2f(right - frameThickness, top - frameThickness);
    glVertex2f(left + frameThickness, top - frameThickness);
    glEnd();

    // Clip the airplane to the inner window area using the scissor test
    // Calculate scissor rectangle in window (pixel) coordinates:
    // Scene x coordinate maps to pixel x by: x_pixel = x_scene + WINDOW_WIDTH/2
    int scissorX = (int)(left + frameThickness + WINDOW_WIDTH / 2);
    int scissorY = (int)(bottom + frameThickness + WINDOW_HEIGHT / 2);
    int scissorW = (int)(right - left - 2 * frameThickness);
    int scissorH = (int)(top - bottom - 2 * frameThickness);
    glEnable(GL_SCISSOR_TEST);
    glScissor(scissorX, scissorY, scissorW, scissorH);
    drawAirplane(planeX, planeY);
    glDisable(GL_SCISSOR_TEST);

    // Draw window borders with line loops instead of lines
    glLineWidth(2);
    g
    // Top border
    setRoomLightAdjustedColor(0.9, 0.9, 0.95);
    glBegin(GL_LINE_LOOP);
    glVertex2f(left + 2, top - 2);
    glVertex2f(right - 2, top - 2);
    glVertex2f(right - 2, top - 4);
    glVertex2f(left + 2, top - 4);
    glEnd();

    // Left border
    glBegin(GL_LINE_LOOP);
    glVertex2f(left + 2, top - 2);
    glVertex2f(left + 2, bottom + 2);
    glVertex2f(left + 4, bottom + 2);
    glVertex2f(left + 4, top - 2);
    glEnd();

    // Bottom border 
    setRoomLightAdjustedColor(0.5, 0.5, 0.55);
    glBegin(GL_LINE_LOOP);
    glVertex2f(left + 2, bottom + 2);
    glVertex2f(right - 2, bottom + 2);
    glVertex2f(right - 2, bottom + 4);
    glVertex2f(left + 2, bottom + 4);
    glEnd();

    // Right border
    glBegin(GL_LINE_LOOP);
    glVertex2f(right - 2, top - 2);
    glVertex2f(right - 2, bottom + 2);
    glVertex2f(right - 4, bottom + 2);
    glVertex2f(right - 4, top - 2);
    glEnd();

    // Inner frame border
    setRoomLightAdjustedColor(0.8, 0.8, 0.85);
    glBegin(GL_LINE_LOOP);
    glVertex2f(left + frameThickness + 2, top - frameThickness - 2);
    glVertex2f(right - frameThickness - 2, top - frameThickness - 2);
    glVertex2f(right - frameThickness - 2, top - frameThickness - 4);
    glVertex2f(left + frameThickness + 2, top - frameThickness - 4);
    glEnd();

    // Draw blinds AFTER the airplane
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
        glBegin(GL_LINE_LOOP);
        glVertex2f(left + frameThickness + 5, y - blindHeight / 2 + 3);
        glVertex2f(right - frameThickness - 5, y - blindHeight / 2 + 3);
        glVertex2f(right - frameThickness - 5, y - blindHeight / 2 + 2);
        glVertex2f(left + frameThickness + 5, y - blindHeight / 2 + 2);
        glEnd();
    }

    // Top blind holder
    if (blindAnimationProgress > 0) {
        setRoomLightAdjustedColor(0.85, 0.85, 0.85);
        glBegin(GL_POLYGON);
        glVertex2f(left + frameThickness, top - frameThickness - 10);
        glVertex2f(right - frameThickness, top - frameThickness - 10);
        glVertex2f(right - frameThickness, top - frameThickness);
        glVertex2f(left + frameThickness, top - frameThickness);
        glEnd();
    }

    // Blind mechanism
    setRoomLightAdjustedColor(0.75, 0.75, 0.8);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(right - frameThickness - 15, top - frameThickness);
    glVertex2f(right - frameThickness - 15, bottom + frameThickness);
    glEnd();

    // Blind adjuster
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

void onBlindsTimer(int v) {
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
        glutTimerFunc(16, onBlindsTimer, 0);
    }
    glutPostRedisplay();
}

void onPlaneTimer(int v) {
    glutTimerFunc(16, onPlaneTimer, 0);

    if (planeAnimationActive) {
        if (movingRight) {
            planeX += planeSpeed;
            if (planeX > WINDOW_WIDTH + 1000) {
                planeX = -WINDOW_WIDTH - 1000;
            }
        }
        else {
            planeX -= planeSpeed;
            if (planeX < -WINDOW_WIDTH - 1000) {
                planeX = WINDOW_WIDTH + 1000;
            }
        }
    }

    glutPostRedisplay();
}

void onClick(int button, int state, int x, int y) {
    int wx = x - WINDOW_WIDTH / 2;
    int wy = WINDOW_HEIGHT / 2 - y;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (isInsideCircle(wx, wy, adjusterX, adjusterY, adjusterRadius)) {
            blindsOpen = !blindsOpen;
            glutTimerFunc(16, onBlindsTimer, 0);
        }
        else if (isInsideCircle(wx, wy, switchX, switchY, switchRadius)) {
            lightOn = !lightOn;
            lightLevel = lightOn ? 1.0 : 0.4;
            glutPostRedisplay();
        }
    }
    glutPostRedisplay();
}

void onSpecialKeyDown(int key, int x, int y) {
    if (key == GLUT_KEY_F1) {
        planeAnimationActive = true;
        planeX = -400; // Reset position
        movingRight = true;
    }
    glutPostRedisplay();
}

void onKeyDown(unsigned char key, int x, int y) {
    if (key == 27) // ESC
        exit(0);
    else if (key == ' ')
        planeAnimationActive = !planeAnimationActive;
    glutPostRedisplay();
}

void display() {
    float effectiveRoomLight = getEffectiveRoomLight();
    glClearColor(0.8 * effectiveRoomLight, 0.8 * effectiveRoomLight, 0.8 * effectiveRoomLight, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawWallAndSwitch();
    drawWindow();
    createNameSurnameLabel();

    glColor3f(0, 0, 0);
    vprint(-WINDOW_WIDTH / 2 + 10, -WINDOW_HEIGHT / 2 + 20, GLUT_BITMAP_HELVETICA_12,
        "F1: Start Animation, SPACEBAR: Pause/Resume, ESC: Exit");
    vprint(-WINDOW_WIDTH / 2 + 10, -WINDOW_HEIGHT / 2 + 40, GLUT_BITMAP_HELVETICA_12,
        "Click on the blind knob to open/close blinds. Animation Active: %s",
        planeAnimationActive ? "Yes" : "No");

    glutSwapBuffers();
}

void onResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Init() {
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("CTIS164 - HW - Sezer Tetik - 22303222 - Airplane Animation");
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    Init();
    glutDisplayFunc(display);
    glutReshapeFunc(onResize);
    glutKeyboardFunc(onKeyDown);
    glutSpecialFunc(onSpecialKeyDown);
    glutMouseFunc(onClick);

    glutTimerFunc(16, onBlindsTimer, 0);
    glutTimerFunc(16, onPlaneTimer, 0);

    glutMainLoop();
    return 0;
}
