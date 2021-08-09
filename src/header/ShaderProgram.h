#pragma once

#include "../header/Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
class ShaderProgram {
    private:
        unsigned int programId;

    public:
        ShaderProgram(Shader vertexShader, Shader fragmentShaderId);
        void Dispose();
        unsigned int GetId() { return programId; };
};