#pragma once

struct GLFWwindow;

class RenderWindow
{
public:

	GLFWwindow* glfwWindow;
	static bool WindowOpen;

	RenderWindow();
	~RenderWindow();

	void UpdateWindow();
};