/*********************************************
   CTIS164 - Lab02
   OpenGL: Drawing different primitive shapes
*********************************************/
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define WINDOW_WIDTH  1200
#define WINDOW_HEIGHT 800
#define D2R 0.01745329252
#define PI  3.14159265358

// Global variables for blind state
bool blindsOpen = false;  // blinds start closed
float blindAnimationProgress = 0.0;  // 0.0 is fully closed, 1.0 is fully open
const float ANIMATION_SPEED = 0.05;  // How quickly blinds open/close
float adjusterX, adjusterY;
float adjusterRadius;
float frameThickness = 15;

// Global variables for light state
bool lightOn = true;  // Start with light on
float lightLevel = 1.0; // Full brightness
float switchX, switchY;
float switchRadius = 12;

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

	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
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

    // Draw wall pattern
    glColor3f(0.9 * lightLevel, 0.9 * lightLevel, 0.95 * lightLevel); // Base wall color

    // Calculate pattern area dimensions
    float patternLeft = left - wallThickness - 200;
    float patternRight = right + wallThickness + 200;
    float patternTop = top + wallThickness + 150;
    float patternBottom = bottom - wallThickness - 150;

    // Draw wall background first
    glBegin(GL_POLYGON);
    glVertex2f(patternLeft, patternTop);
    glVertex2f(patternRight, patternTop);
    glVertex2f(patternRight, patternBottom);
    glVertex2f(patternLeft, patternBottom);
    glEnd();

    // Draw vertical stripes on wall
    glColor3f(0.85 * lightLevel, 0.85 * lightLevel, 0.9 * lightLevel); // Slightly darker for pattern
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
    glColor3f(0.95 * lightLevel, 0.95 * lightLevel, 0.95 * lightLevel);
    glBegin(GL_POLYGON);
    glVertex2f(switchX - 20, switchY + 30);
    glVertex2f(switchX + 20, switchY + 30);
    glVertex2f(switchX + 20, switchY - 30);
    glVertex2f(switchX - 20, switchY - 30);
    glEnd();

    // Switch border
    glColor3f(0.7 * lightLevel, 0.7 * lightLevel, 0.7 * lightLevel);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(switchX - 20, switchY + 30);
    glVertex2f(switchX + 20, switchY + 30);
    glVertex2f(switchX + 20, switchY - 30);
    glVertex2f(switchX - 20, switchY - 30);
    glEnd();

    // Switch button
    if (lightOn) {
        glColor3f(0.2 * lightLevel + 0.3, 0.6 * lightLevel + 0.3, 0.2 * lightLevel + 0.3); // Green when on
    }
    else {
        glColor3f(0.7 * lightLevel, 0.2 * lightLevel, 0.2 * lightLevel); // Red when off
    }

    circle(switchX, switchY, switchRadius);

    // Switch button highlight
    glColor3f((0.9 + 0.1 * lightLevel), (0.9 + 0.1 * lightLevel), (0.9 + 0.1 * lightLevel));
    circle(switchX - 3, switchY + 3, 4);

    // Draw switch label
    glColor3f(0.3 * lightLevel, 0.3 * lightLevel, 0.3 * lightLevel);
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

    // Outer window frame (wall)
    glColor3f(0.85, 0.85, 0.9);  // Light blue-gray
    float wallThickness = 25;
    glRectf(left - wallThickness, bottom - wallThickness,
        right + wallThickness, top + wallThickness);

    // Window frame
    glColor3f(0.7, 0.7, 0.75);  // Medium gray for frame
    glRectf(left, bottom, right, top);

    // Inner window area (glass)
    glColor3f(0.8, 0.9, 1.0);  // Light blue for glass
    float frameThickness = 15;
    glRectf(left + frameThickness, bottom + frameThickness,
        right - frameThickness, top - frameThickness);

    // Window frame shadow/highlight effects
    glLineWidth(2);
    // Top highlight
    glColor3f(0.9, 0.9, 0.95);
    glBegin(GL_LINES);
    glVertex2f(left + 2, top - 2);
    glVertex2f(right - 2, top - 2);
    glEnd();

    // Left highlight
    glBegin(GL_LINES);
    glVertex2f(left + 2, top - 2);
    glVertex2f(left + 2, bottom + 2);
    glEnd();

    // Bottom shadow
    glColor3f(0.5, 0.5, 0.55);
    glBegin(GL_LINES);
    glVertex2f(left + 2, bottom + 2);
    glVertex2f(right - 2, bottom + 2);
    glEnd();

    // Right shadow
    glBegin(GL_LINES);
    glVertex2f(right - 2, top - 2);
    glVertex2f(right - 2, bottom + 2);
    glEnd();

    // Inner frame highlight/shadow
    // Top inner highlight
    glColor3f(0.8, 0.8, 0.85);
    glBegin(GL_LINES);
    glVertex2f(left + frameThickness + 2, top - frameThickness - 2);
    glVertex2f(right - frameThickness - 2, top - frameThickness - 2);
    glEnd();

    // Roller blinds
    int numBlinds = 12;  // More blinds for a sleeker look
    float blindHeight = (top - bottom - 2 * frameThickness) / numBlinds;
    float windowHeight = top - bottom - 2 * frameThickness;

    // Calculate how much of the blinds to show based on animation progress
    float visibleHeight = windowHeight * (1.0 - blindAnimationProgress);
    int visibleBlinds = ceil(visibleHeight / blindHeight);

    // Draw each blind slat (only if it should be visible)
    for (int i = 0; i < numBlinds && i < visibleBlinds; i++) {
        float y = top - frameThickness - (i + 0.5) * blindHeight;

        // Special case for the last partially visible blind
        if (i == visibleBlinds - 1 && blindAnimationProgress > 0) {
            float partialVisibility = visibleHeight - (i * blindHeight);
            if (partialVisibility < blindHeight) {
                // Only show part of this blind
                y = top - frameThickness - i * blindHeight - partialVisibility / 2;
            }
        }

        // Modern gradient effect for blinds
        if (i % 2 == 0) {
            glColor3f(0.93, 0.93, 0.93);  // Slightly lighter for alternating blinds
        }
        else {
            glColor3f(0.9, 0.9, 0.9);
        }

        // Draw the blind slat
        glBegin(GL_POLYGON);
        glVertex2f(left + frameThickness + 5, y + blindHeight / 2 - 3);
        glVertex2f(right - frameThickness - 5, y + blindHeight / 2 - 3);
        glVertex2f(right - frameThickness - 5, y - blindHeight / 2 + 3);
        glVertex2f(left + frameThickness + 5, y - blindHeight / 2 + 3);
        glEnd();

        // Add some 3D effect with slightly darker lines
        glColor3f(0.7, 0.7, 0.7);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(left + frameThickness + 5, y - blindHeight / 2 + 3);
        glVertex2f(right - frameThickness - 5, y - blindHeight / 2 + 3);
        glEnd();
    }

    // Draw rolled up blinds at the top when partially or fully open
    if (blindAnimationProgress > 0) {
        glColor3f(0.85, 0.85, 0.85);
        glRectf(left + frameThickness, top - frameThickness - 10,
            right - frameThickness, top - frameThickness);
    }

    // Modern blind control mechanism
    glColor3f(0.75, 0.75, 0.8);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(right - frameThickness - 15, top - frameThickness);
    glVertex2f(right - frameThickness - 15, bottom + frameThickness);
    glEnd();

    // Blind adjuster (modern cylindrical knob)
    // Change color when blinds are open
    if (blindsOpen) {
        glColor3f(0.5, 0.7, 0.5);  // Greenish when open
    }
    else {
        glColor3f(0.6, 0.6, 0.65);  // Gray when closed
    }
    circle(right - frameThickness - 15, bottom + frameThickness + 25, 8);
    glColor3f(0.8, 0.8, 0.85);  // Highlight
    circle(right - frameThickness - 13, bottom + frameThickness + 27, 3);

    // Reset line width
    glLineWidth(5);
}

// Timer function to animate the blinds
void onTimer(int v) {
    // Update blind animation progress
    if (blindsOpen) {
        // Opening blinds
        blindAnimationProgress += ANIMATION_SPEED;
        if (blindAnimationProgress > 1.0)
            blindAnimationProgress = 1.0;
    }
    else {
        // Closing blinds
        blindAnimationProgress -= ANIMATION_SPEED;
        if (blindAnimationProgress < 0.0)
            blindAnimationProgress = 0.0;
    }

    // Continue animation if not complete
    if ((blindsOpen && blindAnimationProgress < 1.0) ||
        (!blindsOpen && blindAnimationProgress > 0.0)) {
        glutTimerFunc(16, onTimer, 0);  // ~60fps
    }

    // Redraw
    glutPostRedisplay();
}

// Mouse click handler
void onClick(int button, int state, int x, int y) {
    // Convert window coordinates to our coordinate system
    int wx = x - WINDOW_WIDTH / 2;
    int wy = WINDOW_HEIGHT / 2 - y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Check if click is on the adjuster
        if (isInsideCircle(wx, wy, adjusterX, adjusterY, adjusterRadius)) {
            // Toggle blinds state
            blindsOpen = !blindsOpen;

            // Start animation
            glutTimerFunc(16, onTimer, 0);
        }
        // Check if click is on the light switch
        else if (isInsideCircle(wx, wy, switchX, switchY, switchRadius)) {
            // Toggle light state
            lightOn = !lightOn;

            // Adjust light level
            if (lightOn)
                lightLevel = 1.0; // Full brightness
            else
                lightLevel = 0.4; // Dim lighting

            glutPostRedisplay();
        }
    }

    glutPostRedisplay();
}

// To display onto window using OpenGL commands
void display() {
    // Draw window
    glClearColor(0.8 * lightLevel, 0.8 * lightLevel, 0.8 * lightLevel, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawWallAndSwitch();
    drawWindow();
    createNameSurnameLabel();

    glutSwapBuffers();
}

// Key function for ASCII charachters like ESC, a,b,c..,A,B,..Z
void onKeyDown(unsigned char key, int x, int y) {
	// Exit when ESC is pressed.
	if (key == 27)
		exit(0);

	// To refresh the window it calls display() function
	glutPostRedisplay();
}

// This function is called when the window size changes.
// w : is the new width of the window in pixels.
// h : is the new height of the window in pixels.
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

	//Smoothing shapes
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_LINE_SMOOTH);
	//glEnable(GL_POLYGON_SMOOTH);
	//glEnable(GL_POINT_SMOOTH);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	Init();

	// Window Events
	glutDisplayFunc(display);
	glutReshapeFunc(onResize);

	// Keyboard Events
	glutKeyboardFunc(onKeyDown);

    glutMouseFunc(onClick);
    glutTimerFunc(0, onTimer, 0);
	
    glutMainLoop();
	return 0;
}