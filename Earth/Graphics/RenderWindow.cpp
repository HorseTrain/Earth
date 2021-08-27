#include "..\..\External\glew\glew.h"
#include "..\..\External\glfw\glfw3.h"
#include "assert.h"

#include "RenderWindow.h"

bool RenderWindow::WindowOpen = false;

RenderWindow::RenderWindow()
{
	assert(!WindowOpen);

	WindowOpen = true;

	glfwInit();

	glfwWindow = glfwCreateWindow(1000,1000,"Planet",NULL, NULL);

	glfwMakeContextCurrent(glfwWindow);

	glewInit();
}

RenderWindow::~RenderWindow()
{
	glfwDestroyWindow(glfwWindow);
}

void RenderWindow::UpdateWindow()
{
	glfwMakeContextCurrent(glfwWindow);

	glfwPollEvents();

	glfwSwapBuffers(glfwWindow);

	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0,0,0,0);
}