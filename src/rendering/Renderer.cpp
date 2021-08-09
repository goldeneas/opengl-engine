#include "../header/Renderer.h"
#include "../header/Texture.h"
#include "../header/Shader.h"
#include "../header/ShaderProgram.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Renderer::Init(float vertices[], int indices[], int vertCount, int indCount) {
    Texture texture("../resources/textures/grid.png");

    Shader vertexShader("../resources/shaders/vertex.vs", GL_VERTEX_SHADER);
    Shader fragmentShader("../resources/shaders/fragment.fs", GL_FRAGMENT_SHADER);
    ShaderProgram shaderProgram(vertexShader, fragmentShader);

    // Store ShaderProgram ID
    programId = shaderProgram.GetId();

    // Generate VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertCount, vertices, GL_STATIC_DRAW);

    // Position Attrib Pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, STRIDE * sizeof(float), (void*)(0));
    glEnableVertexAttribArray(0);

    // Color Attrib Pointer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, STRIDE * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Texture Attrib Pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, STRIDE * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indCount, indices, GL_STATIC_DRAW);

    // DEBUG: Bind texture now because we're not storing its id to bind it before very render call
    glBindTexture(GL_TEXTURE_2D, texture.GetId());

    // Unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    this->vertCount = vertCount;
}

void Renderer::Dispose() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    // glDeleteTextures(1, texture);
    glDeleteProgram(programId);
}

void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programId);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, vertCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}