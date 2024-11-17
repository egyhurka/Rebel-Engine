#include "Input.h"

#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        std::cout << "Key " << key << " pressed!" << std::endl;
    }
    if (action == GLFW_RELEASE) {
        std::cout << "Key " << key << " released!" << std::endl;
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        std::cout << "Mouse button " << button << " pressed!" << std::endl;
    }
    if (action == GLFW_RELEASE) {
        std::cout << "Mouse button " << button << " released!" << std::endl;
    }
}

void InitInput(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
}

bool IsKeyPressed(int key) {
    return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS;
}

bool IsMouseButtonPressed(int button) {
    return glfwGetMouseButton(glfwGetCurrentContext(), button) == GLFW_PRESS;
}

void GetMousePosition(double& xpos, double& ypos) {
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
}
