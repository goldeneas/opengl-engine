#include "../header/Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

Shader::Shader(const char *shaderSource, int shaderType) {
    shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderSource, NULL);
    glCompileShader(shaderId);

    int success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        std::cout << "[ERROR] Could not compile shader." << std::endl;
    }
}