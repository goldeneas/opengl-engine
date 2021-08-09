#include "../header/Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>
#include <iostream>

// std::ifstream::open starts reading from the path the exe file is located in when executed
Shader::Shader(const char *shaderPath, int glShaderType) {

    std::string _shaderSource;
    std::ifstream shaderFile;

    shaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try {
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;

        shaderStream << shaderFile.rdbuf();
        shaderFile.close();

        _shaderSource = shaderStream.str();
    } catch(std::ifstream::failure e) {
        std::cout << "Could not read shader source." << std::endl;
    }

    const char *shaderSource = _shaderSource.c_str();

    shaderId = glCreateShader(glShaderType);
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