#include "../header/ShaderProgram.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

ShaderProgram::ShaderProgram(Shader vertexShader, Shader fragmentShader) {
    programId = glCreateProgram();

    unsigned int vertexShaderId = vertexShader.GetId();
    unsigned int fragmentShaderId = fragmentShader.GetId();

    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);

    glLinkProgram(programId);

    int success;
    char infoLog[512];
    glGetProgramiv(programId, GL_LINK_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(programId, 512, NULL, infoLog);
        std::cout << "[ERROR] Could not link shaders to program." << std::endl;
    }

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
}

void ShaderProgram::Dispose() {
    glDeleteProgram(programId);
}