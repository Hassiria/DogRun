#ifndef PLAYER_H
#define PLAYER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "entities/Entity.h"

class Player : public Entity
{
public:
    Player(glm::vec2 pos, glm::vec2 size);

    void ProcessInput(GLFWwindow* window);
    void Update(float deltaTime) override;
    void Render(Renderer2D& renderer) override;

private:
    float velocityY;
    float speedX;
    bool onGround;
};

#endif
