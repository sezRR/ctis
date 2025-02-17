/* GL02Primitive.cpp: Vertex, Primitive and Color
 * Draw Simple 2D colored Shapes: quad, triangle and polygon. */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

 /* Handler for window-repaint event. Call back when the window first appears and
	whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0, 0.0, 0.0, 1.0);	// Black and opaque
	glClear(GL_COLOR_BUFFER_BIT);		// Clear the color buffer with current clearing color

	// Define shapes enclosed within a pair of glBegin and glEnd
	glBegin(GL_QUADS);				// Each set of 4 vertices form a quad
	glColor3f(1.0, 0.0, 0.0);	// Red
	glVertex2f(-0.8, 0.1);		// Define vertices in counter-clockwise (CCW) order
	glVertex2f(-0.2, 0.1);		// so that the normal (front-face) is facing you
	glVertex2f(-0.2, 0.7);
	glVertex2f(-0.8, 0.7);

	glColor3f(0.0, 1.0, 0.0);	// Green
	glVertex2f(-0.7, -0.6);
	glVertex2f(-0.1, -0.6);
	glVertex2f(-0.1, 0.0);
	glVertex2f(-0.7, 0.0);

	glColor3f(0.2, 0.2, 0.2);	// Dark Gray
	glVertex2f(-0.9, -0.7);
	glColor3f(1.0, 1.0, 1.0);	// White
	glVertex2f(-0.5, -0.7);
	glColor3f(0.2, 0.2, 0.2);	// Dark Gray
	glVertex2f(-0.5, -0.3);
	glColor3f(1.0, 1.0, 1.0);	// White
	glVertex2f(-0.9, -0.3);
	glEnd();

	glBegin(GL_TRIANGLES);			// Each set of 3 vertices form a triangle
	glColor3f(0.0, 0.0, 1.0);	// Blue
	glVertex2f(0.1, -0.6);
	glVertex2f(0.7, -0.6);
	glVertex2f(0.4, -0.1);

	glColor3f(1.0, 0.0, 0.0);	// Red
	glVertex2f(0.3, -0.4);
	glColor3f(0.0, 1.0, 0.0);	// Green
	glVertex2f(0.9, -0.4);
	glColor3f(0.0, 0.0, 1.0);	// Blue
	glVertex2f(0.6, -0.9);
	glEnd();

	glBegin(GL_POLYGON);			// These vertices form a closed polygon
	glColor3f(1.0, 1.0, 0.0);	// Yellow
	glVertex2f(0.4, 0.2);
	glVertex2f(0.6, 0.2);
	glVertex2f(0.7, 0.4);
	glVertex2f(0.6, 0.6);
	glVertex2f(0.4, 0.6);
	glVertex2f(0.3, 0.4);
	glEnd();

	glFlush();  // Render now
	glutSwapBuffers();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutInitWindowSize(600, 600);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title

	glutDisplayFunc(display);       // Register callback handler for window re-paint event

	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}