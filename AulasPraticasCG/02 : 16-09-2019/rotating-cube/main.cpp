/**
 * A simple OpenGL program that draws a colorful cube
 * that rotates as you move the arrow keys.
 *
 * Author: Mihalis Tsoukalos
 * Date: Wednesday 04 June 2014
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream> 

// The coordinates for the vertices of the cube
float x = 0.0, direcaoX = 1.0;
float escala1 = 1.0;
float escala2 = 1.0, direcaoEscala2 = 1.0;

void display()
{
	// Set Background Color
	glClearColor(1.f, 1.f, 1.f, 1.0f);
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	//Exercício 1: Fazer um programa que desenhe um quadrado. Esse quadrado altera
	//sua escala conforme o usuário pressiona as teclas 2, 3, 4, etc. Tecla 2
	//significa 2x escala em x e y
	// Rotate when user changes rX and rY
	/*
	glScalef(escala1, escala1, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glBegin(GL_LINES);
		glVertex2f(-0.1, -0.1);
		glVertex2f(-0.1, 0.1);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-0.1, 0.1);
		glVertex2f(0.1, 0.1);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.1, 0.1);
		glVertex2f(0.1, -0.1);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0.1, -0.1);
		glVertex2f(-0.1, -0.1);
	glEnd();
	*/

	//Exercício 2: Desenhar um quadrado na tela, que se move da direita para
	//a esquerda (e vice-verso), mas ao longo do movimento, o quadrado
	//aumenta e diminui a escala
	/*
	glScalef(escala2, escala2, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glBegin(GL_LINES);
		glVertex3f(-0.1 + x, 0.1, 0.f);
		glVertex3f(0.1 + x, 0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.1 + x, 0.1, 0.f);
		glVertex3f(0.1 + x, -0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.1 + x, -0.1, 0.f);
		glVertex3f(-0.1 + x, -0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.1 + x, -0.1, 0.f);
		glVertex3f(-0.1 + x, 0.1, 0.f);
	glEnd();
	escala2 += direcaoEscala2*0.01;
	if(escala2 >= 3) direcaoEscala2 = -1.0;
	if(escala2 <= 0.5) direcaoEscala2 = 1.0;
	x += direcaoX * 0.01;
	if(x * escala2 >= 1.0) direcaoX = -1.0;
	if(x * escala2 <= -1.0) direcaoX = 1.0;
	*/

	//Exercício 3: Desenhar dois quadrados que trocam sua escala em ordem inversa
	
	glLoadIdentity();
	glScalef(escala2, escala2, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glBegin(GL_LINES);
		glVertex3f(-0.3, 0.1, 0.f);
		glVertex3f(-0.1, 0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.1, 0.1, 0.f);
		glVertex3f(-0.1, -0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.1, -0.1, 0.f);
		glVertex3f(-0.3, -0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.3, -0.1, 0.f);
		glVertex3f(-0.3, 0.1, 0.f);
	glEnd();
	glLoadIdentity();
	glScalef(3.5-escala2, 3.5-escala2, 0.f);
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_LINES);
		glVertex3f(0.1, 0.1, 0.f);
		glVertex3f(0.3, 0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.3, 0.1, 0.f);
		glVertex3f(0.3, -0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.3, -0.1, 0.f);
		glVertex3f(0.1, -0.1, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.1, -0.1, 0.f);
		glVertex3f(0.1, 0.1, 0.f);
	glEnd();
	escala2 += direcaoEscala2*0.01;
	if(escala2 >= 3) direcaoEscala2 = -1.0;
	if(escala2 <= 0.5) direcaoEscala2 = 1.0;
	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == '1')
		escala1 = 1.f;
	else if (key == '2')
		escala1 = 2.f;
	else if (key == '3')
		escala1 = 3.f;
	else if (key == '4')
		escala1 = 4.f;
	else if (key == '5')
		escala1 = 5.f;
	else if (key == '6')
		escala1 = 6.f;
	else if (key == '7')
		escala1 = 7.f;
	else if (key == '8')
		escala1 = 8.f;
	else if (key == '9')
		escala1 = 9.f;
	else if (key == '0')
		escala1 = 0.f;

	// Request display update
	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	// Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);

	// Create window
	glutCreateWindow("OpenGL Cube");

	// Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	// Pass control to GLUT for events
	glutMainLoop();

	return 0;
}