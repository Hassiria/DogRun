#ifndef GAME_H
#define GAME_H

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "entities/Entity.h"
#include "entities/Player.h"
#include "Renderer2D.h"

enum class GameState
{
    Playing,
    GameOver
};

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void ProcessInput(GLFWwindow* window);
    void Update(float deltaTime);
    void Render();

private:
    GameState state;

    int screenWidth;
    int screenHeight;

    Renderer2D* renderer;

    std::vector<Entity*> entities;
    Player* player;

    unsigned int textureGroundBottom;
    unsigned int textureGroundTop;
};

#endif