#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Engine/window.h"
#include "Application/input.h"
#include "logs.h"

void Window::Start(void(*start)())
{
	start();
    Log(info, "Application Started !");
}

void Window::CreateWindow(int width, int height, const char* title, bool vSync, bool legacy)
{
    if (!glfwInit())
    {
        Log(error, "Failed To Initialize GLFW !");
        return;
    }

    if (!legacy)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    else 
    {
       // Allows Usage Of Legacy OpenGL Code // 
       glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
       glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
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
        Log(error, "Failed To Initialize GLFW Window !");
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log(error, "Failed To Initialize GLAD !");
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
		 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    Log(info, "Application Shutdown Successfully !");
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