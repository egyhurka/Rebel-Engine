#include "Engine.h"

#include <iostream>

Engine::Engine(unsigned int width, unsigned int height, std::string title)
{
	window = new Window(static_cast<int>(width), static_cast<int>(height), title.c_str());
}

Engine::~Engine() 
{
	delete window;
}

void Engine::Run() {
	while (!window->getData().ShouldClose)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f, 0.4f, 0.5f, 1.0f);

		glfwSwapBuffers(window->getData().windowRef);
		glfwPollEvents();
	}
	glfwTerminate();
}
