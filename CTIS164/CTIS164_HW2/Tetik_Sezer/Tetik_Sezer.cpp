/********************
   CTIS164 - HOMEWORK 2 | Hit the Target Game
   OWNER: Sezer Tetik - 22303222 - Section 04
********************/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "Tetik_Sezer.h"

#define GAME_TIME 3

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define TIMER_PERIOD   15     // Period for the timer
#define PI  3.14159265358

#define Y_MARGIN 35           // Height of bow
#define HG      5.0f          // Half Gravity

#define MAX_BALLOONS 5
#define BALLOON_RADIUS  35
#define SPAWN_ATTEMPTS  25

#define ARROW_TAIL_OFFSET  -30.0f  // x-offset from Cx to the back end
#define ARROW_TIP_OFFSET    70.0f  // x-offset from Cx to the front tip (20 + xPadding)

#define BOW_START_X -350
#define BOW_START_Y 35
#define CLOUD_START_X -350
#define CLOUD_START_Y 0

#define INFO_MISS_CONTAINER_TIME 2000
#define MISS_SCORE_PENALIZE 5
#define MISS_TIME_PENALIZE 3

#define HIT_SCORE_BONUS 3
#define HIT_TIME_BONUS 1

typedef struct {
	float x, y;
	float speed;
	bool active;
} Balloon;

Balloon balloons[MAX_BALLOONS];

#define MAX_FEEDBACKS 20

typedef struct {
	float x, y;     // screen position
	float t;        // elapsed time (in seconds)
	bool active;
} Feedback;

Feedback feedbacks[MAX_FEEDBACKS];


// Global variables for Template File
int  winWidth, winHeight;     // Current Window width and height

float Cx = -350, Cy = 0;      // Coordinates of the platform
float Bx = -350, By = 35; // x and y coordinate of the cannonball
float c, h, k;                // Parameters of the quadratic equation
float timeVar = 0;

int   Vx = 900;                // Horizontal firing speed
int   steps;

bool isPaused = false;
bool  animation = false;      // Flag to show if the cannonball is fired/active
bool  gameover = false;       // Flag for game status

int remainingTime = GAME_TIME;
int poppedBalloons = 0;

bool ballonHit = false; // Flag to show if a balloon is hit
int score = 0;
bool showMissInfo = false;

void restartGame();
void giveHitBonus();
void penalizeMiss();

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

void print(int x, int y, const char* string, void* font) {
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, string[i]);
}

// To display text with variables
void vprint(int x, int y, void* font, const char* string, ...) {
	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);

	print(x, y, str, font);
}

void drawGradient(int x1, int y1, int w, int h, float r, float g, float b) {
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2f(x1, y1);
	glVertex2f(x1 + w, y1);
	glColor3f(r + 0.4, g + 0.4, b + 0.4);
	glVertex2f(x1 + w, y1 - h);
	glVertex2f(x1, y1 - h);
	glEnd();

	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glVertex2f(x1 + w, y1);
	glVertex2f(x1 + w, y1 - h);
	glVertex2f(x1, y1 - h);
	glEnd();
}

void addFeedback(float x, float y) {
	for (int i = 0; i < MAX_FEEDBACKS; ++i) {
		if (!feedbacks[i].active) {
			feedbacks[i].active = true;
			feedbacks[i].x = x;
			feedbacks[i].y = y;
			feedbacks[i].t = 0.0f;
			break;
		}
	}
}

void checkBalloonHits() {
	// Endpoints of the arrow line segment:
	float x1 = Bx + ARROW_TAIL_OFFSET, y1 = By;
	float x2 = Bx + ARROW_TIP_OFFSET, y2 = By;
	float dx = x2 - x1, dy = y2 - y1;
	float segLen2 = dx * dx + dy * dy;  // squared length

	for (int i = 0; i < MAX_BALLOONS; ++i) {
		if (!balloons[i].active) continue;

		float px = balloons[i].x, py = balloons[i].y;
		// project point onto the line, computing parameter t:
		float t = ((px - x1) * dx + (py - y1) * dy) / segLen2;
		if (t < 0.0f) t = 0.0f;
		else if (t > 1.0f) t = 1.0f;

		// find closest point on segment:
		float projX = x1 + t * dx;
		float projY = y1 + t * dy;

		// squared distance from balloon center to that point
		float ddx = px - projX;
		float ddy = py - projY;
		if (ddx * ddx + ddy * ddy <= BALLOON_RADIUS * BALLOON_RADIUS) {
			poppedBalloons++; // Pop!
			balloons[i].active = false;
			ballonHit = true;
			showMissInfo = false; // Reset miss info if it was shown
			giveHitBonus();
			addFeedback(px, py); 
			glutPostRedisplay();
		}
	}
}

void initBalloons() {
	srand(time(NULL));
	for (int i = 0; i < MAX_BALLOONS; ++i)
		balloons[i].active = false;
}

void spawnBalloon() {
	int activeCount = 0;
	for (int i = 0; i < MAX_BALLOONS; ++i)
		if (balloons[i].active) ++activeCount;

	if (activeCount >= MAX_BALLOONS) return;

	// random chance to spawn ballon for each frame (%6)
	if (rand() % 100 > 6) return;

	// find a free slot
	for (int i = 0; i < MAX_BALLOONS; ++i) {
		if (!balloons[i].active) {
			// compute horizontal bounds on right half
			float margin = BALLOON_RADIUS;
			float xMin = 0;
			float xMax = (winWidth / 2.0f) - margin;

			// try up to SPAWN_ATTEMPTS times
			float candidateX;
			bool placed = false;
			for (int attempt = 0; attempt < SPAWN_ATTEMPTS; ++attempt) {
				candidateX = xMin + (rand() / (float)RAND_MAX) * (xMax - xMin);

				// check distance to all other active balloons
				bool collides = false;
				for (int j = 0; j < MAX_BALLOONS; ++j) {
					if (!balloons[j].active) continue;
					float dx = candidateX - balloons[j].x;
					// since all start at same y, only x matters here
					if (fabsf(dx) < 1.75 * BALLOON_RADIUS) {
						collides = true;
						break;
					}
				}
				if (!collides) {
					placed = true;
					break;
				}
			}

			// if we failed to find a non-colliding spot, skip spawn
			if (!placed) return;

			// activate and initialize
			balloons[i].active = true;
			balloons[i].x = candidateX;
			balloons[i].y = -winHeight / 2.0f - BALLOON_RADIUS;
			//balloons[i].speed = 0.5f + (rand() / (float)RAND_MAX);
			balloons[i].speed = 3;
			break;
		}
	}
}

void updateBalloons() {
	float off = 10.0f;  // balloon radius + small buffer
	for (int i = 0; i < MAX_BALLOONS; ++i) {
		if (!balloons[i].active) continue;
		// move up
		balloons[i].y += balloons[i].speed;
		// if passed top edge, deactivate
		if (balloons[i].y > WINDOW_HEIGHT / 2.0f + off)
			balloons[i].active = false;
	}
	spawnBalloon();
}

void drawSingleBalloon(float x, float y) {
	// balloon circle
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	circle(x, y, BALLOON_RADIUS);
	glEnd();
	// string
	glColor3f(0, 0, 0);
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	glVertex2f(x, y - BALLOON_RADIUS);
	glVertex2f(x, y - BALLOON_RADIUS - 30);
	glEnd();
}

void drawBalloons() {
	for (int i = 0; i < MAX_BALLOONS; ++i)
		if (balloons[i].active)
			drawSingleBalloon(balloons[i].x, balloons[i].y);
}

void resetArrow() {
	animation = false;
	Bx = Cx;
	By = Cy + Y_MARGIN;
	timeVar = 0;

	if (!ballonHit)
		penalizeMiss();
	else
		ballonHit = false;
}

void resetBow() {
	Bx = BOW_START_X;
	By = BOW_START_Y;
	Cx = CLOUD_START_X;
	Cy = CLOUD_START_Y;
}

void resetTimer() {
	isPaused = false;
	gameover = false;
	remainingTime = GAME_TIME;
}

void resetFeedbacks() {
	for (int i = 0; i < MAX_FEEDBACKS; ++i)
		feedbacks[i].active = false;
}

void resetBalloons() {
	for (int i = 0; i < MAX_BALLOONS; ++i)
		balloons[i].active = false;
}

void resetScore() {
	score = 0;
	poppedBalloons = 0;
	ballonHit = false;
	showMissInfo = false;
}

void restartGame() {
	resetArrow();
	resetBow();
	resetTimer();
	resetFeedbacks();
	resetBalloons();
	resetScore();
}

void drawCloud(int x, int y) {
	glColor3f(1, 1, 1); // White
	circle(0 + x, 0 + y, 30);
	circle(-25 + x, y, 20);
	circle(25 + x, -2 + y, 20);
	circle(21 + x, -19 + y, 10);
}

void drawBackground() {
	drawGradient(-400, 300, 800, 600, 0.4, 0.4, 0.9); // Sky

	// My name
	glColor3f(1, 1, 1);
	print(-100, 275, "Sezer Tetik", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawTopPanel() {
	const int topPanelYCenter = 270;

	// Top info panel
	glColor3f(0.15f, 0.15f, 0.4f);
	glRectf(-400, 250, 400, 300);

	glColor3f(1.0f, 0.85f, 0.4f);
	vprint(-380, topPanelYCenter, GLUT_BITMAP_9_BY_15, "Score: %d", score);
	vprint(-140, topPanelYCenter, GLUT_BITMAP_9_BY_15, "Popped Ballons: %d", poppedBalloons);

	if (remainingTime < 0) 
		remainingTime = 0; // to show proper time

	vprint(180, topPanelYCenter, GLUT_BITMAP_9_BY_15, "Remaining Time: %d sec", remainingTime);

	glColor3f(0, 0, 0);
	vprint(-380, topPanelYCenter - 50, GLUT_BITMAP_9_BY_15, "SEZER TETIK");
}

void drawBottomPanel() {
	// Bottom info panel
	glColor3f(0.15f, 0.15f, 0.4f);
	glRectf(-400, -280, 400, -300);

	glColor3f(1.0f, 0.85f, 0.4f);
	if (gameover)
		print(-380, -295, "Press F1 to restart the game", GLUT_BITMAP_8_BY_13);
	else
		print(-380, -295, "SpaceBar: Fire        Up/Down: Bow Location        F1: Pause/Resume", GLUT_BITMAP_8_BY_13);
}

void drawPanels() {
	drawTopPanel();
	drawBottomPanel();
}

void drawTransparentContainer(int x1, int x2, int y1, int y2, float t) {
	//glColor4f(0, 0, 0, t);
	glColor4f(0.15f, 0.15f, 0.4f, t);
	glRectf(x1, y1, x2, y2);
}

void drawTransparentContainer() {
	drawTransparentContainer(-400, 400, -280, 250, 0.5);
}

void drawPausedContainer() {
	drawTransparentContainer();

	glColor4f(1, 1, 1, 0.5);
	vprint(-80, 25, GLUT_BITMAP_TIMES_ROMAN_24, "GAME PAUSED!");
	vprint(-82, 0, GLUT_BITMAP_9_BY_15, "Press F1 to continue");
}

void drawBow(int y) {
	const float cy = (float)y;
	const float radius = 40.0f;
	const int   segments = 50; // for smoothnes

	// 1) The bow limb
	glColor3f(0.55f, 0.27f, 0.07f);  // dark brown
	glLineWidth(4.0f);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= segments; ++i) {
		float t = -PI / 2 + PI * (float)i / (float)segments;
		float x = Cx + radius * cos(t);
		float z = cy + radius * sin(t);
		glVertex2f(x, z);
	}
	glEnd();

	// 2) Bowstring
	glColor3f(0.8f, 0.8f, 0.8f);     // light gray
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	glVertex2f(Cx, cy + radius);   // top
	glVertex2f(Cx, cy - radius);   // bottom
	glEnd();
}

void drawPlatform(int y) {
	drawBow(y + Y_MARGIN);
	drawCloud(Cx, y - Y_MARGIN);
}

void drawArrow() {
	const int xPadding = 50;

	// Arrow shaft
	glColor3f(0.6f, 0.4f, 0.2f); // Brown
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex2f(Bx - 30, By);
	glVertex2f(Bx + 10 + xPadding, By);
	glEnd();

	// Arrow head (triangle)
	glColor3f(0, 0, 0); // Gray arrowhead
	glBegin(GL_TRIANGLES);
	glVertex2f(Bx + 20 + xPadding, By);
	glVertex2f(Bx + 10 + xPadding, By + 5);
	glVertex2f(Bx + 10 + xPadding, By - 5);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f); // Red feathers
	glBegin(GL_TRIANGLES);

	// Top feather
	glVertex2f(Bx - 20, By);
	glVertex2f(Bx - 30, By);
	glVertex2f(Bx - 25, By + 8);

	// Bottom feather
	glVertex2f(Bx - 20, By);
	glVertex2f(Bx - 30, By);
	glVertex2f(Bx - 25, By - 8);
	glEnd();
}

void constructEquation() {
	c = -HG / ((Vx * Vx) / 36);
	h = Bx;
	k = By;
}

/*****************************************************************
   Find the y coordinate of the cannonball using its x coordinate,
   this is the main quadratic function that represents the path
   of the projectile motion.
*****************************************************************/
float fx(float x) {
	return c * (x - h) * (x - h) + k;
}

void penalizeMiss() {
	showMissInfo = true;
	score -= MISS_SCORE_PENALIZE;
	remainingTime -= MISS_TIME_PENALIZE;
	glutPostRedisplay();
}

void giveHitBonus() {
	score += HIT_SCORE_BONUS;
	remainingTime += HIT_TIME_BONUS;
	glutPostRedisplay();
}

void drawMissInfoPanel() {
	drawTransparentContainer(-400, 400, -280, -240, 0.8);
	glColor3f(1.0f, 0.3f, 0.3f);
	vprint(-380, -270, GLUT_BITMAP_TIMES_ROMAN_24, "You missed the ballons!");
	vprint(-100, -267, GLUT_BITMAP_9_BY_15, "You have penalized %d score, and %d seconds of time!", MISS_SCORE_PENALIZE, MISS_TIME_PENALIZE);
}

void drawFeedbacks() {
	for (int i = 0; i < MAX_FEEDBACKS; ++i) {
		if (!feedbacks[i].active) continue;
		float progress = feedbacks[i].t;
		float rise = 50.0f * progress;       // pixels to move up
		float alpha = 1.0f - progress;        // animation

		if (feedbacks[i].x + 550 >= WINDOW_WIDTH)
			feedbacks[i].x = WINDOW_WIDTH - 550;

		glColor4f(0, 1, 0, alpha);    // green
		vprint(
			(int)feedbacks[i].x,
			(int)(feedbacks[i].y + 2 * rise),
			GLUT_BITMAP_HELVETICA_18,
			"+%d seconds",
			HIT_TIME_BONUS
		);

		vprint(
			(int)feedbacks[i].x + 50,
			(int)(feedbacks[i].y + 2 * rise + 18),
			GLUT_BITMAP_HELVETICA_18,
			"+%d score",
			HIT_SCORE_BONUS
		);
	}
}

void display() {
	glClearColor(0.8, 0.8, 0.8, 0.8);
	glClear(GL_COLOR_BUFFER_BIT);

	drawBackground();
	drawBalloons();
	drawPlatform(Cy);
	drawArrow();
	drawPanels();

	drawFeedbacks();
	
	if (showMissInfo && !ballonHit)
		drawMissInfoPanel();

	if (isPaused && !gameover)
		drawPausedContainer();

	if (gameover) {
		drawTransparentContainer();
		glColor3f(1.0f, 0.85f, 0.4f);
		vprint(-60, 25, GLUT_BITMAP_TIMES_ROMAN_24, "TIME IS UP!!");
		vprint(-110, 0, GLUT_BITMAP_9_BY_15, "You have scored %d points!", score);
	}

	glutSwapBuffers();
}

void onKeyDown(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);

	if (key == ' ' && !isPaused)
		animation = true;

	glutPostRedisplay();
}

void onSpecialKeyDown(int key, int x, int y) {
	if (key == GLUT_KEY_F1)
		if (gameover)
			restartGame();
		else
			isPaused = !isPaused;

	if (!isPaused && !gameover && !animation) {
		switch (key) {
		case GLUT_KEY_UP:
			Cy += 5;
			if (Cy > 165)
				Cy = 165;
			By = Cy + Y_MARGIN;
			break;
		case GLUT_KEY_DOWN:
			Cy -= 5;
			if (Cy < -180)
				Cy = -180;
			By = Cy + Y_MARGIN;
			break;
		}

		constructEquation();
	}

	glutPostRedisplay();
}

void updateFeedbacks(float dt) {
	for (int i = 0; i < MAX_FEEDBACKS; ++i) {
		if (!feedbacks[i].active) continue;
		feedbacks[i].t += dt;
		if (feedbacks[i].t >= 1.0f)
			feedbacks[i].active = false;
	}
}

void onTimer(int v) {
	glutTimerFunc(TIMER_PERIOD, onTimer, 0);
	float dt = TIMER_PERIOD / 1000.0f;

	static int timeAccumulator = 0;
	static int missInfoTimeAccumulator = 0;
	if (!gameover && !isPaused) {
		timeAccumulator += TIMER_PERIOD;

		if (timeAccumulator >= 1000) {
			remainingTime--;
			timeAccumulator = 0;
		}

		if (remainingTime <= 0) {
			gameover = true;
			remainingTime = 0; // to show proper time
		}

		if (showMissInfo && !ballonHit) {
			missInfoTimeAccumulator += TIMER_PERIOD;
			if (missInfoTimeAccumulator >= INFO_MISS_CONTAINER_TIME) {
				showMissInfo = false;
				missInfoTimeAccumulator = 0;
			}
		}
		else
			missInfoTimeAccumulator = 0;

		if (animation) {
			// move arrow:
			Bx += Vx * TIMER_PERIOD / 1000.0;
			By = fx(Bx);

			// check for balloon hits:
			checkBalloonHits();

			// reset arrow if it goes off screen
			if (By < -WINDOW_HEIGHT / 2 || Bx - Y_MARGIN - 15 > WINDOW_WIDTH / 2)
				resetArrow();
		}

		// move balloons & spawn new ones
		updateBalloons();
	}

	if (!gameover && !isPaused) {
		updateFeedbacks(dt);
	}
	glutPostRedisplay();
}

void onResize(int w, int h) {
	winWidth = w;
	winHeight = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	display(); // Refresh window
}

void initFeedbacks() {
	for (int i = 0; i < MAX_FEEDBACKS; ++i)
		feedbacks[i].active = false;
}

void init() {
	// Smoothing shapes
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	constructEquation();
	initBalloons();
	initFeedbacks();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(500, 200);
	glutCreateWindow("Sezer Tetik | Hit the Target Game | CTIS164 - HW2");

	glutDisplayFunc(display);
	glutReshapeFunc(onResize);

	// Keyboard Events
	glutKeyboardFunc(onKeyDown);
	glutSpecialFunc(onSpecialKeyDown);

	// Timer Event
	glutTimerFunc(TIMER_PERIOD, onTimer, 0);

	init();
	glutMainLoop();
	return 0;
}