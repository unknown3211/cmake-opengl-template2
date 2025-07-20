#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
	int width;
	int height;
	char* title;
	bool vSync;
	GLFWwindow* GetGLFWwindow() const;
	void Start(void(*start)());
	void CreateWindow(int width, int height, const char* title, bool vSync, bool legacy);
	void Update(void(*update)());
	void Shutdown(void(*shutdown)());
	void SetBackgroundColor(float r, float g, float b, float a);
	void ResizeWindow(GLFWwindow* window);

private:
	GLFWwindow* window = nullptr;
};

#endif