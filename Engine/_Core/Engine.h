#pragma once

#include "../Window/Window.h"

class Engine 
{
public:
	Engine(unsigned int width, unsigned int height, std::string title);
	~Engine();

	void Run();
private:
	Window* window;
};