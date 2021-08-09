#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader {
    private:
        unsigned int shaderId;

    public:
        Shader(const char *shaderPath, int glShaderType);
        unsigned int GetId() { return shaderId; };
};