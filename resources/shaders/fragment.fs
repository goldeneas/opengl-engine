#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 texturePos;

uniform sampler2D textureSampler;

void main()
{
    FragColor = texture(textureSampler, texturePos) * vec4(vertexColor, 1.0f);
} 