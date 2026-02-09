#include "Input.h"

GLFWwindow* Input::m_Window = nullptr;

bool Input::m_Jump = false;
bool Input::m_Restart = false;
bool Input::m_Exit = false;

void Input::Init(GLFWwindow* window)
{
    m_Window = window;
}

void Input::Update()
{
    m_Jump    = glfwGetKey(m_Window, GLFW_KEY_SPACE) == GLFW_PRESS;
    m_Restart = glfwGetKey(m_Window, GLFW_KEY_R)     == GLFW_PRESS;
    m_Exit    = glfwGetKey(m_Window, GLFW_KEY_ESCAPE)== GLFW_PRESS;
}

bool Input::JumpPressed()
{
    return m_Jump;
}

bool Input::RestartPressed()
{
    return m_Restart;
}

bool Input::ExitPressed()
{
    return m_Exit;
}
