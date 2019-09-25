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

float x1 = -0.1, y1 = 0.1, x2 = 0.1, y2 = -0.1;
float rotacao = 0.0, translacao=0.0, escala=1.0;
bool ativarRotacao = false, ativarTranslacao = false, ativarEscala = false;
float direcaoTranslacao = 1.0, direcaoRotacao = 1.0, direcaoEscala = 1.0;

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	// Render the X and Y axis to guide ourselves.
	//renderCoordinateAxis();

	glLoadIdentity();

	//Exercício: Desenhar um quadrado que se rotaciona ao clicar no botão '1',
	//que translada ao clicar no botão '2' e que escala ao clicar no botão '3'.
	//A rotação, translação e a escala só irão parar ao clicar novamente nesses
	//botões

	// Render a red square
	glColor3f(1, 0, 0);
	glTranslatef(translacao, 0, 0);
	glScalef(escala, escala, 0);
	glRotatef(rotacao, 0, 0, 1);
	glRectf(x1, y1, x2, y2);

	if(ativarRotacao)
		rotacao += direcaoRotacao*5.f;
	if(ativarTranslacao)
		translacao += direcaoTranslacao*0.01;
	if(ativarEscala)
		escala += direcaoEscala*0.01;

	if(escala >= 5) direcaoEscala = -1.0;
	if(escala <= 0.1) direcaoEscala = 1.0;

	if(translacao >= 1) direcaoTranslacao = -1.0;
	if(translacao <= -1) direcaoTranslacao = 1.0;

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == '1'){
		ativarRotacao = !ativarRotacao;
		if(ativarRotacao)
			direcaoRotacao = direcaoRotacao * (-1.0);
	}
	if (key == '2'){
		ativarTranslacao = !ativarTranslacao;
		if(ativarTranslacao)
			direcaoTranslacao = direcaoTranslacao * (-1.0);
	}
	if (key == '3'){
		ativarEscala = !ativarEscala;
		if(ativarEscala)
			direcaoEscala = direcaoEscala * (-1.0);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}