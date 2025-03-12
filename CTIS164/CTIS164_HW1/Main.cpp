/*********************************************
   CTIS164 - Homework 1
   Owner: Sezer Tetik, 22303222 | Section: CTIS164-03

   # DOCUMENTATION
   The program is a simulation of a window view with an airplane flying by.

   ## Features
   - The window has blinds that can be opened and closed. (Dynamic Lightning)
       - The blinds can be opened and closed by clicking on the knob.
   - The room light can be turned on and off. (Dynamic Lightning)
       - The light can be turned on and off by clicking on the switch.
   - The airplane animation can be started with the F1 key. (Animation)
   - The airplane animation can be paused/resumed with the SPACEBAR key. (Animation)

   ### Dynamic Lightning
   - The room light level is adjusted based on the light switch state and blind state.
   - The room elements are drawn with a different color when it is outside the window area.

   #### Functions for Dynamic Lightning
   - setLightAdjustedColor(float r, float g, float b): Sets the color adjusted for light level.
   - getEffectiveRoomLight(bool isObjectOutside = false): Returns the effective room light level.
   - setRoomLightAdjustedColor(float r, float g, float b): Sets the color adjusted for room light level.
   - setRoomLightAdjustedColorOutside(float r, float g, float b): Sets the color adjusted for room light level for outside objects.

   ### Animation
   - The airplane animation can be started with the F1 key; animation can be paused/resumed with the SPACEBAR key.
   - The blinds can be opened and closed by clicking on the knob.

   #### Functions for Animation
   - onPlaneTimer(int v): Timer function to animate the airplane.
   - onBlindsTimer(int v): Timer function to animate the blinds.
   - onSpecialKeyDown(int key, int x, int y): Special key event handler for F1 key to start the airplane animation.
   - onKeyDown(unsigned char key, int x, int y): Keyboard event handler for ESC key to exit the program.

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

// Global variables for airplane animation
bool planeAnimationActive = false;  // Animation starts off
float planeXStart = -2000;          // Initial position
float planeX = planeXStart;         // Current position
float planeY = 100;                 // Fixed height
float planeSpeed = 5.0;             // Movement speed
bool movingRight = true;            // Direction of movement

// Window dimensions
float windowLeft, windowRight, windowTop, windowBottom;
float innerLeft, innerRight, innerTop, innerBottom;

// Global variables to draw wall pattern
double w = 2 / 5.0;
double h = 1 / 3.0;
float left = -WINDOW_WIDTH * w;
float right = WINDOW_WIDTH * w;
float top = WINDOW_HEIGHT * h;
float bottom = -WINDOW_HEIGHT * h;
float wallThickness = 25;
float patternLeft = left - wallThickness - 200;
float patternRight = right + wallThickness + 200;
float patternTop = top + wallThickness + 150;
float patternBottom = bottom - wallThickness - 150;

// Utility function to set color adjusted for light level
void setLightAdjustedColor(float r, float g, float b) {
    glColor3f(r * lightLevel, g * lightLevel, b * lightLevel);
}

// Utility function to get light level adjusted for room light level
// isObjectOutside is used to force full brightness for objects outside the window
float getEffectiveRoomLight(bool isObjectOutside = false) {
    if (isObjectOutside)
        return 1; // Always use full brightness for outside objects

    const float ROOM_BOOST = 0.3;
    return lightOn ? lightLevel : (lightLevel + ROOM_BOOST * blindAnimationProgress);
}

// Utility function to set color adjusted for room light level
void setRoomLightAdjustedColor(float r, float g, float b) {
    float effectiveLight = getEffectiveRoomLight();
    glColor3f(r * effectiveLight, g * effectiveLight, b * effectiveLight);
}

// Utility function to set color adjusted for room light level
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

// Draws a label with the name and surname
void createNameSurnameLabel() {
    const int padding = 20;

    setRoomLightAdjustedColor(0.5, 0.5, 0.5);
    glRectf(-150 - 1.25 * padding, WINDOW_HEIGHT / 2 - 105 - 0.75 * padding, 180 + 1.25 * padding, WINDOW_HEIGHT / 2 - 80 + 0.75 * padding);

    setRoomLightAdjustedColor(1, 1, 1);
    glRectf(-150 - padding, WINDOW_HEIGHT / 2 - 105 - padding/2.0, 180 + padding, WINDOW_HEIGHT / 2 - 80 + padding/2.0);

    glColor3f(0.25, 0.25, 0.25);
    vprint(-150, WINDOW_HEIGHT / 2 - 100, GLUT_BITMAP_HELVETICA_18, "View Through a Window by Sezer Tetik");
}

// Draws emergency door on the airplane
void drawAirplaneEmergencyDoor(float x, float y) {
    setRoomLightAdjustedColorOutside(0.65, 0.65, 0.65);
    glBegin(GL_POLYGON);
    glVertex2f(x - 8, y - 2);
    glVertex2f(x - 2, y - 2);
    glVertex2f(x - 2, y - 12);
    glVertex2f(x - 8, y - 12);
    glEnd();

    setRoomLightAdjustedColorOutside(0.4, 0.4, 0.4);
    glRectf(x - 4, y - 6, x - 6, y - 8);
}

// Draws airplane window on the cockpit
void drawAirplaneWindow(float x, float y) {
    setRoomLightAdjustedColorOutside(0.7, 0.85, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x + 95, y - 4);
    glVertex2f(x + 100, y - 4);
    glVertex2f(x + 102, y - 9);
    glVertex2f(x + 97, y - 9);
    glEnd();
}

// Draws the airplane
void drawAirplane(float x, float y) {
    float scale = 0.3;
    x = x * scale;
    y = y * scale;

    // Override y to fix the vertical position within the window area
    y = (innerTop + innerBottom) / 2 - 30;

    // 1. Main fuselage
    setRoomLightAdjustedColorOutside(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x - 120, y);
    glVertex2f(x + 90, y);
    glVertex2f(x + 90, y - 20);
    glVertex2f(x - 80, y - 20);
    glVertex2f(x - 120, y - 10);
    glEnd();

    // 2. Engine
    glBegin(GL_POLYGON);
    glVertex2f(x - 10, y - 25);
    glVertex2f(x + 20, y - 25);
    glVertex2f(x + 20, y - 35);
    glVertex2f(x - 10, y - 35);
    glEnd();

    // 3. Engine Back Part
    setRoomLightAdjustedColorOutside(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(x + 15, y - 25);
    glVertex2f(x + 20, y - 25);
    glVertex2f(x + 20, y - 35);
    glVertex2f(x + 15, y - 35);
    glEnd();

    // 4. Cockpit
    setRoomLightAdjustedColorOutside(1, 1, 1);
    glLineWidth(5);
	glBegin(GL_POLYGON);
	glVertex2f(x + 90, y);
    glVertex2f(x + 95, y - 3);
    glVertex2f(x + 103, y - 5);
    glVertex2f(x + 105, y - 7);
    glVertex2f(x + 100, y - 15);
    glVertex2f(x + 90, y - 20);
	glEnd();

    // 5. Cockpit Windows
    drawAirplaneWindow(x, y);
    drawAirplaneWindow(x - 6, y);
	glBegin(GL_POLYGON);
    glVertex2f(x + 95 - 12, y - 2);
    glVertex2f(x + 98 - 10, y - 4);
    glVertex2f(x + 102 - 12, y - 9);
    glVertex2f(x + 98 - 15, y - 7);
    glEnd();

    // 6. Tail fin
    setRoomLightAdjustedColorOutside(0.6, 0.6, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x - 90, y);
    glVertex2f(x - 110, y + 40);
    glVertex2f(x - 120, y + 40);
    glVertex2f(x - 120, y);
    glEnd();

    // 7. Horizontal stabilizer
    setRoomLightAdjustedColorOutside(0.6, 0.6, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x - 90, y - 5);
    glVertex2f(x - 110, y - 25);
    glVertex2f(x - 120, y - 25);
    glVertex2f(x - 120, y - 5);
    glEnd();

    // 8. Windows
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

    // 9. Main wings
    setRoomLightAdjustedColorOutside(0.7, 0.7, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(x - 20, y - 15);
    glVertex2f(x + 30, y - 15);
    glVertex2f(x - 40, y - 45);
    glEnd();

	// 10. Emergency Exits Near the Main Wing and cockipt
    drawAirplaneEmergencyDoor(x - 80, y);
    drawAirplaneEmergencyDoor(x, y);
    drawAirplaneEmergencyDoor(x + 80, y);

    // 11. Tail logo (Draws circle and T)
    setRoomLightAdjustedColorOutside(0, 0.0, 1);
    circle(x - 111, y + 20, 9);

    setRoomLightAdjustedColorOutside(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(x - 115, y + 23.5);
    glVertex2f(x - 105, y + 23.5);
    glVertex2f(x - 110, y + 23.5);
    glVertex2f(x - 110, y + 15);
    glEnd();
}

// Initialize window dimensions before drawing
void initializeWindowDimensions() {
    // Save window dimensions for later use
    windowLeft = left;
    windowRight = right;
    windowTop = top;
    windowBottom = bottom;

    // Calculate inner window dimensions
    innerLeft = left + frameThickness;
    innerRight = right - frameThickness;
    innerTop = top - frameThickness;
    innerBottom = bottom + frameThickness;
}

// Draws the mountain in the background
void drawMountain() {
    // Draw Mountain
    glColor3f(0.5, 0.35, 0.25); // Brown color for mountain

    // Calculate mountain peaks and positions for reuse
    float mountain1Left = innerLeft;
    float mountain1Right = innerLeft + (innerRight - innerLeft) * 0.4;
    float mountain1Peak_x = innerLeft + (innerRight - innerLeft) * 0.2;
    float mountain1Peak_y = innerBottom + (innerTop - innerBottom) * 0.7;

    float mountain2Left = innerLeft + (innerRight - innerLeft) * 0.3;
    float mountain2Right = innerLeft + (innerRight - innerLeft) * 0.8;
    float mountain2Peak_x = innerLeft + (innerRight - innerLeft) * 0.55;
    float mountain2Peak_y = innerBottom + (innerTop - innerBottom) * 0.8;

    glBegin(GL_TRIANGLES);
    // First mountain (left)
    glVertex2f(mountain1Left, innerBottom);
    glVertex2f(mountain1Right, innerBottom);
    glVertex2f(mountain1Peak_x, mountain1Peak_y);

    // Second mountain (right)
    glVertex2f(mountain2Left, innerBottom);
    glVertex2f(mountain2Right, innerBottom);
    glVertex2f(mountain2Peak_x, mountain2Peak_y);
    glEnd();

    // Snow caps on mountains
    glColor3f(1.0, 1.0, 1.0); // White color for snow

    // Calculate snow cap height - 20% from the peak
    float snowHeight = 0.2;

    glBegin(GL_TRIANGLES);
    // Snow on first mountain - properly aligned with mountain peak
    glVertex2f(mountain1Peak_x - (mountain1Right - mountain1Left) * 0.1,
        mountain1Peak_y - (mountain1Peak_y - innerBottom) * snowHeight);
    glVertex2f(mountain1Peak_x + (mountain1Right - mountain1Left) * 0.1,
        mountain1Peak_y - (mountain1Peak_y - innerBottom) * snowHeight);
    glVertex2f(mountain1Peak_x, mountain1Peak_y);

    // Snow on second mountain - properly aligned with mountain peak
    glVertex2f(mountain2Peak_x - (mountain2Right - mountain2Left) * 0.1,
        mountain2Peak_y - (mountain2Peak_y - innerBottom) * snowHeight);
    glVertex2f(mountain2Peak_x + (mountain2Right - mountain2Left) * 0.1,
        mountain2Peak_y - (mountain2Peak_y - innerBottom) * snowHeight);
    glVertex2f(mountain2Peak_x, mountain2Peak_y);
    glEnd();
}

void drawSky() {
	// Draw Sky
	setRoomLightAdjustedColorOutside(0.8, 0.9, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(innerLeft, innerBottom);
	glVertex2f(innerRight, innerBottom);
	glVertex2f(innerRight, innerTop);
	glVertex2f(innerLeft, innerTop);
	glEnd();
}

// Draw the window frame and interior
void drawWindowFrame() {
    // Window frame
    setRoomLightAdjustedColor(0.7, 0.7, 0.75);
    glBegin(GL_POLYGON);
    glVertex2f(windowLeft, windowBottom);
    glVertex2f(windowRight, windowBottom);
    glVertex2f(windowRight, windowTop);
    glVertex2f(windowLeft, windowTop);
    glEnd();

    adjusterX = windowRight - frameThickness - 15;
    adjusterY = windowBottom + frameThickness + 25;
    adjusterRadius = 8;
}

// Draw wall pattern to prevent airplane from showing outside the window area
void drawWallPattern() {
    // Compute mask dimensions
    float maskLeft = innerLeft;
    float maskRight = innerRight;
    float maskBottom = innerBottom;
    float maskTop = innerTop;

    // Fill masked areas with the base wall color
    setRoomLightAdjustedColor(0.9, 0.9, 0.95);

    // Left mask
    glBegin(GL_QUADS);
    glVertex2f(-WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);
    glVertex2f(maskLeft, -WINDOW_HEIGHT / 2);
    glVertex2f(maskLeft, WINDOW_HEIGHT / 2);
    glVertex2f(-WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    glEnd();

    // Right mask
    glBegin(GL_QUADS);
    glVertex2f(maskRight, -WINDOW_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    glVertex2f(maskRight, WINDOW_HEIGHT / 2);
    glEnd();

    // Top mask
    glBegin(GL_QUADS);
    glVertex2f(maskLeft, maskTop);
    glVertex2f(maskRight, maskTop);
    glVertex2f(maskRight, WINDOW_HEIGHT / 2);
    glVertex2f(maskLeft, WINDOW_HEIGHT / 2);
    glEnd();

    // Bottom mask
    glBegin(GL_QUADS);
    glVertex2f(maskLeft, -WINDOW_HEIGHT / 2);
    glVertex2f(maskRight, -WINDOW_HEIGHT / 2);
    glVertex2f(maskRight, maskBottom);
    glVertex2f(maskLeft, maskBottom);
    glEnd();

    // Step 2: Reapply the striped pattern in the masked areas
    setRoomLightAdjustedColor(0.85, 0.85, 0.9);
    float stripeWidth = 50;

    // Left mask pattern
    for (float x = -WINDOW_WIDTH / 2; x <= maskLeft; x += stripeWidth * 2) {
        glBegin(GL_QUADS);
        glVertex2f(x, -WINDOW_HEIGHT / 2);
        glVertex2f(x + stripeWidth, -WINDOW_HEIGHT / 2);
        glVertex2f(x + stripeWidth, WINDOW_HEIGHT / 2);
        glVertex2f(x, WINDOW_HEIGHT / 2);
        glEnd();
    }

    // Right mask pattern
    for (float x = maskRight; x <= WINDOW_WIDTH / 2; x += stripeWidth * 2) {
        glBegin(GL_QUADS);
        glVertex2f(x, -WINDOW_HEIGHT / 2);
        glVertex2f(x + stripeWidth, -WINDOW_HEIGHT / 2);
        glVertex2f(x + stripeWidth, WINDOW_HEIGHT / 2);
        glVertex2f(x, WINDOW_HEIGHT / 2);
        glEnd();
    }

    // Top mask pattern
    for (float x = maskLeft; x <= maskRight; x += stripeWidth * 2) {
        glBegin(GL_QUADS);
        glVertex2f(x, maskTop);
        glVertex2f(x + stripeWidth, maskTop);
        glVertex2f(x + stripeWidth, WINDOW_HEIGHT / 2);
        glVertex2f(x, WINDOW_HEIGHT / 2);
        glEnd();
    }

    // Bottom mask pattern
    for (float x = maskLeft; x <= maskRight; x += stripeWidth * 2) {
        glBegin(GL_QUADS);
        glVertex2f(x, -WINDOW_HEIGHT / 2);
        glVertex2f(x + stripeWidth, -WINDOW_HEIGHT / 2);
        glVertex2f(x + stripeWidth, maskBottom);
        glVertex2f(x, maskBottom);
        glEnd();
    }
}

// Draw the window borders on top of everything
void drawWindowBorders() {
    double w = 2 / 5.0;
    double h = 1 / 3.0;
    float left = -WINDOW_WIDTH * w;
    float right = WINDOW_WIDTH * w;
    float top = WINDOW_HEIGHT * h;
    float bottom = -WINDOW_HEIGHT * h;
    float borderThickness = 15;

    // Top border (lighter color)
    setRoomLightAdjustedColor(0.8, 0.8, 0.85);
    glBegin(GL_POLYGON);
    glVertex2f(left, top);
    glVertex2f(right, top);
    glVertex2f(right, top - borderThickness);
    glVertex2f(left, top - borderThickness);
    glEnd();

    // Left border (lighter color)
    glBegin(GL_POLYGON);
    glVertex2f(left, top);
    glVertex2f(left + borderThickness, top);
    glVertex2f(left + borderThickness, bottom);
    glVertex2f(left, bottom);
    glEnd();

    // Bottom border (darker color)
    setRoomLightAdjustedColor(0.7, 0.7, 0.75);
    glBegin(GL_POLYGON);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, bottom + borderThickness);
    glVertex2f(left, bottom + borderThickness);
    glEnd();

    // Right border (darker color)
    glBegin(GL_POLYGON);
    glVertex2f(right - borderThickness, top);
    glVertex2f(right, top);
    glVertex2f(right, bottom);
    glVertex2f(right - borderThickness, bottom);
    glEnd();

    // Inner frame border (highlight)
    setRoomLightAdjustedColor(0.8, 0.8, 0.85);
    float innerOffset = frameThickness + 2;
    glBegin(GL_POLYGON);
    glVertex2f(left + innerOffset, top - innerOffset);
    glVertex2f(right - innerOffset, top - innerOffset);
    glVertex2f(right - innerOffset, top - innerOffset - 2);
    glVertex2f(left + innerOffset, top - innerOffset - 2);
    glEnd();
}

// Draw the blinds on top of everything
void drawBlinds() {
    // Draw blinds AFTER the airplane
    int numBlinds = 12;
    float blindHeight = (windowTop - windowBottom - 2 * frameThickness) / numBlinds;
    float windowHeight = windowTop - windowBottom - 2 * frameThickness;
    float visibleHeight = windowHeight * (1.0 - blindAnimationProgress);
    int visibleBlinds = ceil(visibleHeight / blindHeight);

    for (int i = 0; i < numBlinds && i < visibleBlinds; i++) {
        float y = windowTop - frameThickness - (i + 0.5) * blindHeight;
        if (i == visibleBlinds - 1 && blindAnimationProgress > 0) {
            float partialVisibility = visibleHeight - (i * blindHeight);
            if (partialVisibility < blindHeight) {
                y = windowTop - frameThickness - i * blindHeight - partialVisibility / 2;
            }
        }
        if (i % 2 == 0) {
            setRoomLightAdjustedColor(0.93, 0.93, 0.93);
        }
        else {
            setRoomLightAdjustedColor(0.9, 0.9, 0.9);
        }
        glBegin(GL_POLYGON);
        glVertex2f(innerLeft + 5, y + blindHeight / 2 - 3);
        glVertex2f(innerRight - 5, y + blindHeight / 2 - 3);
        glVertex2f(innerRight - 5, y - blindHeight / 2 + 3);
        glVertex2f(innerLeft + 5, y - blindHeight / 2 + 3);
        glEnd();

        setRoomLightAdjustedColor(0.7, 0.7, 0.7);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(innerLeft + 5, y - blindHeight / 2 + 3);
        glVertex2f(innerRight - 5, y - blindHeight / 2 + 3);
        glVertex2f(innerRight - 5, y - blindHeight / 2 + 2);
        glVertex2f(innerLeft + 5, y - blindHeight / 2 + 2);
        glEnd();
    }

    // Top blind holder
    if (blindAnimationProgress > 0) {
        setRoomLightAdjustedColor(0.85, 0.85, 0.85);
        glBegin(GL_POLYGON);
        glVertex2f(innerLeft, innerTop - 10);
        glVertex2f(innerRight, innerTop - 10);
        glVertex2f(innerRight, innerTop);
        glVertex2f(innerLeft, innerTop);
        glEnd();
    }

    // Blind mechanism
    setRoomLightAdjustedColor(0.75, 0.75, 0.8);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(innerRight - 15, innerTop);
    glVertex2f(innerRight - 15, innerBottom);
    glEnd();

    // Blind adjuster
    if (blindsOpen) {
        setRoomLightAdjustedColor(0.5, 0.7, 0.5);
    }
    else {
        setRoomLightAdjustedColor(0.6, 0.6, 0.65);
    }
    circle(innerRight - 15, innerBottom + 25, 8);
    setRoomLightAdjustedColor(0.8, 0.8, 0.85);
    circle(innerRight - 13, innerBottom + 27, 3);
}

// Draw the switch to control the light
void drawSwitch() {
    const int paddingX = 20;
    const int paddingY = 30;
    switchX = right + wallThickness + 50;
    switchY = (top + bottom) / 2;

    // Draw Switch
    setRoomLightAdjustedColor(0.95, 0.95, 0.95);
    glBegin(GL_POLYGON);
    glVertex2f(switchX - paddingX, switchY + paddingY);
    glVertex2f(switchX + paddingX, switchY + paddingY);
    glVertex2f(switchX + paddingX, switchY - paddingY);
    glVertex2f(switchX - paddingX, switchY - paddingY);
    glEnd();

    setRoomLightAdjustedColor(0.7, 0.7, 0.7);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(switchX - paddingX, switchY + paddingY);
    glVertex2f(switchX + paddingX, switchY + paddingY);
    glVertex2f(switchX + paddingX, switchY - paddingY);
    glVertex2f(switchX - paddingX, switchY - paddingY);
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
        vprint(switchX - 25, switchY - 45, GLUT_BITMAP_HELVETICA_10, "LIGHT: ON");
    }
    else {
        vprint(switchX - 25, switchY - 45, GLUT_BITMAP_HELVETICA_10, "LIGHT: OFF");
    }
}

// Combines all window drawing elements in proper order
void drawWindow() {
    glPointSize(10);
    glLineWidth(5);

    // First draw the window frame and background
    drawWindowFrame();

	// Draw the sky
	drawSky();

	// Draw the mountain
	drawMountain();

    // Draw the airplane
    drawAirplane(planeX, planeY);

    // Draw masks to hide parts of the airplane outside the window
    drawWallPattern();

    // Draw window borders on top
    drawWindowBorders();

    // Draw blinds on top of everything
    drawBlinds();

	drawSwitch();
}

// Timer function to animate the blinds
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

// Timer function to animate the airplane
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

// Mouse click event handler for blinds and light switch
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

// Special key event handler for F1 key to start the airplane animation
void onSpecialKeyDown(int key, int x, int y) {
    if (key == GLUT_KEY_F1 && planeX == planeXStart) {
        planeAnimationActive = true;
        planeX = planeXStart; // Reset position
        movingRight = true;
    }
    glutPostRedisplay();
}

// Keyboard event handler for ESC key to exit the program
void onKeyDown(unsigned char key, int x, int y) {
    if (key == 27) // ESC
        exit(0);
    else if (key == ' ' && planeX != planeXStart)
        planeAnimationActive = !planeAnimationActive;
    glutPostRedisplay();
}

// Print debug information on the screen
void printDebugPrint() {
    glColor3f(0, 0, 0);
    vprint(-WINDOW_WIDTH / 2 + 10, -WINDOW_HEIGHT / 2 + 20, GLUT_BITMAP_HELVETICA_12,
        "F1: Start Animation, SPACEBAR: Pause/Resume, ESC: Exit");
    vprint(-WINDOW_WIDTH / 2 + 10, -WINDOW_HEIGHT / 2 + 40, GLUT_BITMAP_HELVETICA_12,
        "Click on the blind knob to open/close blinds. Animation Active: %s",
        planeAnimationActive ? "Yes" : "No");
}

void display() {
    float effectiveRoomLight = getEffectiveRoomLight();
    glClearColor(0.8 * effectiveRoomLight, 0.8 * effectiveRoomLight, 0.8 * effectiveRoomLight, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

	// Initialize window dimensions before drawing
    initializeWindowDimensions();

    // Draw window, airplane, masks and borders
    drawWindow();

	// Draw name and surname label
    createNameSurnameLabel();

	// Draw debug printing statements
    printDebugPrint();

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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    glutCreateWindow("CTIS164 HW1 - Sezer Tetik - 22303222");
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
