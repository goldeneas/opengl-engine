#pragma once

class Renderer {
    private:
        const unsigned int STRIDE = 8;

        unsigned int VAO, VBO, EBO;
        unsigned int programId;
        unsigned int vertCount;
        

    public:
        void Init(float vertices[], int indices[], int vertCount, int indCount);
        void Dispose();
        void Render();
};