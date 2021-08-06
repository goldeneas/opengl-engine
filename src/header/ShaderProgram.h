#pragma once

class ShaderProgram {
    private:
        unsigned int programId;

    public:
        ShaderProgram(unsigned int vertexShaderId, unsigned int fragmentShaderId);
        unsigned int GetId() { return programId; };
};