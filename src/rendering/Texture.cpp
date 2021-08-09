#include "../header/Texture.h"
#include "../header/stb_image.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Texture::Texture() {
    LoadImage("../../resources/textures/debug.png"); // TODO: Make this variable constant
}

Texture::Texture(const char *imagePath) {
    LoadImage(imagePath);
}

void Texture::Dispose() {
    glDeleteTextures(1, &textureId);
}

void Texture::LoadImage(const char *imagePath) {
    int width, height, channelCount;
    unsigned char *data = stbi_load(imagePath, &width, &height, &channelCount, 0);

    if(!data) {
        std::cout << "Could not read texture data." << std::endl;
        return;
    }

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}