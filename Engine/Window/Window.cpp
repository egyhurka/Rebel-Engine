#include "Window.h"

Window::Window(Resulution resulution, std::string title) 
{
	if (!glfwInit())
		throw std::runtime_error("Failed to initialize glfw.");;

	this->width = static_cast<int>(resulution.width);
	this->height = static_cast<int>(resulution.height);
	this->title = title;

	if (!CreateWindow()) 
	{
		glfwTerminate();
		throw std::runtime_error("Failed to create window.");
	}

	glfwMakeContextCurrent(window);
}

WindowData Window::getData()
{
	return WindowData{
		window,
		width,
		height,
		ShouldClose()
	};
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(window);;
}

bool Window::CreateWindow() 
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!window)
		return false;
	return true;
}
