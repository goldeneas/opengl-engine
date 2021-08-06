#include "header/Window.h"

#include <iostream>

int main() {
    Window window;
    
    window.Init();

    while(!window.ShouldClose()) {
        window.Input();
        window.Update();
        window.Render();
    }

    window.Dispose();

    return 0;
}
