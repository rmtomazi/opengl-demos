/**
 * This demo shows how to periodically call an update() function to create
 * animations over time. In this case, the animation is to rotate a red square.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

// Constants to define the width/height of the window
const int WIDTH = 800;
const int HEIGHT = 800;

// Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 60;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

// Control the angle to rotate the red square
float angle = 0;

float angleX = 0.0, angleY = 0.0, angleZ = 0.0;
float sumX = 0.0, sumY = 0.0, sumZ = 0.0;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-10.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -10.0);
	glEnd();
}

void wireCube(float size){
	glColor3f(1, 0, 0);
	//Quadrado Frontal
	glBegin(GL_LINES);
		glVertex3f(size/2, size/2, -size/2);
		glVertex3f(size/2, -size/2, -size/2);

		glVertex3f(size/2, -size/2, -size/2);
		glVertex3f(-size/2, -size/2, -size/2);
		
		glVertex3f(-size/2, -size/2, -size/2);
		glVertex3f(-size/2, size/2, -size/2);

		glVertex3f(-size/2, size/2, -size/2);
		glVertex3f(size/2, size/2, -size/2);
	glEnd();

	//Quadrado Traseiro
	glBegin(GL_LINES);
		glVertex3f(size/2, size/2, size/2);
		glVertex3f(size/2, -size/2, size/2);

		glVertex3f(size/2, -size/2, size/2);
		glVertex3f(-size/2, -size/2, size/2);
		
		glVertex3f(-size/2, -size/2, size/2);
		glVertex3f(-size/2, size/2, size/2);

		glVertex3f(-size/2, size/2, size/2);
		glVertex3f(size/2, size/2, size/2);
	glEnd();

	//Ligação entre os quadrados
	glBegin(GL_LINES);
		glVertex3f(size/2, size/2, size/2);
		glVertex3f(size/2, size/2, -size/2);

		glVertex3f(size/2, -size/2, size/2);
		glVertex3f(size/2, -size/2, -size/2);
		
		glVertex3f(-size/2, size/2, size/2);
		glVertex3f(-size/2, size/2, -size/2);

		glVertex3f(-size/2, -size/2, size/2);
		glVertex3f(-size/2, -size/2, -size/2);
	glEnd();
}

void display()
{
	// Clear the screen painting it with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -10.0f);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Rotate the red square by "angle" degrees.
	//glRotatef(angle, 0.0f, 1.0f, 1.0f);
	//glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
	
	// Render a red square
	//        R  G  B
	glColor3f(1, 0, 0);
	//        x1    y1    x2     y2
	
	//Renderizando objetos:
	//---------------------------------------------------------------
	//glRectf(-1.0f, 1.0f, 1.0f, -1.0f);
	//glutWireCube(2.0);
	//glutWireTeapot(2.0);
	//---------------------------------------------------------------
	//Atividade 1: Implementar a função glutWireCube()
	//Essa função vai ser implementada como wireCube(float size)
	//antes da função display
	wireCube(2.0);

	//Atividade 2: Fazer o cubo se mover nos 3 eixos (x, y e z)
	//usando teclas diferentes do teclado, ex: setas direcionais e
	//A e S

	// Start the rendering on a new frame
	glutSwapBuffers();
}

void update(int value)
{
	// Update the angle of rotation
	angle += 3;
	angleX += sumX;
	angleY += sumY;
	angleZ += sumZ;

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}
	if(key == 's'){
		sumY = 3.0;
	}
	if(key == 'a'){
		sumY = -3.0;
	}

}

void keyboard2(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT) {
		sumZ = -3.0;
	} else if (key == GLUT_KEY_LEFT) {
		sumZ = 3.0;
	} else if (key == GLUT_KEY_DOWN) {
		sumX = -3.0;
	} else if (key == GLUT_KEY_UP) {
		sumX = 3.0;
	}

	// Request display update
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard2);
	glutMouseFunc(mouse);

	initView();

	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);

	glutMainLoop();
	return 0;
}