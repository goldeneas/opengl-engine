#pragma once

#include "Texture.h"

class Mesh {
    private:
        unsigned int VAO, VBO, EBO;
        Texture texture;

    public:
        Mesh(float vertices[], int indices[], int vertCount, int indCount);
};