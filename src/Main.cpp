#include "header/Window.h"
#include "header/Renderer.h"

#include <iostream>

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main() {
    Window window;
    Renderer renderer;
    
    window.Init();
    renderer.Init(vertices, sizeof(vertices));

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
