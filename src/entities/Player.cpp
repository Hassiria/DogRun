#include "entities/Player.h"
#include "Renderer2D.h"

Player::Player(glm::vec2 pos, glm::vec2 size)
    : Entity(pos, size),
      velocityY(0.0f),
      speedX(300.0f),
      onGround(true)
{
}

void Player::ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        position.x -= speedX * 0.016f;
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS ||
        glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        position.x += speedX * 0.016f;
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && onGround)
    {
        velocityY = 400.0f;
        onGround = false;
    }
}


void Player::Update(float deltaTime)
{
    velocityY -= 800.0f * deltaTime;
    position.y += velocityY * deltaTime;

    if (position.y <= 100.0f)
    {
        position.y = 100.0f;
        velocityY = 0.0f;
        onGround = true;
    }
}

void Player::Render(Renderer2D& renderer)
{
    renderer.DrawRect(position.x, position.y, size.x, size.y, {1.0f, 1.0f, 1.0f});
}
