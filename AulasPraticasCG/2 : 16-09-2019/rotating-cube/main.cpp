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
float scaleX = 1.f;
float scaleY = 1.f;

float x = 0.0, direcao = 1.0;

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
	/*
	// Rotate when user changes rX and rY
	glScalef(scaleX, scaleY, 0.f);
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
	glColor3f(0.f, 0.f, 1.f);
	glBegin(GL_LINES);
		glVertex3f(-0.2 + x, 0.2f, 0.f);
		glVertex3f(0.2 + x, 0.2f, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.2 + x, 0.2f, 0.f);
		glVertex3f(0.2 + x, -0.2f, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0.2 + x, -0.2f, 0.f);
		glVertex3f(-0.2 + x, -0.2f, 0.f);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.2 + x, -0.2f, 0.f);
		glVertex3f(-0.2 + x, 0.2f, 0.f);
	glEnd();
	x += direcao * 0.005;
	if(x >= 0.8f || x <= -0.8f) direcao *= (-1.0);

	//Exercício 3: Desenhar dois quadrados que trocam sua escala em ordem inversa


	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == '1'){
		scaleX = 1.f;
		scaleY = 1.f;
	}
	else if (key == '2'){
		scaleX = 2.f;
		scaleY = 2.f;
	}
	else if (key == '3'){
		scaleX = 3.f;
		scaleY = 3.f;
	}
	else if (key == '4'){
		scaleX = 4.f;
		scaleY = 4.f;
	}
	else if (key == '5'){
		scaleX = 5.f;
		scaleY = 5.f;
	}
	else if (key == '6'){
		scaleX = 6.f;
		scaleY = 6.f;
	}
	else if (key == '7'){
		scaleX = 7.f;
		scaleY = 7.f;
	}
	else if (key == '8'){
		scaleX = 8.f;
		scaleY = 8.f;
	}
	else if (key == '9'){
		scaleX = 9.f;
		scaleY = 9.f;
	}
	else if (key == '0'){
		scaleX = 0.f;
		scaleY = 0.f;
	}

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
	glutKeyboardFunc(keyboard);

	// Pass control to GLUT for events
	glutMainLoop();

	return 0;
}