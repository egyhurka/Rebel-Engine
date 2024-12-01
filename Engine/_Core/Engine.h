#pragma once

#include <glad/glad.h>

#include "../Window/Window.h"
#include "../Input/Input.h"
#include "../Shader/Shader.h"
#include "../Renderer/Renderer.h"

#include <memory>

class Engine 
{
public:
	Engine(Resulution resulution, std::string title);
	~Engine();

	void Run();
private:
	Window* window;
	GLFWwindow* windowRef;
	Renderer renderer;
	void ProcessInput();
};