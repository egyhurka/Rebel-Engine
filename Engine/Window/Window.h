#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

struct WindowData
{
	GLFWwindow* windowRef;
	int width, height;
	bool ShouldClose = false;
};

class Window 
{
public:
	Window(int width, int height, std::string title);

	WindowData getData();


private:
	int width, height;
	std::string title;
	GLFWwindow* window;
	bool CreateWindow();
	bool ShouldClose();
};