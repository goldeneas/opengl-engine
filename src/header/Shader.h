#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader {
    private:
        unsigned int shaderId;
        const char *shaderSource;

    public:
        Shader(const char *shaderSource, int shaderType);
        unsigned int GetId() { return shaderId; };
};