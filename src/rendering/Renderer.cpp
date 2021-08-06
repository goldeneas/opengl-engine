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

    // Store ShaderProgram ID
    programId = shaderProgram.GetId();

    // Generate VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Vertices VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertCount, vertices, GL_STATIC_DRAW);

    // Attrib pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::Dispose() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(programId);
}

void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programId);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}