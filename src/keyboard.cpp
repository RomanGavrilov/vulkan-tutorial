#include "keyboard.hpp"
#include <iostream>

void Keyboard::HandleKeyPress(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    std::cout << "HandleKeyPress" << std::endl;
    if (action == GLFW_PRESS)
    {
        mKeys[key] = true;
        std::cout << "Key pressed: " << key << std::endl;
    }
    else if (action == GLFW_RELEASE)
    {
        mKeys[key] = false;
        std::cout << "Key released: " << key << std::endl;
    }
}