#version 330 core
layout (location = 0) in vec3 vertexPos;
layout (location = 1) in vec3 _vertexColor;
layout (location = 2) in vec2 _texturePos;

out vec3 vertexColor;
out vec2 texturePos;

void main()
{
    vertexColor = _vertexColor;
    texturePos = _texturePos;
    gl_Position = vec4(vertexPos, 1.0);
}