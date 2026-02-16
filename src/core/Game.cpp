#include "core/Game.h"

Game::Game(int width, int height)
    : screenWidth(width),
      screenHeight(height),
      state(GameState::Playing)
{
    renderer = new Renderer2D(screenWidth, screenHeight);

    textureGroundBottom = renderer->LoadTexture("textures/ground_bottom.png");
    textureGroundTop = renderer->LoadTexture("textures/ground_top.png");

    player = new Player({100.0f, 400.0f}, {50.0f, 50.0f}, *renderer);
    entities.push_back(player);
}

Game::~Game()
{
    for (Entity* e : entities)
        delete e;

    delete renderer;
}

void Game::ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    player->ProcessInput(window);
}

void Game::Update(float deltaTime)
{
    for (Entity* e : entities)
        e->Update(deltaTime);
}

void Game::Render()
{

    float tileSize = 50.0f;
    float groundLevel = 300.0f;

    for (float y = 0.0f; y < 300.0f; y += tileSize)
    {
        for (float x = 0.0f; x < 800.0f; x += tileSize)
        {
            if (y >= groundLevel - tileSize){
                renderer->DrawSprite(textureGroundTop, x, y, tileSize, tileSize);
            }
            else{
                renderer->DrawSprite(textureGroundBottom, x, y, tileSize, tileSize);
            }
        }
    }

    for (Entity* e : entities)
        e->Render(*renderer);
}