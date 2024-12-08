#include "Engine.h"

#include <iostream>

const ShaderSourceGroup SHADER_DEFAULT_SOURCE_GROUP = {
	"shader.vert",
	"shader.frag",
	""
};

Engine::Engine(Resulution resulution, std::string title)
	: renderer()
{
	window = new Window(resulution, title.c_str());
	windowRef = window->getData().windowRef;

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error("Failed to initialize glad.");

	glEnable(GL_DEPTH_TEST);

	InitInput(windowRef);

	std::shared_ptr<Shader> SHADER_DEFAULT = std::make_shared<Shader>(SHADER_DEFAULT_SOURCE_GROUP);
	
	Mesh mesh(Mesh::TriangleVert, Mesh::TriangleInd, SHADER_DEFAULT, glm::vec3(1.0f, 0.0f, 0.0f));
	renderer.addToRenderList(&mesh);
}

Engine::~Engine() 
{
	if (window)
		delete window;
}

void Engine::Run() {
	while (!window->getData().ShouldClose)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		renderer.render();

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