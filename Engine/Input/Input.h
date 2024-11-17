#pragma once

#include <GLFW/glfw3.h>

void InitInput(GLFWwindow* window);

bool IsKeyPressed(int key);
bool IsMouseButtonPressed(int button);
void GetMousePosition(double& xpos, double& ypos);