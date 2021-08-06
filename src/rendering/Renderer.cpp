#include "../header/Renderer.h"
#include "../header/ShaderProgram.h"
#include "../header/Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

void Renderer::Init(float vertices[], int vertCount) {

    Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER);
    Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    ShaderProgram shaderProgram(vertexShader.GetId(), fragmentShader.GetId());

    glUseProgram(shaderProgram.GetId());

    glDeleteShader(vertexShader.GetId());
    glDeleteShader(fragmentShader.GetId());

    // Vertices VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertCount, vertices, GL_STATIC_DRAW);
}

void Renderer::Dispose() {

}

void Renderer::Render() {

}