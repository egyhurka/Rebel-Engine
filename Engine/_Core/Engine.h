#pragma once

#include <glad/glad.h>

#include "../Window/Window.h"
#include "../Input/Input.h"

class Engine 
{
public:
	Engine(Resulution resulution, std::string title);
	~Engine();

	void Run();
private:
	Window* window;
	GLFWwindow* windowRef;
	void ProcessInput();
};