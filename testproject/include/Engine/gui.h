#ifndef GUI_CLASS_H
#define GUI_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

class GUI
{
public:
	void Init(GLFWwindow* window);
	void Update(GLFWwindow* window);
	void Shutdown();
};

#endif