#pragma once
#include <GLFW/glfw3.h>

class Input
{
public:
    static void Init(GLFWwindow* window);
    static void Update();

    static bool JumpPressed();
    static bool RestartPressed();
    static bool ExitPressed();

private:
    static GLFWwindow* m_Window;

    static bool m_Jump;
    static bool m_Restart;
    static bool m_Exit;
};
