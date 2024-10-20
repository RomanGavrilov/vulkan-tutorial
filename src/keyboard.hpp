#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>

class Keyboard
{
public:
    void HandleKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
    std::unordered_map<int, bool> mKeys;
};