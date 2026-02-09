#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class Renderer2D
{
public:
    Renderer2D(int screenWidth, int screenHeight);
    ~Renderer2D();

    void DrawRect(float x, float y, float width, float height, glm::vec3 color);

private:
    unsigned int VAO, VBO, EBO;
    unsigned int shaderProgram;
    glm::mat4 projection;

    unsigned int LoadShader(const char* vertexPath, const char* fragmentPath);
};
