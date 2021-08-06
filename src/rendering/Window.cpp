#include "../header/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

void Window::Init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_DECORATED, GL_FALSE);

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Yellow Engine (Now c++ flavored!)", NULL, NULL);
    if(window == NULL) {
        std::cout << "[FATAL] Could not initialize glfw window." << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "[FATAL] Failed to initialize GLAD" << std::endl;
    }

    int window_width, window_height;
    const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwGetWindowSize(window, &window_width, &window_height);
    glfwSetWindowPos(window, (vidmode->width - window_width)/2, (vidmode->height - window_height)/2);
}

void Window::Dispose() {
    glfwTerminate();
}

void Window::Input() {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { glfwSetWindowShouldClose(window, true); }
}

void Window::Update() {
    
}

void Window::Render() {
    glClearColor(0.14f, 0.16f, 0.40, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(window);
}