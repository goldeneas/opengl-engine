#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
    private:
        GLFWwindow* window;
    public:
        void Init();
        void Dispose();
        void Input();
        void Update();
        void Render();

        bool ShouldClose();
};