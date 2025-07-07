#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Engine/engine.h"

void Window::Start(void(*start)())
{
	start();
}

void Window::CreateWindow(int width, int height, const char* title, bool vSync, bool dev)
{
    if (!glfwInit())
    {
        std::cout << "Failed To Initialize GLFW" << std::endl;
        return;
    }

    if (!dev)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#endif

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed To Initialize GLFW Window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed To Load GLAD" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return;
    }

    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);

    if (vSync)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
}

void Window::Update(void(*update)())
{
	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		ResizeWindow(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		update();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Window::Shutdown(void(*shutdown)())
{
	shutdown();
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::SetBackgroundColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Window::ResizeWindow(GLFWwindow* window)
{
	int w = 0, h = 0;
	glfwGetWindowSize(window, &w, &h);
	glViewport(0, 0, w, h);
}

GLFWwindow* Window::GetGLFWwindow() const
{
	return window;
}