#pragma once

class Renderer {
    private:
        unsigned int VBO;

    public:
        void Init(float vertices[], int vertCount);
        void Dispose();
        void Render();
};