/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void torre(){
	glPushMatrix();
		glRotatef(10, 1.f, 0.f, 0.f);
		glRotatef(-10, 0.f, 1.f, 0.f);
		glPushMatrix();
			glScalef(1.f, 0.2f, 1.f);
			glutWireCube(0.5);
		glPopMatrix();
		glPushMatrix();
			glScalef(1.f, 2.f, 1.f);
			glTranslatef(0.f, 0.175f, 0.f);
			glutWireCube(0.3);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.15f, 0.7f, 0.15f);
			glutWireCube(0.1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.15f, 0.7f, 0.15f);
			glutWireCube(0.1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.15f, 0.7f, -0.15f);
			glutWireCube(0.1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.15f, 0.7f, -0.15f);
			glutWireCube(0.1);
		glPopMatrix();
	glPopMatrix();
}

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	//Exercício: Desenhar um quadrado que se rotaciona ao clicar no botão '1',
	//que translada ao clicar no botão '2' e que escala ao clicar no botão '3'.
	//A rotação, translação e a escala só irão parar ao clicar novamente nesses
	//botões

	// Render a red square
	glColor3f(1, 0, 0);
	glTranslatef(0.5f, 0.f, 0.1);
	torre();

	//Fazer duas torres aparecerem na tela e se moverem(por conta ou usando o teclado)

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);

	glutMainLoop();
	return 0;
}