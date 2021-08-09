#pragma once

class Texture {
    private:
        static char[] DEFAULT_TEXTURE_PATH;

        unsigned int textureId;

        void LoadImage(const char *imagePath);

    public:
        Texture();
        Texture(const char *imagePath);

        void Dispose();
        unsigned int GetId() { return textureId; };
};