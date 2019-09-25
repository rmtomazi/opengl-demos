/**
 * Basic usege of OpenGL and GLFW. 
 */

#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 500
#define HEIGHT 500

float x = 0.0, direcao = 1.0;

int main() {
	GLFWwindow* window;
	int width, height;

	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}
	
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world, GLFW!", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		//Exercicio 1: Fazer um programa que desenhe uma linha vermelha na diagonal
		/*
		glBegin(GL_LINES);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(-1.f, -1.f, 0.f);
			glVertex3f(1.f, 1.f, 0.f);
		glEnd();
		*/
		
		//Exercicio 2: Fazer um programa que desenha duas linhas paralelas, uma azul
		//e uma vermelha
		/*
		glBegin(GL_LINES);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(-0.5f, -1.f, 0.f);
			glVertex3f(-0.5f, 1.f, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(0.5f, -1.f, 0.f);
			glVertex3f(0.5f, 1.f, 0.f);
		glEnd();
		*/

		//Exercicio 3: Desenhar um quadrado azul
		/*
		glColor3f(0.f, 0.f, 1.f);
		glBegin(GL_LINES);
			glVertex3f(-0.5f, 0.5f, 0.f);
			glVertex3f(0.5f, 0.5f, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(0.5f, 0.5f, 0.f);
			glVertex3f(0.5f, -0.5f, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(0.5f, -0.5f, 0.f);
			glVertex3f(-0.5f, -0.5f, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(-0.5f, -0.5f, 0.f);
			glVertex3f(-0.5f, 0.5f, 0.f);
		glEnd();*/

		//Exercicio 4: Desenhar um quadrado azul que se movimenta da esquerda para
		//a direita
		/*
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
		if(x >= 0.8f) direcao = -1.0;
		if(x <= -0.8f) direcao = 1.0;
		*/

		//Exercicio 5: O mesmo que o 4, mas com 2 quadrados de cores diferentes e em
		//direções opostas

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
		glColor3f(1.f, 0.f, 0.f);
		glBegin(GL_LINES);
			glVertex3f(-0.2 - x, 0.2f, 0.f);
			glVertex3f(0.2 - x, 0.2f, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(0.2 - x, 0.2f, 0.f);
			glVertex3f(0.2 - x, -0.2f, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(0.2 - x, -0.2f, 0.f);
			glVertex3f(-0.2 - x, -0.2f, 0.f);
		glEnd();
		glBegin(GL_LINES);
			glVertex3f(-0.2 - x, -0.2f, 0.f);
			glVertex3f(-0.2 - x, 0.2f, 0.f);
		glEnd();
		x += direcao * 0.005;
		if(x >= 0.8f) direcao = -1.0;
		if(x <= -0.8f) direcao = 1.0;
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
