#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

#define RES_800x600		{ 800,	600 }
#define RES_1024x768	{ 1024, 768 }
#define RES_1280x1024	{ 1280, 1024 }
#define RES_1366x768	{ 1366, 768 }
#define RES_1920x1080	{ 1920, 1080 }
#define RES_2560x1440	{ 2560, 1440 }

struct Resulution
{
	unsigned int width, height;
};

struct WindowData
{
	GLFWwindow* windowRef;
	int width, height;
	bool ShouldClose = false;
};

class Window
{
public:
	Window(Resulution resulution, std::string title);

	WindowData getData();

private:
	int width, height;
	std::string title;
	GLFWwindow* window;
	bool CreateWindow();
	bool ShouldClose();
};