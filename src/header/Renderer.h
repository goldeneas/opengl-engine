#pragma once

class Renderer {
    private:
        unsigned int VAO;
        unsigned int VBO;
        unsigned int programId;

    public:
        void Init(float vertices[], int vertCount);
        void Dispose();
        void Render();
};