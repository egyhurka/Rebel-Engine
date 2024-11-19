#include "Engine.h"

#include <iostream>

Engine::Engine(Resulution resulution, std::string title)
{
	window = new Window(resulution, title.c_str());
	windowRef = window->getData().windowRef;

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error("Failed to initialize glad.");

	InitInput(windowRef);
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

		glfwSwapBuffers(windowRef);
		ProcessInput();
	}
	glfwDestroyWindow(windowRef);
	glfwTerminate();
}

void Engine::ProcessInput()
{
	glfwPollEvents();

	if (IsKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(windowRef, true);
}