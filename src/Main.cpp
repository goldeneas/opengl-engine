#include "header/Window.h"
#include "header/Renderer.h"

#include <iostream>

float vertices[] = {
    // Coordinates        // Colors           // Texture
     0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left 
};

int indices[] = {
    0, 1, 3,
    1, 2, 3
};

int main() {
    Window window;
    Renderer renderer;
    
    window.Init();
    renderer.Init(vertices, indices, sizeof(vertices), sizeof(indices));

    while(!window.ShouldClose()) {
        window.Input();
        window.Update();

        window.Render();
        renderer.Render();
    }

    window.Dispose();
    renderer.Dispose();

    return 0;
}
